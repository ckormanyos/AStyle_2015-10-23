/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *   ASLocalizer.h
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

#ifndef ASLOCALIZER_H
#define ASLOCALIZER_H

namespace astyle
{

#ifndef ASTYLE_LIB

//-----------------------------------------------------------------------------
// ASLocalizer class for console build.
// This class encapsulates all language-dependent settings and is a
// generalization of the C locale concept.
//-----------------------------------------------------------------------------
  class Translation;

  class ASLocalizer
  {
  public:    // functions
    ASLocalizer();
    virtual ~ASLocalizer();
    std::string getLanguageID() const;
    const Translation* getTranslationClass() const;
#ifdef _WIN32
    void setLanguageFromLCID(std::size_t lcid);
#endif
    void setLanguageFromName(const char* langID);
    const char* settext(const char* textIn) const;

  private:  // functions
    void setTranslationClass();

  private:  // variables
    Translation* m_translation;    // pointer to a polymorphic Translation class
    std::string m_langID;        // language identifier from the locale
    std::string m_subLangID;        // sub language identifier, if needed
    std::string m_localeName;      // name of the current locale (Linux only)
    std::size_t m_lcid;          // LCID of the user locale (Windows only)
  };

//----------------------------------------------------------------------------
// Translation base class.
//----------------------------------------------------------------------------

  class Translation
// This base class is inherited by the language translation classes.
// Polymorphism is used to call the correct language translator.
// This class contains the translation std::vector and settext translation method.
// The language std::vector is built by the language sub classes.
// NOTE: this class must have virtual methods for typeid() to work.
  {
  public:
    Translation() {};
    std::string convertToMultiByte(const std::wstring& wideStr) const;
    std::size_t getTranslationVectorSize() const;
    bool getWideTranslation(const std::string& stringIn, std::wstring& wideOut) const;
    std::string& translate(const std::string& stringIn) const;

  protected:
    void addPair(const std::string& english, const std::wstring& translated);
    // variables
    std::vector<std::pair<std::string, std::wstring> > m_translation;    // translation std::vector

  private:
    // unused method so the class will be identified as polymorphic
    virtual void virtualClass() {}
  };

//----------------------------------------------------------------------------
// Translation classes
// One class for each language.
// These classes have only a constructor which builds the language std::vector.
//----------------------------------------------------------------------------

  class ChineseSimplified : public Translation
  {
  public:
    ChineseSimplified();
  };

  class ChineseTraditional : public Translation
  {
  public:
    ChineseTraditional();
  };

  class English : public Translation
  {
  public:
    English();
  };

  class French : public Translation
  {
  public:
    French();
  };

  class German : public Translation
  {
  public:
    German();
  };

  class Hindi : public Translation
  {
  public:
    Hindi();
  };

  class Spanish : public Translation
  {
  public:
    Spanish();
  };

#endif  //  ASTYLE_LIB

}  // namespace astyle

#endif  //  ASLOCALIZER_H
