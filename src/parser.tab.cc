// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


// First part of user declarations.

#line 37 "parser.tab.cc" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "parser.tab.hh"

// User implementation prologue.

#line 51 "parser.tab.cc" // lalr1.cc:412
// Unqualified %code blocks.
#line 29 "parser.yy" // lalr1.cc:413

#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

#include "Driver.hpp"

#undef yylex
#define yylex scanner.yylex

#line 65 "parser.tab.cc" // lalr1.cc:413


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 5 "parser.yy" // lalr1.cc:479
namespace C0 {
#line 151 "parser.tab.cc" // lalr1.cc:479

  /// Build a parser object.
  Parser::Parser (Scanner  &scanner_yyarg, Driver  &driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      scanner (scanner_yyarg),
      driver (driver_yyarg)
  {}

  Parser::~Parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/

  inline
  Parser::syntax_error::syntax_error (const location_type& l, const std::string& m)
    : std::runtime_error (m)
    , location (l)
  {}

  // basic_symbol.
  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
    , location (other.location)
  {
      switch (other.type_get ())
    {
      case 3: // ID
      case 4: // NUMERO
      case 5: // STRING
        value.copy< std::string > (other.value);
        break;

      default:
        break;
    }

  }


  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {
    (void) v;
      switch (this->type_get ())
    {
      case 3: // ID
      case 4: // NUMERO
      case 5: // STRING
        value.copy< std::string > (v);
        break;

      default:
        break;
    }
}


  // Implementation of basic_symbol constructor for each type.

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::string v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}


  template <typename Base>
  inline
  Parser::basic_symbol<Base>::~basic_symbol ()
  {
    clear ();
  }

  template <typename Base>
  inline
  void
  Parser::basic_symbol<Base>::clear ()
  {
    // User destructor.
    symbol_number_type yytype = this->type_get ();
    basic_symbol<Base>& yysym = *this;
    (void) yysym;
    switch (yytype)
    {
   default:
      break;
    }

    // Type destructor.
    switch (yytype)
    {
      case 3: // ID
      case 4: // NUMERO
      case 5: // STRING
        value.template destroy< std::string > ();
        break;

      default:
        break;
    }

    Base::clear ();
  }

  template <typename Base>
  inline
  bool
  Parser::basic_symbol<Base>::empty () const
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  inline
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
      switch (this->type_get ())
    {
      case 3: // ID
      case 4: // NUMERO
      case 5: // STRING
        value.move< std::string > (s.value);
        break;

      default:
        break;
    }

    location = s.location;
  }

  // by_type.
  inline
  Parser::by_type::by_type ()
    : type (empty_symbol)
  {}

  inline
  Parser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  Parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  Parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
  Parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  inline
  int
  Parser::by_type::type_get () const
  {
    return type;
  }
  // Implementation of make_symbol for each symbol type.
  Parser::symbol_type
  Parser::make_ID (const std::string& v, const location_type& l)
  {
    return symbol_type (token::ID, v, l);
  }

  Parser::symbol_type
  Parser::make_NUMERO (const std::string& v, const location_type& l)
  {
    return symbol_type (token::NUMERO, v, l);
  }

  Parser::symbol_type
  Parser::make_STRING (const std::string& v, const location_type& l)
  {
    return symbol_type (token::STRING, v, l);
  }

  Parser::symbol_type
  Parser::make_IF (const location_type& l)
  {
    return symbol_type (token::IF, l);
  }

  Parser::symbol_type
  Parser::make_WHILE (const location_type& l)
  {
    return symbol_type (token::WHILE, l);
  }

  Parser::symbol_type
  Parser::make_PRINT (const location_type& l)
  {
    return symbol_type (token::PRINT, l);
  }

  Parser::symbol_type
  Parser::make_BREAK (const location_type& l)
  {
    return symbol_type (token::BREAK, l);
  }

  Parser::symbol_type
  Parser::make_FUNC (const location_type& l)
  {
    return symbol_type (token::FUNC, l);
  }

  Parser::symbol_type
  Parser::make_INT (const location_type& l)
  {
    return symbol_type (token::INT, l);
  }

  Parser::symbol_type
  Parser::make_VOID (const location_type& l)
  {
    return symbol_type (token::VOID, l);
  }

  Parser::symbol_type
  Parser::make_RETURN (const location_type& l)
  {
    return symbol_type (token::RETURN, l);
  }

  Parser::symbol_type
  Parser::make_STRUCT (const location_type& l)
  {
    return symbol_type (token::STRUCT, l);
  }

  Parser::symbol_type
  Parser::make_LKEY (const location_type& l)
  {
    return symbol_type (token::LKEY, l);
  }

  Parser::symbol_type
  Parser::make_RKEY (const location_type& l)
  {
    return symbol_type (token::RKEY, l);
  }

  Parser::symbol_type
  Parser::make_PYC (const location_type& l)
  {
    return symbol_type (token::PYC, l);
  }

  Parser::symbol_type
  Parser::make_COMA (const location_type& l)
  {
    return symbol_type (token::COMA, l);
  }

  Parser::symbol_type
  Parser::make_ASIG (const location_type& l)
  {
    return symbol_type (token::ASIG, l);
  }

  Parser::symbol_type
  Parser::make_OR (const location_type& l)
  {
    return symbol_type (token::OR, l);
  }

  Parser::symbol_type
  Parser::make_AND (const location_type& l)
  {
    return symbol_type (token::AND, l);
  }

  Parser::symbol_type
  Parser::make_EQUAL (const location_type& l)
  {
    return symbol_type (token::EQUAL, l);
  }

  Parser::symbol_type
  Parser::make_DISTINCT (const location_type& l)
  {
    return symbol_type (token::DISTINCT, l);
  }

  Parser::symbol_type
  Parser::make_LT (const location_type& l)
  {
    return symbol_type (token::LT, l);
  }

  Parser::symbol_type
  Parser::make_GT (const location_type& l)
  {
    return symbol_type (token::GT, l);
  }

  Parser::symbol_type
  Parser::make_LTE (const location_type& l)
  {
    return symbol_type (token::LTE, l);
  }

  Parser::symbol_type
  Parser::make_GTE (const location_type& l)
  {
    return symbol_type (token::GTE, l);
  }

  Parser::symbol_type
  Parser::make_MAS (const location_type& l)
  {
    return symbol_type (token::MAS, l);
  }

  Parser::symbol_type
  Parser::make_MENOS (const location_type& l)
  {
    return symbol_type (token::MENOS, l);
  }

  Parser::symbol_type
  Parser::make_MUL (const location_type& l)
  {
    return symbol_type (token::MUL, l);
  }

  Parser::symbol_type
  Parser::make_DIV (const location_type& l)
  {
    return symbol_type (token::DIV, l);
  }

  Parser::symbol_type
  Parser::make_MOD (const location_type& l)
  {
    return symbol_type (token::MOD, l);
  }

  Parser::symbol_type
  Parser::make_LCOR (const location_type& l)
  {
    return symbol_type (token::LCOR, l);
  }

  Parser::symbol_type
  Parser::make_RCOR (const location_type& l)
  {
    return symbol_type (token::RCOR, l);
  }

  Parser::symbol_type
  Parser::make_NOT (const location_type& l)
  {
    return symbol_type (token::NOT, l);
  }

  Parser::symbol_type
  Parser::make_DOT (const location_type& l)
  {
    return symbol_type (token::DOT, l);
  }

  Parser::symbol_type
  Parser::make_LPAR (const location_type& l)
  {
    return symbol_type (token::LPAR, l);
  }

  Parser::symbol_type
  Parser::make_RPAR (const location_type& l)
  {
    return symbol_type (token::RPAR, l);
  }

  Parser::symbol_type
  Parser::make_IFX (const location_type& l)
  {
    return symbol_type (token::IFX, l);
  }

  Parser::symbol_type
  Parser::make_ELSE (const location_type& l)
  {
    return symbol_type (token::ELSE, l);
  }



  // by_state.
  inline
  Parser::by_state::by_state ()
    : state (empty_state)
  {}

  inline
  Parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  Parser::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
  Parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  Parser::symbol_number_type
  Parser::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  inline
  Parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  Parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
      switch (that.type_get ())
    {
      case 3: // ID
      case 4: // NUMERO
      case 5: // STRING
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

  inline
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
      switch (that.type_get ())
    {
      case 3: // ID
      case 4: // NUMERO
      case 5: // STRING
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
  Parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  Parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  Parser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            yyla.type = yytranslate_ (yylex (&yyla.value, &yyla.location));
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
        switch (yyr1_[yyn])
    {
      case 3: // ID
      case 4: // NUMERO
      case 5: // STRING
        yylhs.value.build< std::string > ();
        break;

      default:
        break;
    }


      // Compute the default @$.
      {
        slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, slice, yylen);
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {

#line 911 "parser.tab.cc" // lalr1.cc:859
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    yyerror_range[1].location = yystack_[yylen - 1].location;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (state_type, const symbol_type&) const
  {
    return YY_("syntax error");
  }


  const short int Parser::yypact_ninf_ = -131;

  const signed char Parser::yytable_ninf_ = -1;

  const short int
  Parser::yypact_[] =
  {
    -131,     4,    85,  -131,    -3,  -131,  -131,    -9,  -131,  -131,
      14,   -12,  -131,    22,  -131,    36,    -3,  -131,    58,  -131,
      21,  -131,  -131,     7,    60,    18,  -131,  -131,    14,    34,
      -3,    89,    14,  -131,  -131,   -12,   120,    87,   121,  -131,
    -131,    98,  -131,  -131,   125,    -3,  -131,  -131,  -131,   135,
      15,   108,   113,   114,   139,    16,   154,  -131,   142,   146,
    -131,  -131,  -131,  -131,  -131,  -131,   152,  -131,  -131,  -131,
      16,   169,    16,   140,     8,     8,    10,  -131,   156,  -131,
      16,    50,  -131,   104,  -131,  -131,  -131,    16,    73,  -131,
     136,   163,  -131,   155,    16,     8,     8,   105,     3,    39,
     150,   132,   187,    16,  -131,   140,   137,  -131,    16,    16,
      16,    16,    16,  -131,   154,    81,  -131,   174,    16,   148,
    -131,    62,    45,    16,    16,    16,    16,    16,    16,     8,
       8,   111,   111,   177,   178,  -131,   158,  -131,     6,     6,
    -131,  -131,  -131,  -131,  -131,  -131,  -131,  -131,  -131,   155,
     155,   155,   155,   155,   155,   176,  -131,   146,  -131,   159,
    -131,  -131,  -131,  -131,   182,   111,  -131,  -131,  -131
  };

  const unsigned char
  Parser::yydefact_[] =
  {
       4,     0,     0,     1,     0,    12,    13,     0,     3,     5,
       0,    15,     6,     2,    21,     0,     0,    10,     0,     9,
       0,    11,    20,     0,     0,     0,    18,     7,     0,     0,
      24,     0,     0,    17,     8,    15,     0,     0,    23,    26,
      19,     0,    14,    27,     0,     0,    16,    29,    25,    35,
      84,     0,     0,     0,     0,     0,     0,    28,     0,    34,
      37,    45,    44,    38,    39,    40,     0,    41,    42,    43,
       0,     0,    49,    85,     0,     0,     0,    89,    64,    59,
       0,     0,    33,     0,    32,    22,    36,     0,     0,    86,
       0,    48,    51,    52,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    49,    60,    62,     0,    46,     0,     0,
       0,     0,     0,    30,     0,     0,    66,     0,     0,     0,
      75,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    61,     0,    58,    53,    54,
      55,    56,    57,    31,    83,    47,    50,    65,    76,    69,
      70,    72,    71,    74,    73,    67,    68,    35,    81,    79,
      82,    88,    87,    63,     0,     0,    77,    80,    78
  };

  const short int
  Parser::yypgoto_[] =
  {
    -131,  -131,  -131,  -131,  -131,   168,   173,  -131,     1,   167,
    -131,  -131,   179,  -131,   190,  -131,  -131,   160,  -131,  -131,
    -131,    92,    51,  -131,   -49,  -131,  -131,   106,  -131,    93,
     -54,  -131,   129,   -68,  -131,  -131,  -130,  -131,  -131,  -131,
    -131,  -131,  -131
  };

  const short int
  Parser::yydefgoto_[] =
  {
      -1,     1,     2,     8,     9,    18,    19,    10,    24,    21,
      12,    25,    26,    13,    14,    37,    38,    39,    49,    57,
      83,    84,    58,    59,   158,    61,    62,    90,    91,    92,
      97,   104,    73,    98,    63,   166,   159,    64,    65,    66,
      67,    68,    69
  };

  const unsigned char
  Parser::yytable_[] =
  {
      60,    81,   160,    11,     3,    15,    16,    99,     5,     6,
      86,    78,    79,    78,    79,   100,    88,    17,    93,    78,
      79,    20,   101,   129,   130,    29,   106,   120,   122,     5,
       6,    36,     4,   115,    32,   168,   110,   111,   112,    23,
     119,   131,   121,    95,    30,    96,    36,    80,    70,    93,
      56,    71,    72,    80,   138,   139,   140,   141,   142,   129,
     130,   155,   156,    31,    93,   129,   130,   107,    35,   149,
     150,   151,   152,   153,   154,    27,    28,   132,   108,   109,
     110,   111,   112,   148,   123,   124,   125,   126,   127,   128,
     108,   109,   110,   111,   112,     4,     5,     6,   144,     7,
     137,   108,   109,   110,   111,   112,    40,   116,    60,   108,
     109,   110,   111,   112,    50,    46,    28,    51,    52,    53,
      54,   113,   114,    43,    55,    44,   157,   123,   124,   125,
     126,   127,   128,   108,   109,   110,   111,   112,    50,    45,
      47,    51,    52,    53,    54,    74,     5,     6,    55,    50,
      75,    76,    51,    52,    53,    54,    77,    82,    85,    55,
     108,   109,   110,   111,   112,   108,   109,   110,   111,   112,
     134,    87,    89,    94,   117,   137,   108,   109,   110,   111,
     112,   118,   147,   108,   109,   110,   111,   112,   133,    70,
     135,   145,   102,   103,   161,   162,   163,   130,   167,   165,
      41,    34,    42,    22,    33,    48,   143,   105,   164,   136,
       0,   146
  };

  const short int
  Parser::yycheck_[] =
  {
      49,    55,   132,     2,     0,     4,    15,    75,    11,    12,
      59,     3,     4,     3,     4,     5,    70,     3,    72,     3,
       4,    33,    76,    20,    21,     4,    80,    95,    96,    11,
      12,    30,    10,    87,    16,   165,    30,    31,    32,     3,
      94,    38,    96,    35,    37,    37,    45,    37,    33,   103,
      49,    36,    37,    37,   108,   109,   110,   111,   112,    20,
      21,   129,   130,     3,   118,    20,    21,    17,    34,   123,
     124,   125,   126,   127,   128,    17,    18,    38,    28,    29,
      30,    31,    32,    38,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    10,    11,    12,    17,    14,
      38,    28,    29,    30,    31,    32,    17,    34,   157,    28,
      29,    30,    31,    32,     3,    17,    18,     6,     7,     8,
       9,    17,    18,     3,    13,    38,    15,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,     3,    18,
      15,     6,     7,     8,     9,    37,    11,    12,    13,     3,
      37,    37,     6,     7,     8,     9,    17,     3,    16,    13,
      28,    29,    30,    31,    32,    28,    29,    30,    31,    32,
      38,    19,     3,    33,    38,    38,    28,    29,    30,    31,
      32,    18,    34,    28,    29,    30,    31,    32,    38,    33,
       3,    17,    36,    37,    17,    17,    38,    21,    16,    40,
      32,    28,    35,    13,    25,    45,   114,    78,   157,   103,
      -1,   118
  };

  const unsigned char
  Parser::yystos_[] =
  {
       0,    42,    43,     0,    10,    11,    12,    14,    44,    45,
      48,    49,    51,    54,    55,    49,    15,     3,    46,    47,
      33,    50,    55,     3,    49,    52,    53,    17,    18,     4,
      37,     3,    16,    53,    47,    34,    49,    56,    57,    58,
      17,    46,    50,     3,    38,    18,    17,    15,    58,    59,
       3,     6,     7,     8,     9,    13,    49,    60,    63,    64,
      65,    66,    67,    75,    78,    79,    80,    81,    82,    83,
      33,    36,    37,    73,    37,    37,    37,    17,     3,     4,
      37,    71,     3,    61,    62,    16,    65,    19,    71,     3,
      68,    69,    70,    71,    33,    35,    37,    71,    74,    74,
       5,    71,    36,    37,    72,    73,    71,    17,    28,    29,
      30,    31,    32,    17,    18,    71,    34,    38,    18,    71,
      74,    71,    74,    22,    23,    24,    25,    26,    27,    20,
      21,    38,    38,    38,    38,     3,    68,    38,    71,    71,
      71,    71,    71,    62,    17,    17,    70,    34,    38,    71,
      71,    71,    71,    71,    71,    74,    74,    15,    65,    77,
      77,    17,    17,    38,    63,    40,    76,    16,    77
  };

  const unsigned char
  Parser::yyr1_[] =
  {
       0,    41,    42,    43,    43,    44,    44,    45,    46,    46,
      47,    48,    49,    49,    50,    50,    51,    52,    52,    53,
      54,    54,    55,    56,    56,    57,    57,    58,    59,    59,
      60,    61,    61,    62,    63,    63,    64,    64,    65,    65,
      65,    65,    65,    65,    65,    65,    66,    67,    68,    68,
      69,    69,    70,    71,    71,    71,    71,    71,    71,    71,
      71,    72,    72,    72,    72,    73,    73,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    75,    76,    76,
      77,    77,    78,    79,    80,    80,    80,    81,    82,    83
  };

  const unsigned char
  Parser::yyr2_[] =
  {
       0,     2,     2,     2,     0,     1,     1,     3,     3,     1,
       1,     2,     1,     1,     4,     0,     6,     2,     1,     3,
       2,     1,    10,     1,     0,     3,     1,     2,     2,     0,
       3,     3,     1,     1,     1,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     5,     1,     0,
       3,     1,     1,     3,     3,     3,     3,     3,     3,     1,
       2,     2,     1,     3,     0,     4,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     3,     6,     2,     0,
       3,     1,     5,     4,     1,     2,     3,     5,     5,     2
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "$end", "error", "$undefined", "ID", "NUMERO", "STRING", "IF", "WHILE",
  "PRINT", "BREAK", "FUNC", "INT", "VOID", "RETURN", "STRUCT", "LKEY",
  "RKEY", "PYC", "COMA", "ASIG", "OR", "AND", "EQUAL", "DISTINCT", "LT",
  "GT", "LTE", "GTE", "MAS", "MENOS", "MUL", "DIV", "MOD", "LCOR", "RCOR",
  "NOT", "DOT", "LPAR", "RPAR", "IFX", "ELSE", "$accept", "program",
  "declarations", "declaration", "decl_var", "list_var", "var", "type",
  "base", "arreglo", "decl_struct", "body_struct", "def_mem", "functions",
  "function", "list_args", "args", "arg", "local_decls", "local_decl",
  "local_list", "local", "bloqueSentencias", "sentencias", "sentencia",
  "sentReturn", "sentProc", "list_params", "params", "param", "expresion",
  "complemento", "array", "condicion", "sentIf", "sentElse",
  "bloqueOSentencia", "sentWhile", "sentAsig", "left_part", "sentPutw",
  "sentPuts", "sentBreak", YY_NULLPTR
  };


  const unsigned short int
  Parser::yyrline_[] =
  {
       0,    71,    71,    77,    79,    84,    86,    91,    96,    97,
     102,   107,   112,   114,   118,   120,   125,   130,   132,   137,
     142,   144,   149,   153,   155,   160,   162,   167,   172,   174,
     179,   184,   186,   191,   196,   198,   203,   205,   210,   212,
     214,   216,   218,   220,   222,   224,   228,   233,   238,   240,
     245,   247,   251,   256,   258,   260,   262,   264,   266,   268,
     270,   275,   277,   279,   281,   286,   288,   293,   295,   297,
     299,   301,   303,   305,   307,   309,   311,   315,   323,   325,
     330,   332,   337,   345,   350,   352,   354,   359,   365,   370
  };

  // Print the state stack on the debug stream.
  void
  Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  Parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  // Symbol number corresponding to token number t.
  inline
  Parser::token_number_type
  Parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
     0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40
    };
    const unsigned int user_token_number_max_ = 295;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }

#line 5 "parser.yy" // lalr1.cc:1167
} // C0
#line 1368 "parser.tab.cc" // lalr1.cc:1167
#line 374 "parser.yy" // lalr1.cc:1168


void C0::Parser::error( const location_type &l, const std::string &err_message )
{
    cerr << "Error: " << err_message << " at " << l << endl;
}
