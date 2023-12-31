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
 * @param func		The symbol table record of the function into which the record
 * 					of the variable should be added
 * @param name		Name of the variable
 * @param width		The total memory size required for storing the variable data
 * @param offset	The offset of a variable from the base address of a function
 * @param dataType	The dataType of the variable
 * @param s			Value of the variable
 * @param line_num 	The line number of the source code where the variable is declared
 * @return updated symbol table
 */
void insertVarRecord(SymTableFunc * func, char* name, int width, int offset, astDataType dataType, SymDataType s, int line_num);

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
SymTableVar * fetchVarData(SymTableFunc * func, char* name, int line_num);

/**
 * Returns the Record for the parent function of a nested scope
 * @param local	The local symbol table of a function
 */
SymTableFunc * getParentFunc(SymTableFunc * local);

/**
 * @param func 	Symbol Table of the current local scope		
 * @param name 	name of the identifier to lookout for.
 * Returns 1 if any of the outer scope have a variable of the same name as 'name'
 */
int lookupDependentVar(SymTableFunc * func, char* name);

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
 * @param line_num		Line number of declaration
 *
 * @return updated Symbol Table after inserting the given record
 */
void addDataToFunction(SymTableFunc * funcData, char * fname, char* varName, astDataType varDataType, int line_num);

/**
 * Adds a new variable into the symbol table of variables associated with a function
 * @param funcData		The record of a function
 * @param fname 		Name of the module
 * @param varName		Name of the variable
 * @param lft 			AST Node of the lower bound of the array
 * @param right			AST Node of the upper bound of the array
 * @param varDataType	The dataType of the variable
 *
 * @return updated Symbol Table after inserting the given record
 */
void addArrToFunction(SymTableFunc * funcData, char * fname, char* varName, ASTNode * lft, ASTNode * right, astDataType varDataType);

/**
 * Inserts a given variable to the input list of a function
 * @param funcData		The record of a function
 * @param paramType		0 -> input, 1 -> output
 * @param varName		Name of the variable
 * @param varDataType	The dataType of the variable
 * @param line_num		Line number of parameter list
 * 
 * @return updated Symbol Table after inserting the record to the Input/Output parameters linked list
 */
void addParamToFunction(SymTableFunc* funcData, int paramType, char* varName, astDataType varDataType, int line_num);

/**
 * Inserts a given variable to the input list of a function
 * @param funcData		The record of a function
 * @param paramType		0 -> input, 1 -> output
 * @param lft 			AST Node of the lower bound of the array
 * @param right			AST Node of the upper bound of the array
 * @param varName		Name of the variable
 * @param varDataType	The dataType of the variable
 * 
 * @return updated Symbol Table after inserting the array record to the Input/Output parameters linked list
 */
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

/**
 * Prints all elements of a given symbol table
 * @param st			The symbol table to be printed
 * @param printElement	Function specifying how each element of
 * 						the symbol table should be printed
 */
void printSymbolTable(SymbolTable st, void (*printElement)(void*));

/**
 * Function to print the details of a variable in the symbol table
 * @param data	The data to be printed
 */
void printVar(void* data);

/**
 * Function to print the details of a function in the symbol table
 * @param data	The data to be printed
 */
void printFunc(void* data);

/**
 * Prints the entire Symbol Table of the source code
 * @param curr		The root node of the Abstract Syntax Tree
 * @param operation	The operation to perform:
 * 					0 --> Print Symbol Table
 * 					1 --> Print Array Type exprs and width
 */
void outputSymbolTable(ASTNode * curr, int operation);

/**
 * Prints the activation record sizes of all functions
 */
static inline void outputActivationRecords() {
	printSymbolTable(globalST, printFunc);
}

/**
 * Prints the array type expression and widths
 * @param curr	The root of current AST subtree
 */
static inline void outputArrayExprs(ASTNode* curr) {
	outputSymbolTable(curr, 1);
}

#endif