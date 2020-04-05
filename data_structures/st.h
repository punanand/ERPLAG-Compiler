/*  GROUP 48:
  PUNEET ANAND    2016B4A70487P
  MAYANK JASORIA  2016B1A70703P
  SHUBHAM TIWARI  2016B4A70935P
  VIBHAV OSWAL    2016B4A70594P */

#ifndef _SYMBOL_TABLE
#define _SYMBOL_TABLE

#include "astDef.h"


/**
* Creates and returns an instance of a new symbol table
* @return an instance of a new symbol table
*/
SymbolTable getSymbolTable();

/**
* Inserts a record for a variable into the symbol table
* @param st			The symbol table into which the variable record should be added
* @param name		Name of the variable
* @param width		The total memory size required for storing the variable data
* @param offset		The offset of a variable from the base address of a function
* @param dataType	The dataType of the variable
* 
* @return updated symbol table
*/
void insertVarRecord(SymbolTable st, char* name, int width, int offset, astDataType dataType);

/**
* Inserts a record for a function into the symbol table
* @param st		The symbol table in which the function record should be added
* @param name	The name of the function
* 
* @return updated symbol table
*/
SymTableFunc * insertFuncRecord(char* name);

/**
* Returns the record for a variable from the symbol table,
* if it exists. Otherwise returns NULL
* @param st	The symbol table from which the variable is to be fetched
* @param name	The name of the variable
* 
* @return pointer to the record if it is found, otherwise NULL
*/
SymTableVar * fetchVarData(SymTableFunc * func, char* name);

/**
* Returns the record for a function from the symbol table,
* if it exists. Otherwise returns NULL
* @param name	The name of the function
* 
* @return pointer to the record if it is found, otherwise NULL
*/
SymTableFunc* fetchFuncData(char* name);

/**
* Creates a record for an inner score, along with a new symbol table
* @param fname Name of the function
* 
* @return pointer to the newly created record
*/
SymTableFunc * getFuncTable(char * fname, SymTableFunc * par);

/**
* Adds a new variable into the symbol table of variables associated with a function
* @param funcData		The record of a function
* @param varName		Name of the variable
* @param varDataType	The dataType of the variable
* 
* @return updated Symbol Table
*/
void addDataToFunction(SymTableFunc * funcData, char * fname, char* varName, astDataType varDataType);

void addArrToFunction(SymTableFunc * funcData, char * fname, char* varName, ASTNode * lft, ASTNode * right, astDataType varDataType);

/**
* Inserts a given variable to the input list of a function
* @param funcData		The record of a function
* @param paramType		0 -> input, 1 -> output
* @param varName		Name of the variable
* @param varDataType	The dataType of the variable
* 
* @return updated Symbol Table
*/
void addParamToFunction(SymTableFunc* funcData, int paramType, char* varName, astDataType varDataType);

void addArrParamToFunction(SymTableFunc * funcData, int paramType, char* varName, ASTNode * lft, ASTNode * right, astDataType varDataType);

/**
* Given a width, updates the activation record size of a function
* (to be used when adding a variable to a child scope of a function)
* @param st		The Symbol Table
* @param funcName	The name of the function
* @param varWidth	The width of the variable
* 
* @return updated symbol table
*/
SymbolTable updateOffsetOfFunc(SymbolTable st, char* funcName, int varWidth);

#endif