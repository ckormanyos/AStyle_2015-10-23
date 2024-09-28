/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *   astyle_main.h
 *
 *   Copyright (C) 2006-2011 by Jim Pattee <jimp03@email.com>
 *   Copyright (C) 1998-2002 by Tal Davidson
 *   <http://www.gnu.org/licenses/lgpl-3.0.html>
 *
 *   This file is a part of Artistic Style - an indentation and
 *   reformatting tool for C, C++, C# and Java source files.
 *   <http://astyle.sourceforge.net>
 *
 *   Artistic Style is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU Lesser General Public License as published
 *   by the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   Artistic Style is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU Lesser General Public License for more details.
 *
 *   You should have received a copy of the GNU Lesser General Public License
 *   along with Artistic Style.  If not, see <http://www.gnu.org/licenses/>.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */

#ifndef ASTYLE_MAIN_H
#define ASTYLE_MAIN_H

//----------------------------------------------------------------------------
// headers
//----------------------------------------------------------------------------

#include <sstream>
#include <ctime>
#include "astyle.h"

#if defined(_MSC_VER) || defined(__DMC__)
#include <sys/utime.h>
#include <sys/stat.h>
#else
#include <utime.h>
#include <sys/stat.h>
#endif                         // end compiler checks

#ifdef ASTYLE_JNI
#include <jni.h>
#ifndef ASTYLE_LIB    // ASTYLE_LIB must be defined for ASTYLE_JNI
#define ASTYLE_LIB
#endif
#endif  //  ASTYLE_JNI

// for console build only
#ifndef ASTYLE_LIB
#include "ASLocalizer.h"
#define _(a) localizer.settext(a)
#endif

// for G++ implementation of std::string.compare:
#if defined(__GNUC__) && __GNUC__ < 3
#error - Use GNU C compiler release 3 or higher
#endif

// for namespace problem in version 5.0
#if defined(_MSC_VER) && _MSC_VER < 1200        // check for V6.0
#error - Use Microsoft compiler version 6 or higher
#endif

// for mingw BOM, UTF-16, and Unicode functions
#if defined(__MINGW32__)
#if (__MINGW32_MAJOR_VERSION > 3)  || ((__MINGW32_MAJOR_VERSION == 3) && (__MINGW32_MINOR_VERSION < 16))
#error - Use MinGW compiler version 4 or higher
#endif
#endif


namespace astyle
{

//----------------------------------------------------------------------------
// ASStreamIterator class
// typename will be istringstream for GUI and istream otherwise
// ASSourceIterator is an abstract class defined in astyle.h
//----------------------------------------------------------------------------

  template<typename T>
  class ASStreamIterator : public ASSourceIterator
  {
  public:
    bool checkForEmptyLine;

    // function declarations
    ASStreamIterator(T* in);
    virtual ~ASStreamIterator();
    bool getLineEndChange(std::int32_t lineEndFormat) const;
    std::string nextLine(bool emptyLineWasDeleted);
    std::string peekNextLine();
    void peekReset();
    void saveLastInputLine();

  private:
    ASStreamIterator(const ASStreamIterator& copy);       // copy constructor not to be imlpemented
    ASStreamIterator& operator=(ASStreamIterator&);       // assignment operator not to be implemented
    T* inStream;           // pointer to the input stream
    std::string buffer;         // current input line
    std::string prevBuffer;     // previous input line
    std::int32_t eolWindows;        // number of Windows line endings, CRLF
    std::int32_t eolLinux;          // number of Linux line endings, LF
    std::int32_t eolMacOld;         // number of old Mac line endings. CR
    char outputEOL[4];     // next output end of line char
    std::streamoff peekStart;   // starting position for peekNextLine
    bool prevLineDeleted;  // the previous input line was deleted

  public:  // inline functions
    bool compareToInputBuffer(const std::string& nextLine_) const
    {
      return (nextLine_ == prevBuffer);
    }
    const char* getOutputEOL() const
    {
      return outputEOL;
    }
    bool hasMoreLines() const
    {
      return !inStream->eof();
    }
  };

//----------------------------------------------------------------------------
// ASOptions class for options processing
// used by both console and library builds
//----------------------------------------------------------------------------

  class ASOptions
  {
  public:
    ASOptions(ASFormatter& formatterArg) : formatter(formatterArg) {}
    std::string getOptionErrors();
    void importOptions(std::istream& in, std::vector<std::string> &optionsVector);
    bool parseOptions(std::vector<std::string> &optionsVector, const std::string& errorInfo);

  private:
    // variables
    ASFormatter& formatter;      // reference to the ASFormatter object
    std::stringstream optionErrors;    // option error messages

    // functions
    ASOptions& operator=(ASOptions&);          // not to be implemented
    std::string getParam(const std::string& arg, const char* op);
    std::string getParam(const std::string& arg, const char* op1, const char* op2);
    bool isOption(const std::string arg, const char* op);
    bool isOption(const std::string& arg, const char* op1, const char* op2);
    void isOptionError(const std::string& arg, const std::string& errorInfo);
    bool isParamOption(const std::string& arg, const char* option);
    bool isParamOption(const std::string& arg, const char* option1, const char* option2);
    void parseOption(const std::string& arg, const std::string& errorInfo);
  };

#ifndef  ASTYLE_LIB

//----------------------------------------------------------------------------
// ASConsole class for console build
//----------------------------------------------------------------------------

  class ASConsole
  {
  private:  // variables
    ASFormatter& formatter;        // reference to the ASFormatter object
    ASLocalizer localizer;        // ASLocalizer object
    // command line options
    bool isRecursive;                   // recursive option
    std::string origSuffix;                  // suffix= option
    bool noBackup;                      // suffix=none option
    bool preserveDate;                  // preserve-date option
    bool isVerbose;                     // verbose option
    bool isQuiet;                       // quiet option
    bool isFormattedOnly;               // formatted lines only option
    bool ignoreExcludeErrors;           // don't abort on unmatched excludes
    bool ignoreExcludeErrorsDisplay;    // don't display unmatched excludes
    bool optionsFileRequired;           // options= option
    bool useAscii;                      // ascii option
    // other variables
    bool hasWildcard;                   // file name includes a wildcard
    std::size_t mainDirectoryLength;         // directory length to be excluded in displays
    bool filesAreIdentical;        // input and output files are identical
    bool lineEndsMixed;          // output has mixed line ends
    std::int32_t  linesOut;                      // number of output lines
    std::int32_t  filesFormatted;                // number of files formatted
    std::int32_t  filesUnchanged;                // number of files unchanged
    char outputEOL[4];          // current line end
    char prevEOL[4];          // previous line end

    std::string optionsFileName;             // file path and name of the options file to use
    std::string targetDirectory;             // path to the directory being processed
    std::string targetFilename;              // file name being processed

    std::vector<std::string> excludeVector;       // exclude from wildcard hits
    std::vector<bool>   excludeHitsVector;   // exclude flags for eror reporting
    std::vector<std::string> fileNameVector;      // file paths and names from the command line
    std::vector<std::string> optionsVector;       // options from the command line
    std::vector<std::string> fileOptionsVector;   // options from the options file
    std::vector<std::string> fileName;            // files to be processed including path

  public:
    ASConsole(ASFormatter& formatterArg) : formatter(formatterArg)
    {
      // command line options
      isRecursive = false;
      origSuffix = ".orig";
      noBackup = false;
      preserveDate = false;
      isVerbose = false;
      isQuiet = false;
      isFormattedOnly = false;
      ignoreExcludeErrors = false;
      ignoreExcludeErrorsDisplay = false;
      optionsFileRequired = false;
      useAscii = false;
      // other variables
      hasWildcard = false;
      filesAreIdentical = true;
      lineEndsMixed = false;
      outputEOL[0] = '\0';
      prevEOL[0] = '\0';
      mainDirectoryLength = 0;
      filesFormatted = 0;
      filesUnchanged = 0;
      linesOut = 0;
    }

    // functions
    void convertLineEnds(std::ostringstream& out, std::int32_t lineEnd);
    FileEncoding detectEncoding(const char* data, std::size_t dataSize) const;
    void error() const;
    void error(const char* why, const char* what) const;
    void formatCinToCout() const;
    std::vector<std::string> getArgvOptions(std::int32_t argc, char** argv) const;
    bool fileNameVectorIsEmpty();
    std::int32_t  getFilesFormatted();
    std::int32_t  getFilesUnchanged();
    bool getIgnoreExcludeErrors();
    bool getIgnoreExcludeErrorsDisplay();
    bool getIsFormattedOnly();
    bool getIsQuiet();
    bool getIsRecursive();
    bool getIsVerbose();
    bool getLineEndsMixed();
    bool getNoBackup();
    std::string getLanguageID() const;
    std::string getNumberFormat(std::int32_t num, std::size_t = 0) const ;
    std::string getNumberFormat(std::int32_t num, const char* groupingArg, const char* separator) const;
    std::string getOptionsFileName();
    bool getOptionsFileRequired();
    std::string getOrigSuffix();
    bool getPreserveDate();
    void processFiles();
    void processOptions(std::vector<std::string>& argvOptions);
    void setIgnoreExcludeErrors(bool state);
    void setIgnoreExcludeErrorsAndDisplay(bool state);
    void setIsFormattedOnly(bool state);
    void setIsQuiet(bool state);
    void setIsRecursive(bool state);
    void setIsVerbose(bool state);
    void setNoBackup(bool state);
    void setOptionsFileName(std::string name);
    void setOptionsFileRequired(bool state);
    void setOrigSuffix(std::string suffix);
    void setPreserveDate(bool state);
    void setProgramLocale();
    void standardizePath(std::string& path, bool removeBeginningSeparator = false) const;
    bool stringEndsWith(const std::string& str, const std::string& suffix) const;
    void updateExcludeVector(std::string suffixParam);
    std::size_t Utf8Length(const char* data, std::size_t len, FileEncoding encoding) const;
    std::size_t Utf8ToUtf16(char* utf8In, std::size_t inLen, FileEncoding encoding, char* utf16Out) const;
    std::size_t Utf16Length(const char* data, std::size_t len) const;
    std::size_t Utf16ToUtf8(char* utf16In, std::size_t inLen, FileEncoding encoding, bool firstBlock, char* utf8Out) const;
    void verifyCinPeek() const;

    // for unit testing
    std::vector<std::string> getExcludeVector();
    std::vector<bool>        getExcludeHitsVector();
    std::vector<std::string> getFileNameVector();
    std::vector<std::string> getOptionsVector();
    std::vector<std::string> getFileOptionsVector();
    std::vector<std::string> getFileName();

  private:
    ASConsole& operator=(ASConsole&);          // not to be implemented
    void correctMixedLineEnds(std::ostringstream& out);
    void formatFile(const std::string& fileName_);
    std::string getCurrentDirectory(const std::string& fileName_) const;
    void getFileNames(const std::string& directory, const std::string& wildcard);
    void getFilePaths(std::string& filePath);
    std::string getParam(const std::string& arg, const char* op);
    void initializeOutputEOL(LineEndFormat lineEndFormat);
    bool isOption(const std::string& arg, const char* op);
    bool isOption(const std::string& arg, const char* op1, const char* op2);
    bool isParamOption(const std::string& arg, const char* option);
    bool isPathExclued(const std::string& subPath);
    void printHelp() const;
    void printMsg(const char* msg, const std::string& data) const;
    void printSeparatingLine() const;
    void printVerboseHeader() const;
    void printVerboseStats(clock_t startTime) const;
    FileEncoding readFile(const std::string& fileName, std::stringstream& in) const;
    void removeFile(const char* fileName_, const char* errMsg) const;
    void renameFile(const char* oldFileName, const char* newFileName, const char* errMsg) const;
    void setOutputEOL(LineEndFormat lineEndFormat, const char* currentEOL);
    void sleep(std::int32_t seconds) const;
    std::int32_t  swap8to16bit(std::int32_t value) const;
    std::int32_t  swap16bit(std::int32_t value) const;
    std::int32_t  waitForRemove(const char* oldFileName) const;
    std::int32_t  wildcmp(const char* wild, const char* data) const;
    void writeFile(const std::string& fileName_, FileEncoding encoding, std::ostringstream& out) const;
#ifdef _WIN32
    void displayLastError();
#endif
  };
#endif  // ASTYLE_LIB

}   // end of namespace astyle

//----------------------------------------------------------------------------
// declarations for java native interface (JNI) build
// global because they are called externally and are NOT part of the namespace
//----------------------------------------------------------------------------

#ifdef ASTYLE_JNI
void  STDCALL javaErrorHandler(std::int32_t errorNumber, const char* errorMessage);
char* STDCALL javaMemoryAlloc(unsigned long memoryNeeded);
// the following function names are constructed from method names in the calling java program
extern "C"  EXPORT
jstring STDCALL Java_AStyleInterface_AStyleGetVersion(JNIEnv* env, jclass);
extern "C"  EXPORT
jstring STDCALL Java_AStyleInterface_AStyleMain
(JNIEnv* env, jobject obj, jstring textInJava, jstring optionsJava);
#endif //  ASTYLE_JNI


#endif // closes ASTYLE_MAIN_H
