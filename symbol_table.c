/*  GROUP 48:
	PUNEET ANAND    2016B4A70487P
	MAYANK JASORIA  2016B1A70703P
	SHUBHAM TIWARI  2016B4A70935P
	VIBHAV OSWAL    2016B4A70594P */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_tableDef.h"

/**
 * @see symbol_table.h
 */
SymbolTable getSymbolTable() {
	return getHashTable();
}

/**
 * @see symbol_table.h
 * Assumption: Symbol Table never has two entries with same name,
 * even if one is a function and another a variable
 */
SymTableVar* fetchVarData(SymbolTable st, char* name) {
	if(st == NULL) {
		fprintf(stderr, "The given symbol table is not defined.\nNo changes have been made.\n");
		return NULL;
	}

	/* Retrieve the record form the table */
	SymTableVar* data = (SymTableVar*) getDataFromTable(st, name, stringHash);
	if(data->type == SYM_VARIABLE) {
		/* the retrieved record is a variable */
		return data;
	} else {
		/* the retrieved record is a function */
		return NULL;
	}
}

/**
 * @see symbol_table.h
 * Assumption: Symbol Table never has two entries with same name,
 * even if one is a function and another a variable
 */
SymTableFunc* fetchFuncData(SymbolTable st, char* name) {
	if(st == NULL) {
		fprintf(stderr, "The given symbol table is not defined.\nNo changes have been made.\n");
		return NULL;
	}

	/* Retrieve the record form the table */
	SymTableFunc* data = (SymTableFunc*) getDataFromTable(st, name, stringHash);
	if(data->type == SYM_FUNCTION) {
		/* the retrieved record is a function */
		return data;
	} else {
		/* the retrieved record is a variable */
		return NULL;
	}
}

/**
 * @see symbol_table.h
 */
SymbolTable insertVarRecord(SymbolTable st, char* name, int width, int offset, astDataType dataType) {
	if(st == NULL) {
		fprintf(stderr, "The provided symbol table was not defined\n.No changes have been made\n");
		return st;
	}
	
	if(strcmp(name, "") == 0) {
		fprintf(stderr, "The given variable name is empty.\nNo changes hae been made\n");
		return st;
	}

	if(fetchFuncData(st, name) != NULL || fetchVarData(st, name) != NULL) {
		fprintf(stderr, "A record with the given already exists within the symbol table.");
		return st;
	}

	/* creating a record for a variable */
	SymTableVar* data = (SymTableVar*) malloc(sizeof(SymTableVar));
	strcpy(data->name, name);
	data->width = width;
	data->offset = offset;
	data->dataType = dataType;
	data->type = SYM_VARIABLE;

	/**
	 * hashing the record to the symbol table, and returning updated table
	 * NOTE: The stringHash() function is defined in hash_map.h
	 */
	return insertToTable(st, name, data, stringHash);
}

/**
 * @see symbol_table.h
 */
SymbolTable insertFuncRecord(SymbolTable st, char* name) {
	if(st == NULL) {
		fprintf(stderr, "The provided symbol table was not defined\n.No changes have been made\n");
		return st;
	}
	
	if(strcmp(name, "") == 0) {
		fprintf(stderr, "The given variable name is empty.\nNo changes have been made\n");
		return st;
	}

	if(fetchFuncData(st, name) != NULL || fetchVarData(st, name) != NULL) {
		fprintf(stderr, "A record with the given already exists within the symbol table.");
		return st;
	}

	/* creating a record for a function */
	SymTableFunc* data = (SymTableFunc*) malloc(sizeof(SymTableFunc));
	strcpy(data->name, name);
	data->type = SYM_FUNCTION;

	/* initialize input parameters list */
	data->input_plist = getList();

	/* initialize output parameters list */
	data->output_plist = getList();

	/* 
	 * will be updated dynamically, for every variable added to 
	 * this function's symbol table
	 */
	data->actRecSize = 0;

	/* creating a new symbol table for the function */
	data->dataTable = getSymbolTable();

	/**
	 * hashing the record to the symbol table, and returning updated table
	 * NOTE: The stringHash() function is defined in hash_map.h
	 */
	return insertToTable(st, name, data, stringHash);
}

/**
 * Assumption: The function record (name) is already hashed to the symbol table
 * The size of the activation record is computed dynamically everytime this
 * function is called for a new variable. For other details, 
 * @see symbol_table.h
 */
SymbolTable addParamToFunction(SymbolTable st, char* funcName, 
	int paramType, char* varName, int varWidth, astDataType varDataType) {
	/* find the record for the function */
	SymTableFunc* funcData = fetchFuncData(st, funcName);

	if(funcData == NULL) {
		fprintf(stderr, "The data for the required function could not be fetched.\n");
		return st;
	}

	/* compute offset */
	int offset = funcData->actRecSize;

	/* Create a record for the variable */
	SymTableVar* varData = (SymTableVar*) malloc(sizeof(SymTableVar));
	varData->type = SYM_VARIABLE;
	varData->name = varName;
	varData->offset = offset;
	varData->width = varWidth;
	varData->dataType = varDataType;
	
	/* populate correct list */
	if(paramType == 0) {
		funcData->input_plist = insertToList(funcData->input_plist, varData, BACK);

		/* update activation record size */
		funcData->actRecSize += varWidth;
	} else {
		funcData->output_plist = insertToList(funcData->output_plist, varData, BACK);
	}

	return st;
}

/**
 * Assumption: The function record (name) is already hashed to the symbol table
 * The size of the activation record is computed dynamically everytime this
 * function is called for a new variable. For other details, 
 * @see symbol_table.h
 */
SymbolTable addDataToFunction(SymbolTable st, char* funcName, char* varName, int varWidth, astDataType varDataType) {
	/* find the record for the function */
	SymTableFunc* funcData = fetchFuncData(st, funcName);

	if(funcData == NULL) {
		fprintf(stderr, "The data for the required function could not be fetched.\n");
		return st;
	}

	/* check if the supplied variable is unique for this function's table */
	if(fetchVarData(funcData->dataTable, varName) == NULL) {
		/* supplied variable is unique */
		int offset = funcData->actRecSize;

		st = insertVarRecord(st, varName, varWidth, offset, varDataType);

		/* update the size of activation record */
		funcData->actRecSize += varWidth;

		return st;
	} else {
		/* variable already exists, report error and exit */
		fprintf(stderr, 
			"A record for the given data item already exists within the scope of this function.\nNo changes have been made.\n");
		return st;
	}
}

/**
 * Assumption: THe function is already hashed to the symbol table,
 * and variable is added to a nested block
 * @see symbol_table.h
 */
SymbolTable updateOffsetOfFunc(SymbolTable st, char* funcName, int varWidth) {
	/* find the record for the function */
	SymTableFunc* funcData = fetchFuncData(st, funcName);

	if(funcData == NULL) {
		fprintf(stderr, "The data for the required function could not be fetched.\n");
		return st;
	}

	funcData->actRecSize += varWidth;

	return st;
}