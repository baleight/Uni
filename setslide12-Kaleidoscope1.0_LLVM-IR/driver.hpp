#ifndef DRIVER_HPP
#define DRIVER_HPP
/************ Header file per la generazione del codice oggetto *************/
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/Support/Host.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/Target/TargetOptions.h"
#include "llvm/IR/LegacyPassManager.h"
/***************************************************************************/
#include "llvm/ADT/APFloat.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Verifier.h"

#include "llvm/Transforms/InstCombine/InstCombine.h"
#include "llvm/Transforms/Scalar.h"
#include "llvm/Transforms/Scalar/GVN.h"
#include "llvm/Transforms/Utils.h"
#include <optional>
#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <memory>
#include <string>
#include <vector>
#include <variant>
#include "parser.hpp"
//classe per passare il contesto

using namespace llvm;

// Dichiarazione del prototipo yylex per Flex
// Flex va proprio a cercare YY_DECL perché
// deve espanderla (usando M4) nel punto appropriato
# define YY_DECL \
  yy::parser::symbol_type yylex (driver& drv)
// Per il parser è sufficiente una forward declaration
YY_DECL;

// Classe che organizza e gestisce il processo di compilazione
class driver
{
public:
  driver();
  std::map<std::string, AllocaInst *> NamedValues; // Tabella associativa in cui le
            // chiavi sono (nomi di) variabili e i valori sono 
  static inline int Cnt=0; //Contatore incrementale, per identificare registri SSA
  RootAST* root;//quando fa l'ultima riduzione viene passato dal parser      // A fine parsing "punta" alla radice dell'AST
  int parse (const std::string& f); //funzione che chiama il parser, f sara il file del programma
  std::string file; //salvato nella variabile file
  bool trace_parsing; // Abilita le tracce di debug el parser, inizializzato a false
  void scan_begin (); // Implementata nello scanner, aperto del file
  void scan_end ();   // Implementata nello scanner, chiusura del file
  bool trace_scanning;// Abilita le tracce di debug nello scanner
  yy::location location; // Utillizata dallo scannar per localizzare i token, serve per tenere traccia dove sono i token nel caso di errori
  void codegen(); //visit e' stato sostituito da cogen, che serve per generare codice, ogni classe ha il suo codgen(una che produce il codice, una che fa la variabile..)
};

typedef std::variant<std::string,double> lexval;
const lexval NONE = 0.0;

//sparisce la funzione visit e arriva codgen

// Classe base dell'intera gerarchia di classi che rappresentano
// gli elementi del programma
class RootAST {
public:
  virtual ~RootAST() {};
  virtual lexval getLexVal() const {return NONE;};
  virtual Value *codegen(driver& drv) { return nullptr; };
};

// Classe che rappresenta la sequenza di statement
class SeqAST : public RootAST {
private:
  RootAST* first;
  RootAST* continuation;

public:
  SeqAST(RootAST* first, RootAST* continuation);
  Value *codegen(driver& drv) override;
};

/// ExprAST - Classe base per tutti i nodi espressione
class ExprAST : public RootAST {};

/// NumberExprAST - Classe per la rappresentazione di costanti numeriche
class NumberExprAST : public ExprAST {
private:
  double Val;

public:
  NumberExprAST(double Val);
  lexval getLexVal() const override;
  Value *codegen(driver& drv) override;
};

/// VariableExprAST - Classe per la rappresentazione di riferimenti a variabili
class VariableExprAST : public ExprAST {
private:
  std::string Name;
  
public:
  VariableExprAST(const std::string &Name);
  lexval getLexVal() const override;
  Value *codegen(driver& drv) override;
};

/// BinaryExprAST - Classe per la rappresentazione di operatori binari
class BinaryExprAST : public ExprAST {
private:
  char Op;
  ExprAST* LHS;
  ExprAST* RHS;

public:
  BinaryExprAST(char Op, ExprAST* LHS, ExprAST* RHS);
  Value *codegen(driver& drv) override;
};

/// CallExprAST - Classe per la rappresentazione di chiamate di funzione
class CallExprAST : public ExprAST {
private:
  std::string Callee;
  std::vector<ExprAST*> Args;  // ASTs per la valutazione degli argomenti

public:
  CallExprAST(std::string Callee, std::vector<ExprAST*> Args);
  lexval getLexVal() const override;
  Value *codegen(driver& drv) override;
};

/// PrototypeAST - Classe per la rappresentazione dei prototipi di funzione
/// (nome, numero e nome dei parametri; in questo caso il tipo è implicito
/// perché unico)
class PrototypeAST : public RootAST {
private:
  std::string Name;
  std::vector<std::string> Args;
  bool emitcode;

public:
  PrototypeAST(std::string Name, std::vector<std::string> Args);
  const std::vector<std::string> &getArgs() const;
  lexval getLexVal() const override;
  Function *codegen(driver& drv) override;
  void noemit();
};

/// FunctionAST - Classe che rappresenta la definizione di una funzione
class FunctionAST : public RootAST {
private:
  PrototypeAST* Proto;
  ExprAST* Body;
  bool external;
  
public:
  FunctionAST(PrototypeAST* Proto, ExprAST* Body);
  Function *codegen(driver& drv) override;
};

#endif // ! DRIVER_HH

//VarBindingAST
VarBindingAST: public RootAST{
  private:
    std::string Name:
    ExprAST* Val;
public: //simboltable ci sono le istruzioni per loc, pescare nei registi il valore di alloca
  VarBindingAST(std:: string Name, ExprAST* Val);
  AllocaInst *codegen(driven& drv) override;
  std::string& getName();

}
