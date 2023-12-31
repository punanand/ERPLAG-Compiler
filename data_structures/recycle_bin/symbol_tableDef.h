/*  GROUP 48:
	PUNEET ANAND    2016B4A70487P
	MAYANK JASORIA  2016B1A70703P
	SHUBHAM TIWARI  2016B4A70935P
	VIBHAV OSWAL    2016B4A70594P */

#ifndef _SYMBOL_TABLE_DEF
#define _SYMBOL_TABLE_DEF

#include "hash_map.h"
#include "linked_list.h"
#include "astDef.h"

/* defining a symbol table */
typedef HashTable SymbolTable;

SymbolTable globalST;

typedef enum {
	SYM_VARIABLE,
	SYM_FUNCTION,
	SYM_OTHER
} SymTableType;

typedef struct arrayInfo {
	astDataType dataType; 
	int low;
	int high;
	char* lowId;
	char* highId;
} arrayInfo;

typedef union {
	arrayInfo r;	
	int intVal;
	float floatVal;
	int boolVal:1;
} SymDataType;

typedef struct SymTableFunc {
	SymTableType type;

	/* For the pointer to the static parent of the scope. */
	struct SymTableFunc * par;
	
	/* base address of the fuction activation record. */
	int baseAdd;
	
	// name of the function
	char* name;

	/* List of input parameter variables */
	List input_plist;

	/* List of output parameter variables */
	List output_plist; 
	
	/* symbol table associated with the local elements of this function */
	SymbolTable dataTable; // it contains entries of type SymTableVar
	
	/* field for storing activation record size */
	int actRecSize;
} SymTableFunc;

typedef struct symTableVar {	
	SymTableType type;
	char* name;

	/* total memory space to be allocated */
	int width;
	
	/* Stores the offset of the variable from base */
	int offset;

	/**
	 * flag to store if the variable was assigned a value or not 
	 * 0 -> not yet assigned, 1 -> assigned
	 */
	unsigned int isAssigned:1;

	/* datatype of variable -> INT, RNUM, BOOL (optionally define a new enum) */
	astDataType dataType;
	SymDataType sdt;
} SymTableVar;

#endif