/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *   ASResource.cpp
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

#include "astyle.h"
#include <algorithm>


namespace astyle
{
  const std::string ASResource::AS_IF = std::string("if");
  const std::string ASResource::AS_ELSE = std::string("else");
  const std::string ASResource::AS_FOR = std::string("for");
  const std::string ASResource::AS_DO = std::string("do");
  const std::string ASResource::AS_WHILE = std::string("while");
  const std::string ASResource::AS_SWITCH = std::string("switch");
  const std::string ASResource::AS_CASE = std::string("case");
  const std::string ASResource::AS_DEFAULT = std::string("default");
  const std::string ASResource::AS_CLASS = std::string("class");
  const std::string ASResource::AS_VOLATILE = std::string("volatile");
  const std::string ASResource::AS_STRUCT = std::string("struct");
  const std::string ASResource::AS_UNION = std::string("union");
  const std::string ASResource::AS_INTERFACE = std::string("interface");
  const std::string ASResource::AS_NAMESPACE = std::string("namespace");
  const std::string ASResource::AS_EXTERN = std::string("extern");
  const std::string ASResource::AS_ENUM = std::string("enum");
  const std::string ASResource::AS_PUBLIC = std::string("public");
  const std::string ASResource::AS_PROTECTED = std::string("protected");
  const std::string ASResource::AS_PRIVATE = std::string("private");
  const std::string ASResource::AS_STATIC = std::string("static");
  const std::string ASResource::AS_SYNCHRONIZED = std::string("synchronized");
  const std::string ASResource::AS_OPERATOR = std::string("operator");
  const std::string ASResource::AS_TEMPLATE = std::string("template");
  const std::string ASResource::AS_TRY = std::string("try");
  const std::string ASResource::AS_CATCH = std::string("catch");
  const std::string ASResource::AS_FINALLY = std::string("finally");
  const std::string ASResource::_AS_TRY = std::string("__try");
  const std::string ASResource::_AS_FINALLY = std::string("__finally");
  const std::string ASResource::_AS_EXCEPT = std::string("__except");
  const std::string ASResource::AS_THROWS = std::string("throws");
  const std::string ASResource::AS_CONST = std::string("const");
  const std::string ASResource::AS_SEALED = std::string("sealed");
  const std::string ASResource::AS_OVERRIDE = std::string("override");
  const std::string ASResource::AS_WHERE = std::string("where");
  const std::string ASResource::AS_NEW = std::string("new");

  const std::string ASResource::AS_ASM = std::string("asm");
  const std::string ASResource::AS__ASM__ = std::string("__asm__");
  const std::string ASResource::AS_MS_ASM = std::string("_asm");
  const std::string ASResource::AS_MS__ASM = std::string("__asm");

  const std::string ASResource::AS_BAR_DEFINE = std::string("#define");
  const std::string ASResource::AS_BAR_INCLUDE = std::string("#include");
  const std::string ASResource::AS_BAR_IF = std::string("#if");
  const std::string ASResource::AS_BAR_EL = std::string("#el");
  const std::string ASResource::AS_BAR_ENDIF = std::string("#endif");

  const std::string ASResource::AS_OPEN_BRACKET = std::string("{");
  const std::string ASResource::AS_CLOSE_BRACKET = std::string("}");
  const std::string ASResource::AS_OPEN_LINE_COMMENT = std::string("//");
  const std::string ASResource::AS_OPEN_COMMENT = std::string("/*");
  const std::string ASResource::AS_CLOSE_COMMENT = std::string("*/");

  const std::string ASResource::AS_ASSIGN = std::string("=");
  const std::string ASResource::AS_PLUS_ASSIGN = std::string("+=");
  const std::string ASResource::AS_MINUS_ASSIGN = std::string("-=");
  const std::string ASResource::AS_MULT_ASSIGN = std::string("*=");
  const std::string ASResource::AS_DIV_ASSIGN = std::string("/=");
  const std::string ASResource::AS_MOD_ASSIGN = std::string("%=");
  const std::string ASResource::AS_OR_ASSIGN = std::string("|=");
  const std::string ASResource::AS_AND_ASSIGN = std::string("&=");
  const std::string ASResource::AS_XOR_ASSIGN = std::string("^=");
  const std::string ASResource::AS_GR_GR_ASSIGN = std::string(">>=");
  const std::string ASResource::AS_LS_LS_ASSIGN = std::string("<<=");
  const std::string ASResource::AS_GR_GR_GR_ASSIGN = std::string(">>>=");
  const std::string ASResource::AS_LS_LS_LS_ASSIGN = std::string("<<<=");
  const std::string ASResource::AS_GCC_MIN_ASSIGN = std::string("<?");
  const std::string ASResource::AS_GCC_MAX_ASSIGN = std::string(">?");

  const std::string ASResource::AS_RETURN = std::string("return");
  const std::string ASResource::AS_CIN = std::string("cin");
  const std::string ASResource::AS_COUT = std::string("cout");
  const std::string ASResource::AS_CERR = std::string("cerr");

  const std::string ASResource::AS_EQUAL = std::string("==");
  const std::string ASResource::AS_PLUS_PLUS = std::string("++");
  const std::string ASResource::AS_MINUS_MINUS = std::string("--");
  const std::string ASResource::AS_NOT_EQUAL = std::string("!=");
  const std::string ASResource::AS_GR_EQUAL = std::string(">=");
  const std::string ASResource::AS_GR_GR = std::string(">>");
  const std::string ASResource::AS_GR_GR_GR = std::string(">>>");
  const std::string ASResource::AS_LS_EQUAL = std::string("<=");
  const std::string ASResource::AS_LS_LS = std::string("<<");
  const std::string ASResource::AS_LS_LS_LS = std::string("<<<");
  const std::string ASResource::AS_QUESTION_QUESTION = std::string("??");
  const std::string ASResource::AS_EQUAL_GR = std::string("=>");            // C# lambda expression arrow
  const std::string ASResource::AS_ARROW = std::string("->");
  const std::string ASResource::AS_AND = std::string("&&");
  const std::string ASResource::AS_OR = std::string("||");
  const std::string ASResource::AS_COLON_COLON = std::string("::");

  const std::string ASResource::AS_PLUS = std::string("+");
  const std::string ASResource::AS_MINUS = std::string("-");
  const std::string ASResource::AS_MULT = std::string("*");
  const std::string ASResource::AS_DIV = std::string("/");
  const std::string ASResource::AS_MOD = std::string("%");
  const std::string ASResource::AS_GR = std::string(">");
  const std::string ASResource::AS_LS = std::string("<");
  const std::string ASResource::AS_NOT = std::string("!");
  const std::string ASResource::AS_BIT_OR = std::string("|");
  const std::string ASResource::AS_BIT_AND = std::string("&");
  const std::string ASResource::AS_BIT_NOT = std::string("~");
  const std::string ASResource::AS_BIT_XOR = std::string("^");
  const std::string ASResource::AS_QUESTION = std::string("?");
  const std::string ASResource::AS_COLON = std::string(":");
  const std::string ASResource::AS_COMMA = std::string(",");
  const std::string ASResource::AS_SEMICOLON = std::string(";");

  const std::string ASResource::AS_FOREACH = std::string("foreach");
  const std::string ASResource::AS_LOCK = std::string("lock");
  const std::string ASResource::AS_UNSAFE = std::string("unsafe");
  const std::string ASResource::AS_FIXED = std::string("fixed");
  const std::string ASResource::AS_GET = std::string("get");
  const std::string ASResource::AS_SET = std::string("set");
  const std::string ASResource::AS_ADD = std::string("add");
  const std::string ASResource::AS_REMOVE = std::string("remove");
  const std::string ASResource::AS_DELEGATE = std::string("delegate");
  const std::string ASResource::AS_UNCHECKED = std::string("unchecked");

  const std::string ASResource::AS_CONST_CAST = std::string("const_cast");
  const std::string ASResource::AS_DYNAMIC_CAST = std::string("dynamic_cast");
  const std::string ASResource::AS_REINTERPRET_CAST = std::string("reinterpret_cast");
  const std::string ASResource::AS_STATIC_CAST = std::string("static_cast");


  /**
   * Sort comparison function.
   * Compares the length of the value of pointers in the vectors.
   * The LONGEST strings will be first in the std::vector.
   *
   * @params the std::string pointers to be compared.
   */
  bool sortOnLength(const std::string* a, const std::string* b)
  {
    return (*a).length() > (*b).length();
  }

  /**
   * Sort comparison function.
   * Compares the value of pointers in the vectors.
   *
   * @params the std::string pointers to be compared.
   */
  bool sortOnName(const std::string* a, const std::string* b)
  {
    return *a < *b;
  }

  /**
   * Build the std::vector of assignment operators.
   * Used by BOTH ASFormatter.cpp and ASBeautifier.cpp
   *
   * @param assignmentOperators   a reference to the std::vector to be built.
   */
  void ASResource::buildAssignmentOperators(std::vector<const std::string*>* assignmentOperators)
  {
    assignmentOperators->push_back(&AS_ASSIGN);
    assignmentOperators->push_back(&AS_PLUS_ASSIGN);
    assignmentOperators->push_back(&AS_MINUS_ASSIGN);
    assignmentOperators->push_back(&AS_MULT_ASSIGN);
    assignmentOperators->push_back(&AS_DIV_ASSIGN);
    assignmentOperators->push_back(&AS_MOD_ASSIGN);
    assignmentOperators->push_back(&AS_OR_ASSIGN);
    assignmentOperators->push_back(&AS_AND_ASSIGN);
    assignmentOperators->push_back(&AS_XOR_ASSIGN);

    // Java
    assignmentOperators->push_back(&AS_GR_GR_GR_ASSIGN);
    assignmentOperators->push_back(&AS_GR_GR_ASSIGN);
    assignmentOperators->push_back(&AS_LS_LS_ASSIGN);

    // Unknown
    assignmentOperators->push_back(&AS_LS_LS_LS_ASSIGN);

    sort(assignmentOperators->begin(), assignmentOperators->end(), sortOnLength);
  }

  /**
   * Build the std::vector of C++ cast operators.
   * Used by ONLY ASFormatter.cpp
   *
   * @param castOperators     a reference to the std::vector to be built.
   */
  void ASResource::buildCastOperators(std::vector<const std::string*>* castOperators)
  {
    castOperators->push_back(&AS_CONST_CAST);
    castOperators->push_back(&AS_DYNAMIC_CAST);
    castOperators->push_back(&AS_REINTERPRET_CAST);
    castOperators->push_back(&AS_STATIC_CAST);
  }

  /**
   * Build the std::vector of header words.
   * Used by BOTH ASFormatter.cpp and ASBeautifier.cpp
   *
   * @param headers       a reference to the std::vector to be built.
   */
  void ASResource::buildHeaders(std::vector<const std::string*>* headers, std::int32_t fileType, bool beautifier)
  {
    headers->push_back(&AS_IF);
    headers->push_back(&AS_ELSE);
    headers->push_back(&AS_FOR);
    headers->push_back(&AS_WHILE);
    headers->push_back(&AS_DO);
    headers->push_back(&AS_SWITCH);
    headers->push_back(&AS_CASE);
    headers->push_back(&AS_DEFAULT);
    headers->push_back(&AS_TRY);
    headers->push_back(&AS_CATCH);

    if(fileType == C_TYPE)
    {
      headers->push_back(&_AS_TRY);    // __try
      headers->push_back(&_AS_FINALLY);  // __finally
      headers->push_back(&_AS_EXCEPT);  // __except
    }

    if(fileType == JAVA_TYPE)
    {
      headers->push_back(&AS_FINALLY);
      headers->push_back(&AS_SYNCHRONIZED);
    }

    if(fileType == SHARP_TYPE)
    {
      headers->push_back(&AS_FINALLY);
      headers->push_back(&AS_FOREACH);
      headers->push_back(&AS_LOCK);
      headers->push_back(&AS_FIXED);
      headers->push_back(&AS_GET);
      headers->push_back(&AS_SET);
      headers->push_back(&AS_ADD);
      headers->push_back(&AS_REMOVE);
    }

    if(beautifier)
    {
      if(fileType == C_TYPE)
      {
        headers->push_back(&AS_TEMPLATE);
      }

      if(fileType == JAVA_TYPE)
      {
        headers->push_back(&AS_STATIC);         // for static constructor
      }
    }

    sort(headers->begin(), headers->end(), sortOnName);
  }

  /**
   * Build the std::vector of indentable headers.
   * Used by ONLY ASBeautifier.cpp
   *
   * @param indentableHeaders     a reference to the std::vector to be built.
   */
  void ASResource::buildIndentableHeaders(std::vector<const std::string*>* indentableHeaders)
  {
    indentableHeaders->push_back(&AS_RETURN);

    sort(indentableHeaders->begin(), indentableHeaders->end(), sortOnName);
  }

  /**
   * Build the std::vector of non-assignment operators.
   * Used by ONLY ASBeautifier.cpp
   *
   * @param nonAssignmentOperators       a reference to the std::vector to be built.
   */
  void ASResource::buildNonAssignmentOperators(std::vector<const std::string*>* nonAssignmentOperators)
  {
    nonAssignmentOperators->push_back(&AS_EQUAL);
    nonAssignmentOperators->push_back(&AS_PLUS_PLUS);
    nonAssignmentOperators->push_back(&AS_MINUS_MINUS);
    nonAssignmentOperators->push_back(&AS_NOT_EQUAL);
    nonAssignmentOperators->push_back(&AS_GR_EQUAL);
    nonAssignmentOperators->push_back(&AS_GR_GR_GR);
    nonAssignmentOperators->push_back(&AS_GR_GR);
    nonAssignmentOperators->push_back(&AS_LS_EQUAL);
    nonAssignmentOperators->push_back(&AS_LS_LS_LS);
    nonAssignmentOperators->push_back(&AS_LS_LS);
    nonAssignmentOperators->push_back(&AS_ARROW);
    nonAssignmentOperators->push_back(&AS_AND);
    nonAssignmentOperators->push_back(&AS_OR);
    nonAssignmentOperators->push_back(&AS_EQUAL_GR);

    sort(nonAssignmentOperators->begin(), nonAssignmentOperators->end(), sortOnLength);
  }

  /**
   * Build the std::vector of header non-paren headers.
   * Used by BOTH ASFormatter.cpp and ASBeautifier.cpp.
   * NOTE: Non-paren headers should also be included in the headers std::vector.
   *
   * @param nonParenHeaders       a reference to the std::vector to be built.
   */
  void ASResource::buildNonParenHeaders(std::vector<const std::string*>* nonParenHeaders, std::int32_t fileType, bool beautifier)
  {
    nonParenHeaders->push_back(&AS_ELSE);
    nonParenHeaders->push_back(&AS_DO);
    nonParenHeaders->push_back(&AS_TRY);
    nonParenHeaders->push_back(&AS_CATCH);    // can be paren or non-paren
    nonParenHeaders->push_back(&AS_CASE);    // can be paren or non-paren
    nonParenHeaders->push_back(&AS_DEFAULT);

    if(fileType == C_TYPE)
    {
      nonParenHeaders->push_back(&_AS_TRY);    // __try
      nonParenHeaders->push_back(&_AS_FINALLY);  // __finally
    }

    if(fileType == JAVA_TYPE)
    {
      nonParenHeaders->push_back(&AS_FINALLY);
    }

    if(fileType == SHARP_TYPE)
    {
      nonParenHeaders->push_back(&AS_FINALLY);
      nonParenHeaders->push_back(&AS_GET);
      nonParenHeaders->push_back(&AS_SET);
      nonParenHeaders->push_back(&AS_ADD);
      nonParenHeaders->push_back(&AS_REMOVE);
    }

    if(beautifier)
    {
      if(fileType == C_TYPE)
      {
        nonParenHeaders->push_back(&AS_TEMPLATE);
      }

      if(fileType == JAVA_TYPE)
      {
        nonParenHeaders->push_back(&AS_STATIC);
      }
    }

    sort(nonParenHeaders->begin(), nonParenHeaders->end(), sortOnName);
  }

  /**
   * Build the std::vector of operators.
   * Used by ONLY ASFormatter.cpp
   *
   * @param operators             a reference to the std::vector to be built.
   */
  void ASResource::buildOperators(std::vector<const std::string*>* operators)
  {
    operators->push_back(&AS_PLUS_ASSIGN);
    operators->push_back(&AS_MINUS_ASSIGN);
    operators->push_back(&AS_MULT_ASSIGN);
    operators->push_back(&AS_DIV_ASSIGN);
    operators->push_back(&AS_MOD_ASSIGN);
    operators->push_back(&AS_OR_ASSIGN);
    operators->push_back(&AS_AND_ASSIGN);
    operators->push_back(&AS_XOR_ASSIGN);
    operators->push_back(&AS_EQUAL);
    operators->push_back(&AS_PLUS_PLUS);
    operators->push_back(&AS_MINUS_MINUS);
    operators->push_back(&AS_NOT_EQUAL);
    operators->push_back(&AS_GR_EQUAL);
    operators->push_back(&AS_GR_GR_GR_ASSIGN);
    operators->push_back(&AS_GR_GR_ASSIGN);
    operators->push_back(&AS_GR_GR_GR);
    operators->push_back(&AS_GR_GR);
    operators->push_back(&AS_LS_EQUAL);
    operators->push_back(&AS_LS_LS_LS_ASSIGN);
    operators->push_back(&AS_LS_LS_ASSIGN);
    operators->push_back(&AS_LS_LS_LS);
    operators->push_back(&AS_LS_LS);
    operators->push_back(&AS_QUESTION_QUESTION);
    operators->push_back(&AS_EQUAL_GR);
    operators->push_back(&AS_GCC_MIN_ASSIGN);
    operators->push_back(&AS_GCC_MAX_ASSIGN);
    operators->push_back(&AS_ARROW);
    operators->push_back(&AS_AND);
    operators->push_back(&AS_OR);
    operators->push_back(&AS_COLON_COLON);
    operators->push_back(&AS_PLUS);
    operators->push_back(&AS_MINUS);
    operators->push_back(&AS_MULT);
    operators->push_back(&AS_DIV);
    operators->push_back(&AS_MOD);
    operators->push_back(&AS_QUESTION);
    operators->push_back(&AS_COLON);
    operators->push_back(&AS_ASSIGN);
    operators->push_back(&AS_LS);
    operators->push_back(&AS_GR);
    operators->push_back(&AS_NOT);
    operators->push_back(&AS_BIT_OR);
    operators->push_back(&AS_BIT_AND);
    operators->push_back(&AS_BIT_NOT);
    operators->push_back(&AS_BIT_XOR);

    sort(operators->begin(), operators->end(), sortOnLength);
  }

  /**
   * Build the std::vector of pre-block statements.
   * Used by ONLY ASBeautifier.cpp
   * NOTE: Cannot be both a header and a preBlockStatement.
   *
   * @param preBlockStatements        a reference to the std::vector to be built.
   */
  void ASResource::buildPreBlockStatements(std::vector<const std::string*>* preBlockStatements, std::int32_t fileType)
  {
    preBlockStatements->push_back(&AS_CLASS);

    if(fileType == C_TYPE)
    {
      preBlockStatements->push_back(&AS_STRUCT);
      preBlockStatements->push_back(&AS_UNION);
      preBlockStatements->push_back(&AS_NAMESPACE);
    }

    if(fileType == JAVA_TYPE)
    {
      preBlockStatements->push_back(&AS_INTERFACE);
      preBlockStatements->push_back(&AS_THROWS);
    }

    if(fileType == SHARP_TYPE)
    {
      preBlockStatements->push_back(&AS_INTERFACE);
      preBlockStatements->push_back(&AS_NAMESPACE);
      preBlockStatements->push_back(&AS_WHERE);
      preBlockStatements->push_back(&AS_STRUCT);
    }

    sort(preBlockStatements->begin(), preBlockStatements->end(), sortOnName);
  }

  /**
   * Build the std::vector of pre-command headers.
   * Used by BOTH ASFormatter.cpp and ASBeautifier.cpp.
   * NOTE: Cannot be both a header and a preCommandHeader.
   *
   * A preCommandHeader is in a function definition between
   * the closing paren and the opening bracket.
   * e.g. in "void foo() const {}", "const" is a preCommandHeader.
   */
  void ASResource::buildPreCommandHeaders(std::vector<const std::string*>* preCommandHeaders, std::int32_t fileType)
  {
    if(fileType == C_TYPE)
    {
      preCommandHeaders->push_back(&AS_CONST);
      preCommandHeaders->push_back(&AS_VOLATILE);
      preCommandHeaders->push_back(&AS_SEALED);    // Visual C only
      preCommandHeaders->push_back(&AS_OVERRIDE);    // Visual C only
    }

    if(fileType == JAVA_TYPE)
    {
      preCommandHeaders->push_back(&AS_THROWS);
    }

    if(fileType == SHARP_TYPE)
    {
      preCommandHeaders->push_back(&AS_WHERE);
    }

    sort(preCommandHeaders->begin(), preCommandHeaders->end(), sortOnName);
  }

  /**
   * Build the std::vector of pre-definition headers.
   * Used by ONLY ASFormatter.cpp
   * NOTE: Do NOT add 'enum' here. It is an array type bracket.
   * NOTE: Do NOT add 'extern' here. Do not want an extra indent.
   *
   * @param preDefinitionHeaders      a reference to the std::vector to be built.
   */
  void ASResource::buildPreDefinitionHeaders(std::vector<const std::string*>* preDefinitionHeaders, std::int32_t fileType)
  {
    preDefinitionHeaders->push_back(&AS_CLASS);

    if(fileType == C_TYPE)
    {
      preDefinitionHeaders->push_back(&AS_STRUCT);
      preDefinitionHeaders->push_back(&AS_UNION);
      preDefinitionHeaders->push_back(&AS_NAMESPACE);
    }

    if(fileType == JAVA_TYPE)
    {
      preDefinitionHeaders->push_back(&AS_INTERFACE);
    }

    if(fileType == SHARP_TYPE)
    {
      preDefinitionHeaders->push_back(&AS_STRUCT);
      preDefinitionHeaders->push_back(&AS_INTERFACE);
      preDefinitionHeaders->push_back(&AS_NAMESPACE);
    }

    sort(preDefinitionHeaders->begin(), preDefinitionHeaders->end(), sortOnName);
  }

  /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
   *                             ASBase Funtions
   * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

// check if a specific line position contains a keyword.
  bool ASBase::findKeyword(const std::string& line, std::int32_t i, const std::string& keyword) const
  {
    assert(isCharPotentialHeader(line, i));
    // check the word
    const std::size_t keywordLength = keyword.length();
    const std::size_t wordEnd = i + keywordLength;

    if(wordEnd > line.length())
    {
      return false;
    }

    if(line.compare(i, keywordLength, keyword) != 0)
    {
      return false;
    }

    // check that this is not part of a longer word
    if(wordEnd == line.length())
    {
      return true;
    }

    if(isLegalNameChar(line[wordEnd]))
    {
      return false;
    }

    // is not a keyword if part of a definition
    const char peekChar = peekNextChar(line, wordEnd - 1);

    if(peekChar == ',' || peekChar == ')')
    {
      return false;
    }

    return true;
  }

// get the current word on a line
// index must point to the beginning of the word
  std::string ASBase::getCurrentWord(const std::string& line, std::size_t index) const
  {
    assert(isCharPotentialHeader(line, index));
    std::size_t lineLength = line.length();
    std::size_t i;

    for(i = index; i < lineLength; i++)
    {
      if(!isLegalNameChar(line[i]))
      {
        break;
      }
    }

    return line.substr(index, i - index);
  }

}   // end namespace astyle
