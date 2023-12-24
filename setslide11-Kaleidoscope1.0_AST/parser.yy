%skeleton "lalr1.cc" /* -*- C++ -*- */
%require "3.2"
%defines

%define api.token.constructor
%define api.location.file none
%define api.value.type variant
%define parse.assert
%define parse.trace
%define parse.error verbose

%code requires {
  # include <string>
  #include <exception>
  class driver;
  class RootAST;
  class ExprAST;
  class FunctionAST;
  class SeqAST;
  class PrototypeAST;
}

/* Argomento addizionale per il parser. Si ricordi che
   (nel file driver.hpp) è stata definita la stessa
   segnatura anche per yylex */
%param { driver& drv }

/* Genera il codice (lato parser) per trattare le location
   e permettere la generazione di messaggi di errore più
   accurati */
%locations

%code {
# include "driver.hpp"
}

%define api.token.prefix {TOK_}
%token
  END  0  "end of file"
  SEMICOLON  ";"
  COMMA      ","
  MINUS      "-"
  PLUS       "+"
  STAR       "*"
  SLASH      "/"
  LPAREN     "("
  RPAREN     ")"
  EXTERN     "extern"
  DEF        "def"
;

%token <std::string> IDENTIFIER "id"
%token <double> NUMBER "number"
%type <ExprAST*> exp
%type <ExprAST*> idexp
%type <std::vector<ExprAST*>> optexp
%type <std::vector<ExprAST*>> explist
%type <RootAST*> program
%type <ExprAST> exprif //aggiunto
%type <ExprAST> condexpr //aggiunto
%type <RootAST*> top
%type <FunctionAST*> definition
%type <PrototypeAST*> external
%type <PrototypeAST*> proto
%type <std::vector<std::string>> idseq
%type <BlockExprAst*> blockexp
%type <std::vector<VarBindingsAST*>> vardefs
%type <VarBindingsAST*> binding 

%%
%start startsymb;

startsymb:
program             { drv.root = $1; }

program:
  %empty               { $$ = new SeqAST(nullptr,nullptr); }
|  top ";" program     { $$ = new SeqAST($1,$3); };

top:
%empty                 { $$ = nullptr; }
| definition           { $$ = $1; }
| external             { $$ = $1; }
| exp                  { $$ = $1; };

definition:
  "def" proto exp      { $$ = new FunctionAST($2,$3); };

external:
  "extern" proto       { $$ = $2; };

proto:
  "id" "(" idseq ")"   { $$ = new PrototypeAST($1,$3); };

idseq:
  %empty               { std::vector<std::string> args;
                         $$ = args; }
| "id" idseq           { $2.insert($2.begin(),$1); $$ = $2; };


%left "+" "-";
%left "*" "/";

exp:
  exp "+" exp          { $$ = new BinaryExprAST('+',$1,$3); }
| exp "-" exp          { $$ = new BinaryExprAST('-',$1,$3); }
| exp "*" exp          { $$ = new BinaryExprAST('*',$1,$3); }
| exp "/" exp          { $$ = new BinaryExprAST('/',$1,$3); }
| idexp                { $$ = $1; }
| "(" exp ")"          { $$ = $2; }
| "number"             { $$ = new NumberExprAST($1); };
| exprif               { $$ = $1;}
blockexp               { $$ = $1;}

blockexp:
"{" vardefs ";" exp "}" { $$ = new BlockExprAst($2,$4);}

//binding = legame, leghiamo il nome al identificatore, 
vardefs:
  binding { std::vector<VarBindingsAST *> definitions:
            definitinois.push_back($1);
            $$ = definitinois; }
  vardefs ";" binding  { $1.push_back($3);
                      $$ = $1;}

binding: 
  "var" "id" "=" exp { $$ = new VarBindingsAST($2,$4);}

exprif:

//creaiamo una nuova classe expressione condizionale
//costruiamo l'albero
//come si definisce un oggetto tipo: x<1 ? 1 : 2
condexpr "?" exp ":" exp { $$ = New IfExprAST($1,$3,$5); } 

condexpr:
  expr "<" exp { $$ = new BinaryExprAST('<',$1,$3); }
  exp "=" exp  { $$ = new BinaryExprAST('=',$1,$3); }





idexp:
  "id"                 { $$ = new VariableExprAST($1); }
| "id" "(" optexp ")"  { $$ = new CallExprAST($1,$3); };

optexp:
%empty                 { std::vector<ExprAST*> args;
                         args.push_back(nullptr);
			 $$ = args;
                       }
| explist              { $$ = $1; };

explist:
  exp                  { std::vector<ExprAST*> args;
                         args.push_back($1);
			 $$ = args;
                       }
| exp "," explist      { $3.insert($3.begin(), $1); $$ = $3; };

%%

void
yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
