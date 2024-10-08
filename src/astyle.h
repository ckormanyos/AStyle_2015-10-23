/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *   astyle.h
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

#ifndef ASTYLE_H
#define ASTYLE_H

#ifdef __VMS
#define __USE_STD_IOSTREAM 1
#include <assert>
#else
#include <cassert>
#endif

#include <string.h>         // need both std::string and std::string.h for GCC
#include <string>
#include <vector>
#include <cctype>

#ifdef _WIN32
#define STDCALL __stdcall
#define EXPORT  __declspec(dllexport)
#else
#define STDCALL
#define EXPORT
#endif

#ifdef _MSC_VER
#pragma warning(disable: 4996)  // secure version deprecation warnings
#pragma warning(disable: 4267)  // 64 bit signed/unsigned loss of data
#endif

#ifdef __BORLANDC__
#pragma warn -aus  // variable is assigned a value that is never used in function.
#endif

#ifdef __INTEL_COMPILER
#pragma warning(disable:  383)  // value copied to temporary, reference to temporary used
// #pragma warning(disable:  444)  // destructor for base class is not virtual
#pragma warning(disable:  981)  // operands are evaluated in unspecified order
#endif

namespace astyle
{

  enum FileType      { C_TYPE = 0, JAVA_TYPE = 1, SHARP_TYPE = 2 };

  /* The enums below are not recognized by 'vectors' in Microsoft Visual C++
     V5 when they are part of a namespace!!!  Use Visual C++ V6 or higher.
  */
  enum FormatStyle   { STYLE_NONE,
                       STYLE_ALLMAN,
                       STYLE_JAVA,
                       STYLE_KR,
                       STYLE_STROUSTRUP,
                       STYLE_WHITESMITH,
                       STYLE_BANNER,
                       STYLE_GNU,
                       STYLE_LINUX,
                       STYLE_HORSTMANN,
                       STYLE_1TBS,
                       STYLE_PICO,
                       STYLE_LISP
                     };

  enum BracketMode   { NONE_MODE,
                       ATTACH_MODE,
                       BREAK_MODE,
                       LINUX_MODE,
                       STROUSTRUP_MODE,
                       RUN_IN_MODE,
                       BDAC_MODE = LINUX_MODE
                     };

  enum BracketType   { NULL_TYPE = 0,
                       NAMESPACE_TYPE = 1,        // also a DEFINITION_TYPE
                       CLASS_TYPE = 2,            // also a DEFINITION_TYPE
                       STRUCT_TYPE = 4,           // also a DEFINITION_TYPE
                       INTERFACE_TYPE = 8,        // also a DEFINITION_TYPE
                       DEFINITION_TYPE = 16,
                       COMMAND_TYPE = 32,
                       ARRAY_NIS_TYPE = 64,       // also an ARRAY_TYPE
                       ARRAY_TYPE = 128,      // arrays and enums
                       EXTERN_TYPE = 256,      // extern "C", not a command type extern
                       SINGLE_LINE_TYPE = 512
                     };

  enum PointerAlign { PTR_ALIGN_NONE,
                      PTR_ALIGN_TYPE,
                      PTR_ALIGN_MIDDLE,
                      PTR_ALIGN_NAME
                    };

  enum ReferenceAlign { REF_ALIGN_NONE = PTR_ALIGN_NONE,
                        REF_ALIGN_TYPE = PTR_ALIGN_TYPE,
                        REF_ALIGN_MIDDLE = PTR_ALIGN_MIDDLE,
                        REF_ALIGN_NAME = PTR_ALIGN_NAME,
                        REF_SAME_AS_PTR
                      };

  enum MinConditional { MINCOND_ZERO,
                        MINCOND_ONE,
                        MINCOND_TWO,
                        MINCOND_ONEHALF,
                        MINCOND_END
                      };

  enum FileEncoding { ENCODING_8BIT,
                      UTF_16BE,
                      UTF_16LE,
                      UTF_32BE,
                      UTF_32LE
                    };

  enum LineEndFormat { LINEEND_DEFAULT,  // Use line break that matches most of the file
                       LINEEND_WINDOWS,
                       LINEEND_LINUX,
                       LINEEND_MACOLD,
                       LINEEND_CRLF = LINEEND_WINDOWS,
                       LINEEND_LF   = LINEEND_LINUX,
                       LINEEND_CR   = LINEEND_MACOLD
                     };


//-----------------------------------------------------------------------------
// Class ASSourceIterator
// A pure virtual class is used by ASFormatter and ASBeautifier instead of
// ASStreamIterator. This allows programs using AStyle as a plugin to define
// their own ASStreamIterator. The ASStreamIterator class must inherit
// this class.
//-----------------------------------------------------------------------------

  class ASSourceIterator
  {
  public:
    ASSourceIterator() {}
    virtual ~ASSourceIterator() {}
    virtual bool hasMoreLines() const = 0;
    virtual std::string nextLine(bool emptyLineWasDeleted = false) = 0;
    virtual std::string peekNextLine() = 0;
    virtual void peekReset() = 0;
  };

//-----------------------------------------------------------------------------
// Class ASResource
//-----------------------------------------------------------------------------

  class ASResource
  {
  public:
    ASResource() {}
    virtual ~ASResource() {}
    void buildAssignmentOperators(std::vector<const std::string*>* assignmentOperators);
    void buildCastOperators(std::vector<const std::string*>* castOperators);
    void buildHeaders(std::vector<const std::string*>* headers, std::int32_t fileType, bool beautifier = false);
    void buildIndentableHeaders(std::vector<const std::string*>* indentableHeaders);
    void buildNonAssignmentOperators(std::vector<const std::string*>* nonAssignmentOperators);
    void buildNonParenHeaders(std::vector<const std::string*>* nonParenHeaders, std::int32_t fileType, bool beautifier = false);
    void buildOperators(std::vector<const std::string*>* operators);
    void buildPreBlockStatements(std::vector<const std::string*>* preBlockStatements, std::int32_t fileType);
    void buildPreCommandHeaders(std::vector<const std::string*>* preCommandHeaders, std::int32_t fileType);
    void buildPreDefinitionHeaders(std::vector<const std::string*>* preDefinitionHeaders, std::int32_t fileType);

  public:
    static const std::string AS_IF, AS_ELSE;
    static const std::string AS_DO, AS_WHILE;
    static const std::string AS_FOR;
    static const std::string AS_SWITCH, AS_CASE, AS_DEFAULT;
    static const std::string AS_TRY, AS_CATCH, AS_THROWS, AS_FINALLY, _AS_TRY, _AS_FINALLY, _AS_EXCEPT;
    static const std::string AS_PUBLIC, AS_PROTECTED, AS_PRIVATE;
    static const std::string AS_CLASS, AS_STRUCT, AS_UNION, AS_INTERFACE, AS_NAMESPACE;
    static const std::string AS_EXTERN, AS_ENUM;
    static const std::string AS_STATIC, AS_CONST, AS_SEALED, AS_OVERRIDE, AS_VOLATILE, AS_NEW;
    static const std::string AS_WHERE, AS_SYNCHRONIZED;
    static const std::string AS_OPERATOR, AS_TEMPLATE;
    static const std::string AS_OPEN_BRACKET, AS_CLOSE_BRACKET;
    static const std::string AS_OPEN_LINE_COMMENT, AS_OPEN_COMMENT, AS_CLOSE_COMMENT;
    static const std::string AS_BAR_DEFINE, AS_BAR_INCLUDE, AS_BAR_IF, AS_BAR_EL, AS_BAR_ENDIF;
    static const std::string AS_RETURN;
    static const std::string AS_CIN, AS_COUT, AS_CERR;
    static const std::string AS_ASSIGN, AS_PLUS_ASSIGN, AS_MINUS_ASSIGN, AS_MULT_ASSIGN;
    static const std::string AS_DIV_ASSIGN, AS_MOD_ASSIGN, AS_XOR_ASSIGN, AS_OR_ASSIGN, AS_AND_ASSIGN;
    static const std::string AS_GR_GR_ASSIGN, AS_LS_LS_ASSIGN, AS_GR_GR_GR_ASSIGN, AS_LS_LS_LS_ASSIGN;
    static const std::string AS_GCC_MIN_ASSIGN, AS_GCC_MAX_ASSIGN;
    static const std::string AS_EQUAL, AS_PLUS_PLUS, AS_MINUS_MINUS, AS_NOT_EQUAL, AS_GR_EQUAL, AS_GR_GR_GR, AS_GR_GR;
    static const std::string AS_LS_EQUAL, AS_LS_LS_LS, AS_LS_LS;
    static const std::string AS_QUESTION_QUESTION, AS_EQUAL_GR;
    static const std::string AS_ARROW, AS_AND, AS_OR;
    static const std::string AS_COLON_COLON;
    static const std::string AS_PLUS, AS_MINUS, AS_MULT, AS_DIV, AS_MOD, AS_GR, AS_LS;
    static const std::string AS_NOT, AS_BIT_XOR, AS_BIT_OR, AS_BIT_AND, AS_BIT_NOT;
    static const std::string AS_QUESTION, AS_COLON, AS_SEMICOLON, AS_COMMA;
    static const std::string AS_ASM, AS__ASM__, AS_MS_ASM, AS_MS__ASM;
    static const std::string AS_FOREACH, AS_LOCK, AS_UNSAFE, AS_FIXED;
    static const std::string AS_GET, AS_SET, AS_ADD, AS_REMOVE;
    static const std::string AS_DELEGATE, AS_UNCHECKED;
    static const std::string AS_CONST_CAST, AS_DYNAMIC_CAST, AS_REINTERPRET_CAST, AS_STATIC_CAST;
  };  // Class ASResource

//-----------------------------------------------------------------------------
// Class ASBase
//-----------------------------------------------------------------------------

  class ASBase
  {
  private:
    // all variables should be set by the "init" function
    std::int32_t baseFileType;      // a value from enum FileType

  protected:
    ASBase() : baseFileType(C_TYPE) { }
    virtual ~ASBase() {}

    // functions definitions are at the end of ASResource.cpp
    bool findKeyword(const std::string& line, std::int32_t i, const std::string& keyword) const;
    std::string getCurrentWord(const std::string& line, std::size_t index) const;

  protected:

    void init(std::int32_t fileTypeArg)
    {
      baseFileType = fileTypeArg;
    }
    bool isCStyle() const
    {
      return (baseFileType == C_TYPE);
    }
    bool isJavaStyle() const
    {
      return (baseFileType == JAVA_TYPE);
    }
    bool isSharpStyle() const
    {
      return (baseFileType == SHARP_TYPE);
    }

    // check if a specific character is a digit
    // NOTE: Visual C isdigit() gives assert error if char > 256
    bool isDigit(char ch) const
    {
      return (ch >= '0' && ch <= '9');
    }

    // check if a specific character can be used in a legal variable/method/class name
    bool isLegalNameChar(char ch) const
    {
      if(isWhiteSpace(ch))
      {
        return false;
      }

      if((unsigned) ch > 127)
      {
        return false;
      }

      return (isalnum(ch)
              || ch == '.' || ch == '_'
              || (isJavaStyle() && ch == '$')
              || (isSharpStyle() && ch == '@'));  // may be used as a prefix
    }

    // check if a specific character can be part of a header
    bool isCharPotentialHeader(const std::string& line, std::size_t i) const
    {
      assert(!isWhiteSpace(line[i]));
      char prevCh = ' ';

      if(i > 0)
      {
        prevCh = line[i - 1];
      }

      if(!isLegalNameChar(prevCh) && isLegalNameChar(line[i]))
      {
        return true;
      }

      return false;
    }

    // check if a specific character can be part of an operator
    bool isCharPotentialOperator(char ch) const
    {
      assert(!isWhiteSpace(ch));

      if((unsigned) ch > 127)
      {
        return false;
      }

      return (ispunct(ch)
              && ch != '{' && ch != '}'
              && ch != '(' && ch != ')'
              && ch != '[' && ch != ']'
              && ch != ';' && ch != ','
              && ch != '#' && ch != '\\'
              && ch != '\'' && ch != '\"');
    }

    // check if a specific character is a whitespace character
    bool isWhiteSpace(char ch) const
    {
      return (ch == ' ' || ch == '\t');
    }

    // peek at the next unread character.
    char peekNextChar(const std::string& line, std::int32_t i) const
    {
      char ch = ' ';
      std::size_t peekNum = line.find_first_not_of(" \t", i + 1);

      if(peekNum == std::string::npos)
      {
        return ch;
      }

      ch = line[peekNum];
      return ch;
    }
  };  // Class ASBase

//-----------------------------------------------------------------------------
// Class ASBeautifier
//-----------------------------------------------------------------------------

  class ASBeautifier : protected ASResource, protected ASBase
  {
  public:
    ASBeautifier();
    virtual ~ASBeautifier();
    virtual void init(ASSourceIterator* iter);
    void init();
    virtual std::string beautify(const std::string& line);
    void setTabIndentation(std::int32_t length = 4, bool forceTabs = false);
    void setSpaceIndentation(std::int32_t length = 4);
    void setMaxInStatementIndentLength(std::int32_t max);
    void setMinConditionalIndentOption(std::int32_t min);
    void setMinConditionalIndentLength();
    void setModeManuallySet(bool state);
    void setClassIndent(bool state);
    void setSwitchIndent(bool state);
    void setCaseIndent(bool state);
    void setNamespaceIndent(bool state);
    void setLabelIndent(bool state);
    void setCStyle();
    void setJavaStyle();
    void setSharpStyle();
    void setEmptyLineFill(bool state);
    void setPreprocessorIndent(bool state);
    std::int32_t  getBeautifierFileType() const;
    std::int32_t  getFileType();
    std::int32_t  getIndentLength(void);
    std::string getIndentString(void);
    std::string getNextWord(const std::string& line, std::size_t currPos) const;
    bool getBracketIndent(void);
    bool getBlockIndent(void);
    bool getCaseIndent(void);
    bool getClassIndent(void);
    bool getEmptyLineFill(void);
    bool getForceTabIndentation(void);
    bool getModeManuallySet(void);
    bool getPreprocessorIndent(void);
    bool getSwitchIndent(void);

  protected:
    void deleteBeautifierVectors();
    const std::string* findHeader(const std::string& line, std::int32_t i,
                                  const std::vector<const std::string*>* possibleHeaders) const;
    const std::string* findOperator(const std::string& line, std::int32_t i,
                                    const std::vector<const std::string*>* possibleOperators) const;
    std::int32_t getNextProgramCharDistance(const std::string& line, std::int32_t i) const;
    std::int32_t  indexOf(std::vector<const std::string*> &container, const std::string* element);
    void setBlockIndent(bool state);
    void setBracketIndent(bool state);
    std::string trim(const std::string& str);

    // variables set by ASFormatter - must be updated in activeBeautifierStack
    std::int32_t  inLineNumber;
    std::int32_t  horstmannIndentInStatement;
    std::int32_t  nonInStatementBracket;
    bool lineCommentNoBeautify;
    bool isNonInStatementArray;
    bool isSharpAccessor;
    bool isSharpDelegate;
    bool isInExtern;
    bool isInBeautifySQL;
    bool isInIndentableStruct;

  private:
    ASBeautifier(const ASBeautifier& copy);
    ASBeautifier& operator=(ASBeautifier&);        // not to be implemented

    void computePreliminaryIndentation();
    void parseCurrentLine(const std::string& line);
    void processProcessor(std::string& line);
    void registerInStatementIndent(const std::string& line, std::int32_t i, std::int32_t spaceTabCount,
                                   std::int32_t tabIncrementIn, std::int32_t minIndent, bool updateParenStack);
    void initVectors();
    std::string preLineWS(std::int32_t spaceTabCount_, std::int32_t tabCount_);
    std::int32_t  convertTabToSpaces(std::int32_t i, std::int32_t tabIncrementIn) const;
    std::int32_t  getInStatementIndentAssign(const std::string& line, std::size_t currPos) const;
    std::int32_t  getInStatementIndentComma(const std::string& line, std::size_t currPos) const;
    bool isClassAccessModifier(const std::string& line) const;
    bool isIndentedPreprocessor(const std::string& line, std::size_t currPos) const;
    bool isLineEndComment(const std::string& line, std::int32_t startPos) const;
    bool statementEndsWithComma(const std::string& line, std::int32_t index) const;
    std::vector<std::vector<const std::string*>*>* copyTempStacks(const ASBeautifier& other) const;
    template<typename T> void deleteContainer(T& container);
    void deleteContainer(std::vector<std::vector<const std::string*>*>* &container);
    template<typename T> void initContainer(T& container, T value);

  private:  // variables

    std::int32_t beautifierFileType;
    std::vector<const std::string*>* headers;
    std::vector<const std::string*>* nonParenHeaders;
    std::vector<const std::string*>* preBlockStatements;
    std::vector<const std::string*>* preCommandHeaders;
    std::vector<const std::string*>* assignmentOperators;
    std::vector<const std::string*>* nonAssignmentOperators;
    std::vector<const std::string*>* indentableHeaders;

    std::vector<ASBeautifier*> *waitingBeautifierStack;
    std::vector<ASBeautifier*> *activeBeautifierStack;
    std::vector<std::int32_t> *waitingBeautifierStackLengthStack;
    std::vector<std::int32_t> *activeBeautifierStackLengthStack;
    std::vector<const std::string*> *headerStack;
    std::vector< std::vector<const std::string*>* > *tempStacks;
    std::vector<std::int32_t> *blockParenDepthStack;
    std::vector<bool> *blockStatementStack;
    std::vector<bool> *parenStatementStack;
    std::vector<bool> *bracketBlockStateStack;
    std::vector<std::int32_t> *inStatementIndentStack;
    std::vector<std::int32_t> *inStatementIndentStackSizeStack;
    std::vector<std::int32_t> *parenIndentStack;

    ASSourceIterator* sourceIterator;
    const std::string* currentHeader;
    const std::string* previousLastLineHeader;
    const std::string* probationHeader;
    const std::string* lastLineHeader;
    std::string indentString;
    bool isInQuote;
    bool isInVerbatimQuote;
    bool haveLineContinuationChar;
    bool isInAsm;
    bool isInAsmOneLine;
    bool isInAsmBlock;
    bool isInComment;
    bool isInHorstmannComment;
    bool isInCase;
    bool isInQuestion;
    bool isInStatement;
    bool isInHeader;
    bool isInTemplate;
    bool isInDefine;
    bool isInDefineDefinition;
    bool classIndent;
    bool isInClassInitializer;
    bool isInClassHeaderTab;
    bool isInEnum;
    bool switchIndent;
    bool caseIndent;
    bool namespaceIndent;
    bool bracketIndent;
    bool blockIndent;
    bool labelIndent;
    bool preprocessorIndent;
    bool isInConditional;
    bool isMinConditionalManuallySet;
    bool isModeManuallySet;
    bool shouldForceTabIndentation;
    bool emptyLineFill;
    bool backslashEndsPrevLine;
    bool lineOpensComment;
    bool blockCommentNoIndent;
    bool blockCommentNoBeautify;
    bool previousLineProbationTab;
    bool lineBeginsWithBracket;
    bool shouldIndentBrackettedLine;
    bool isInClass;
    bool isInSwitch;
    bool foundPreCommandHeader;
    std::int32_t  tabCount;
    std::int32_t  spaceTabCount;
    std::int32_t  lineOpeningBlocksNum;
    std::int32_t  lineClosingBlocksNum;
    std::int32_t  fileType;
    std::int32_t  minConditionalOption;
    std::int32_t  minConditionalIndent;
    std::int32_t  parenDepth;
    std::int32_t  indentLength;
    std::int32_t  blockTabCount;
    std::int32_t  maxInStatementIndent;
    std::int32_t  classInitializerTabs;
    std::int32_t  templateDepth;
    std::int32_t  prevFinalLineSpaceTabCount;
    std::int32_t  prevFinalLineTabCount;
    std::int32_t  defineTabCount;
    char quoteChar;
    char prevNonSpaceCh;
    char currentNonSpaceCh;
    char currentNonLegalCh;
    char prevNonLegalCh;
  };  // Class ASBeautifier

//-----------------------------------------------------------------------------
// Class ASEnhancer
//-----------------------------------------------------------------------------

  class ASEnhancer : protected ASBase
  {
  public:  // functions
    ASEnhancer();
    virtual ~ASEnhancer();
    void init(std::int32_t, std::int32_t, std::string, bool, bool, bool);
    void enhance(std::string& line, bool isInPreprocessor, bool isInSQL);

  private:
    // options from command line or options file
    std::int32_t  indentLength;
    bool useTabs;
    bool caseIndent;
    bool preprocessorIndent;
    bool emptyLineFill;

    // parsing variables
    std::int32_t  lineNumber;
    bool isInQuote;
    bool isInComment;
    char quoteChar;

    // unindent variables
    std::int32_t  bracketCount;
    std::int32_t  switchDepth;
    bool lookingForCaseBracket;
    bool unindentNextLine;
    bool shouldIndentLine;

    // struct used by ParseFormattedLine function
    // contains variables used to unindent the case blocks
    struct switchVariables
    {
      std::int32_t  switchBracketCount;
      std::int32_t  unindentDepth;
      bool unindentCase;
    };

    switchVariables sw;                      // switch variables struct
    std::vector<switchVariables> switchStack;     // stack std::vector of switch variables

    // event table variables
    bool nextLineIsEventIndent;             // begin event table indent is reached
    bool isInEventTable;                    // need to indent an event table

    // SQL variables
    bool nextLineIsDeclareIndent;           // begin declare section indent is reached
    bool isInDeclareSection;                // need to indent a declare section


  private:  // functions
    std::size_t  findCaseColon(std::string&  line, std::size_t caseIndex) const;
    std::int32_t     indentLine(std::string&  line, std::int32_t indent) const;
    bool    isBeginDeclareSectionSQL(std::string&  line, std::size_t index) const;
    bool    isEndDeclareSectionSQL(std::string&  line, std::size_t index) const;
    bool    isOneLineBlockReached(std::string& line, std::int32_t startChar) const;
    std::size_t  processSwitchBlock(std::string&  line, std::size_t index);
    std::int32_t     unindentLine(std::string&  line, std::int32_t unindent) const;
  };  // Class ASEnhancer

//-----------------------------------------------------------------------------
// Class ASFormatter
//-----------------------------------------------------------------------------

  class ASFormatter : public ASBeautifier
  {
  public:  // functions
    ASFormatter();
    virtual ~ASFormatter();
    virtual void init(ASSourceIterator* iter);
    virtual bool hasMoreLines() const;
    virtual std::string nextLine();
    LineEndFormat getLineEndFormat() const;
    bool getIsLineReady() const;
    void setFormattingStyle(FormatStyle style);
    void setAddBracketsMode(bool state);
    void setAddOneLineBracketsMode(bool state);
    void setBracketFormatMode(BracketMode mode);
    void setBreakClosingHeaderBracketsMode(bool state);
    void setBreakBlocksMode(bool state);
    void setBreakClosingHeaderBlocksMode(bool state);
    void setBreakElseIfsMode(bool state);
    void setBreakOneLineBlocksMode(bool state);
    void setDeleteEmptyLinesMode(bool state);
    void setIndentCol1CommentsMode(bool state);
    void setLineEndFormat(LineEndFormat fmt);
    void setOperatorPaddingMode(bool mode);
    void setParensOutsidePaddingMode(bool mode);
    void setParensInsidePaddingMode(bool mode);
    void setParensHeaderPaddingMode(bool mode);
    void setParensUnPaddingMode(bool state);
    void setPointerAlignment(PointerAlign alignment);
    void setReferenceAlignment(ReferenceAlign alignment);
    void setSingleStatementsMode(bool state);
    void setTabSpaceConversionMode(bool state);
    std::size_t getChecksumIn() const;
    std::size_t getChecksumOut() const;
    std::int32_t  getChecksumDiff() const;
    std::int32_t  getFormatterFileType() const;

  private:  // functions
    ASFormatter(const ASFormatter& copy);       // copy constructor not to be imlpemented
    ASFormatter& operator=(ASFormatter&);       // assignment operator not to be implemented
    template<typename T> void deleteContainer(T& container);
    template<typename T> void initContainer(T& container, T value);
    char peekNextChar() const;
    BracketType getBracketType();
    bool addBracketsToStatement();
    bool commentAndHeaderFollows();
    bool getNextChar();
    bool getNextLine(bool emptyLineWasDeleted = false);
    bool isBeforeComment() const;
    bool isBeforeAnyComment() const;
    bool isBeforeAnyLineEndComment(std::int32_t startPos) const;
    bool isBeforeMultipleLineEndComments(std::int32_t startPos) const;
    bool isBracketType(BracketType a, BracketType b) const;
    bool isClosingHeader(const std::string* header) const;
    bool isCurrentBracketBroken() const;
    bool isDereferenceOrAddressOf() const;
    bool isExecSQL(std::string&  line, std::size_t index) const;
    bool isEmptyLine(const std::string& line) const;
    bool isNextWordSharpNonParenHeader(std::int32_t startChar) const;
    bool isNonInStatementArrayBracket() const;
    bool isPointerOrReference() const;
    bool isPointerOrReferenceCentered() const;
    bool isSharpStyleWithParen(const std::string* header) const;
    bool isStructAccessModified(std::string&  firstLine, std::size_t index) const;
    bool isUnaryOperator() const;
    bool isImmediatelyPostCast() const;
    bool isInExponent() const;
    bool isNextCharOpeningBracket(std::int32_t startChar) const;
    bool isOkToBreakBlock(BracketType bracketType) const;
    std::int32_t  getCurrentLineCommentAdjustment();
    std::int32_t  getNextLineCommentAdjustment();
    std::int32_t  isOneLineBlockReached(std::string& line, std::int32_t startChar) const;
    void adjustComments();
    void appendCharInsideComments();
    void appendSequence(const std::string& sequence, bool canBreakLine = true);
    void appendSpacePad();
    void appendSpaceAfter();
    void breakLine();
    void buildLanguageVectors();
    void checkForHeaderFollowingComment(const std::string& firstLine);
    void checkIfTemplateOpener();
    void convertTabToSpaces();
    void deleteContainer(std::vector<BracketType>* &container);
    void formatArrayRunIn();
    void formatRunIn();
    void formatArrayBrackets(BracketType bracketType, bool isOpeningArrayBracket);
    void formatClosingBracket(BracketType bracketType);
    void formatCommentBody();
    void formatCommentOpener();
    void formatLineCommentBody();
    void formatLineCommentOpener();
    void formatOpeningBracket(BracketType bracketType);
    void formatQuoteBody();
    void formatQuoteOpener();
    void formatPointerOrReference();
    void formatPointerOrReferenceCast();
    void fixOptionVariableConflicts();
    void goForward(std::int32_t i);
    void isLineBreakBeforeClosingHeader();
    void initContainer(std::vector<BracketType>* &container, std::vector<BracketType>* value);
    void initNewLine();
    void padOperators(const std::string* newOperator);
    void padParens();
    void processPreprocessor();
    void setAttachClosingBracket(bool state);
    void setBreakBlocksVariables();
    void trimContinuationLine();
    std::size_t findNextChar(std::string& line, char searchChar, std::int32_t searchStart = 0);
    std::string getPreviousWord(const std::string& line, std::int32_t currPos) const;
    std::string peekNextText(const std::string& firstLine, bool endOnEmptyLine = false, bool shouldReset = false) const;

  private:  // variables
    std::int32_t formatterFileType;
    std::vector<const std::string*>* headers;
    std::vector<const std::string*>* nonParenHeaders;
    std::vector<const std::string*>* preDefinitionHeaders;
    std::vector<const std::string*>* preCommandHeaders;
    std::vector<const std::string*>* operators;
    std::vector<const std::string*>* assignmentOperators;
    std::vector<const std::string*>* castOperators;

    ASSourceIterator* sourceIterator;
    ASEnhancer* enhancer;

    std::vector<const std::string*> *preBracketHeaderStack;
    std::vector<BracketType> *bracketTypeStack;
    std::vector<std::int32_t> *parenStack;
    std::vector<bool> *structStack;
    std::string readyFormattedLine;
    std::string currentLine;
    std::string formattedLine;
    const std::string* currentHeader;
    const std::string* previousOperator;    // used ONLY by pad-oper
    char currentChar;
    char previousChar;
    char previousNonWSChar;
    char previousCommandChar;
    char quoteChar;
    std::int32_t  charNum;
    std::int32_t  horstmannIndentChars;
    std::int32_t  nextLineSpacePadNum;
    std::int32_t  preprocBracketTypeStackSize;
    std::int32_t  spacePadNum;
    std::int32_t  tabIncrementIn;
    std::int32_t  templateDepth;
    std::int32_t  traceLineNumber;
    std::size_t checksumIn;
    std::size_t checksumOut;
    std::size_t leadingSpaces;
    std::size_t formattedLineCommentNum;     // comment location on formattedLine
    std::size_t currentLineFirstBracketNum;  // first bracket location on currentLine
    std::size_t previousReadyFormattedLineLength;
    FormatStyle formattingStyle;
    BracketMode bracketFormatMode;
    BracketType previousBracketType;
    PointerAlign pointerAlignment;
    ReferenceAlign referenceAlignment;
    LineEndFormat lineEnd;
    bool computeChecksumIn(const std::string& currentLine_);
    bool computeChecksumOut(const std::string& beautifiedLine);
    bool isVirgin;
    bool shouldPadOperators;
    bool shouldPadParensOutside;
    bool shouldPadParensInside;
    bool shouldPadHeader;
    bool shouldUnPadParens;
    bool shouldConvertTabs;
    bool shouldIndentCol1Comments;
    bool isInLineComment;
    bool isInComment;
    bool noTrimCommentContinuation;
    bool isInPreprocessor;
    bool isInPreprocessorBeautify;
    bool isInTemplate;
    bool doesLineStartComment;
    bool lineEndsInCommentOnly;
    bool lineIsLineCommentOnly;
    bool lineIsEmpty;
    bool isImmediatelyPostCommentOnly;
    bool isImmediatelyPostEmptyLine;
    bool isInQuote;
    bool isInVerbatimQuote;
    bool haveLineContinuationChar;
    bool isInQuoteContinuation;
    bool isSpecialChar;
    bool isNonParenHeader;
    bool foundQuestionMark;
    bool foundPreDefinitionHeader;
    bool foundNamespaceHeader;
    bool foundClassHeader;
    bool foundStructHeader;
    bool foundInterfaceHeader;
    bool foundPreCommandHeader;
    bool foundCastOperator;
    bool isInLineBreak;
    bool endOfCodeReached;
    bool lineCommentNoIndent;
    bool isInExecSQL;
    bool isInAsm;
    bool isInAsmOneLine;
    bool isInAsmBlock;
    bool isLineReady;
    bool isPreviousBracketBlockRelated;
    bool isInPotentialCalculation;
    bool isCharImmediatelyPostComment;
    bool isPreviousCharPostComment;
    bool isCharImmediatelyPostLineComment;
    bool isCharImmediatelyPostOpenBlock;
    bool isCharImmediatelyPostCloseBlock;
    bool isCharImmediatelyPostTemplate;
    bool isCharImmediatelyPostReturn;
    bool isCharImmediatelyPostOperator;
    bool isCharImmediatelyPostPointerOrReference;
    bool breakCurrentOneLineBlock;
    bool isInHorstmannRunIn;
    bool currentLineBeginsWithBracket;
    bool shouldAttachClosingBracket;
    bool shouldBreakOneLineBlocks;
    bool shouldReparseCurrentChar;
    bool shouldBreakOneLineStatements;
    bool shouldBreakClosingHeaderBrackets;
    bool shouldBreakElseIfs;
    bool shouldAddBrackets;
    bool shouldAddOneLineBrackets;
    bool shouldDeleteEmptyLines;
    bool needHeaderOpeningBracket;
    bool shouldBreakLineAtNextChar;
    bool passedSemicolon;
    bool passedColon;
    bool isImmediatelyPostNonInStmt;
    bool isCharImmediatelyPostNonInStmt;
    bool isImmediatelyPostComment;
    bool isImmediatelyPostLineComment;
    bool isImmediatelyPostEmptyBlock;
    bool isImmediatelyPostPreprocessor;
    bool isImmediatelyPostReturn;
    bool isImmediatelyPostOperator;
    bool isImmediatelyPostPointerOrReference;

    bool shouldBreakBlocks;
    bool shouldBreakClosingHeaderBlocks;
    bool isPrependPostBlockEmptyLineRequested;
    bool isAppendPostBlockEmptyLineRequested;

    bool prependEmptyLine;
    bool appendOpeningBracket;
    bool foundClosingHeader;

    bool isInHeader;
    bool isImmediatelyPostHeader;
    bool isInCase;
    bool isJavaStaticConstructor;

  private:  // inline functions
    // append a character to the current formatted line.
    void appendChar(char ch, bool canBreakLine)
    {
      if(canBreakLine && isInLineBreak)
      {
        breakLine();
      }

      formattedLine.append(1, ch);
      isImmediatelyPostCommentOnly = false;
    }

    // append the CURRENT character (curentChar) to the current formatted line.
    void appendCurrentChar(bool canBreakLine = true)
    {
      appendChar(currentChar, canBreakLine);
    }

    // check if a specific sequence exists in the current placement of the current line
    bool isSequenceReached(const char* sequence) const
    {
      return currentLine.compare(charNum, strlen(sequence), sequence) == 0;
    }

    // call ASBase::findHeader for the current character
    const std::string* findHeader(const std::vector<const std::string*>* headers_)
    {
      return ASBeautifier::findHeader(currentLine, charNum, headers_);
    }

    // call ASBase::findOperator for the current character
    const std::string* findOperator(const std::vector<const std::string*>* headers_)
    {
      return ASBeautifier::findOperator(currentLine, charNum, headers_);
    }
  };  // Class ASFormatter


//-----------------------------------------------------------------------------
// astyle namespace global declarations
//-----------------------------------------------------------------------------
// sort comparison functions for ASResource
  bool sortOnLength(const std::string* a, const std::string* b);
  bool sortOnName(const std::string* a, const std::string* b);

}   // end of astyle namespace

// end of astyle namespace  --------------------------------------------------


//-----------------------------------------------------------------------------
// declarations for library build
// global because they are called externally and are NOT part of the namespace
//-----------------------------------------------------------------------------

typedef void (STDCALL* fpError)(std::int32_t, const char*);      // pointer to callback error handler
typedef char* (STDCALL* fpAlloc)(unsigned long);    // pointer to callback memory allocation
extern "C" EXPORT char* STDCALL AStyleMain(const char*, const char*, fpError, fpAlloc);
extern "C" EXPORT const char* STDCALL AStyleGetVersion(void);


#endif // closes ASTYLE_H
