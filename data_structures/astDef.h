/*  GROUP 48:
	PUNEET ANAND    2016B4A70487P
	MAYANK JASORIA  2016B1A70703P
	SHUBHAM TIWARI  2016B4A70935P
	VIBHAV OSWAL    2016B4A70594P */

#ifndef _AST_DEF
#define _AST_DEF

#include "hash_map.h"

/**
*  astDef.h: Contains definitions for constructing abstract syntax tree 
*  Note: 'declarationNode' in our semantic rules documentation has been changed to
*         'moduleDeclarationsNode' in this code to avoid confusion.
*/

/*
* BOUND_RUNTIME: The bound checking of the array index is left for runtime.
* BOUND_CORRECT: The given index access satisfies the bounds of the array. (if statically checked)
* BOUND_ERROR: The given index access satisfies the bounds of the array. (if statically checked)
*/
typedef enum {
	BOUND_RUNTIME,
	BOUND_ERROR,
	BOUND_CORRECT
} boundCheck;

/**
* nodeType: Identifies the type of node represented by the 
*           ASTNode. 
* Naming convention: Construct name in all uppercase letters
*/
typedef enum {
	AST_NODE_PROGRAM,
	AST_NODE_MODULEDECLARATION,
	AST_NODE_MODULELIST,
	AST_NODE_MODULE,
	AST_NODE_INPUTLIST,
	AST_NODE_OUTPUTLIST,
	AST_NODE_ARRAY,
	AST_NODE_RANGEARRAYS,
	AST_NODE_STATEMENT,
	AST_NODE_IO,
	AST_NODE_SIMPLESTMT,
	AST_NODE_ASSIGN,
	AST_NODE_WHICHSTMT,
	AST_NODE_MODULEREUSE,
	AST_NODE_IDLIST,
	AST_NODE_EXPR,
	AST_NODE_AOBEXPR,
	AST_NODE_DECLARESTMT,
	AST_NODE_CONDSTMT,
	AST_NODE_CASESTMT,
	AST_NODE_UNARY,
	AST_NODE_LVALARRSTMT,
	AST_NODE_ITERSTMT,
	AST_NODE_FOR,
	AST_NODE_WHILE,
	AST_NODE_VARIDNUM,
	AST_NODE_LEAF
} astNodeType;

/**
* astDataType: Identifies the datatype of node represented by the 
*           ASTNode (if it represents some identifier or a subexpression). 
*/
typedef enum astDataType {
	AST_TYPE_INT,
	AST_TYPE_REAL,
	AST_TYPE_BOOLEAN,
	AST_TYPE_ARRAY,
	AST_TYPE_POINTER
} astDataType;

/* 
* stmt_type: specifies the type of statement if it is a statement type of node
* naming convention: Construct name in all uppercase letters
*/
typedef enum {
	AST_STMT_IO,
	AST_STMT_SIMPLE,
	AST_STMT_DECLARATION,
	AST_STMT_CONDITIONAL,
	AST_STMT_ITERATIVE,
	AST_STMT_ASSIGNMENT,
	AST_STMT_MODULEREUSE,
	AST_STMT_LVALUEID,
	AST_STMT_LVALUEARR,
	AST_STMT_SIMPLE_MODULEREUSE,
	AST_STMT_SIMPLE_ASSIGN
} stmt_type;

/*
* io_type: specifies the type of IO statement for AST_NODE_IO.
* 	AST_IO_GETVAL: used for get_value() construct
* 	AST_IO_PRINT: used for print construct
*/
typedef enum {
	AST_IO_GETVAL,
	AST_IO_PRINT
} io_type;

/* 
*  iter_type: specifies the type of IO statement for AST_NODE_ITER.
*	AST_ITER_FOR: used for for loop construct
*	AST_ITER_WHILE: used for while loop construct
*/
typedef enum {
	AST_ITER_FOR,
	AST_ITER_WHILE
} iter_type;

/* 
*	module_type: distinguishes driver modules from other modules. 
*	AST_MODULE_DRIVER: for driver module
*	AST_MODULE_Other: for other modules
*/
typedef enum {
	AST_MODULE_DRIVER,
	AST_MODULE_OTHER
} module_type;


/*
*	leaf_type: specifies the type of leaf node.
* 	naming convention: type of symbol represented in all uppercase.
*/
typedef enum {
	AST_LEAF_INT,
	AST_LEAF_RNUM,
	AST_LEAF_NUM,
	AST_LEAF_BOOL,
	AST_LEAF_ID,
	AST_LEAF_IDXNUM,
	AST_LEAF_IDXID,
	AST_LEAF_PLUS,
	AST_LEAF_MINUS,
	AST_LEAF_MUL,
	AST_LEAF_DIV,
	AST_LEAF_OR,
	AST_LEAF_AND,
	AST_LEAF_LT,
	AST_LEAF_LE,
	AST_LEAF_GT,
	AST_LEAF_GE,
	AST_LEAF_EQ,
	AST_LEAF_NE,
	AST_LEAF_TRUE,
	AST_LEAF_FALSE,
	AST_LEAF_VALNUM,
	AST_LEAF_VALTRUE,
	AST_LEAF_VALFALSE,
	AST_LEAF_VARIDNUM_NUM,
	AST_LEAF_VARIDNUM_ID,
	AST_LEAF_VARIDNUM_RNUM,
	AST_LEAF_BOOLTRUE,
	AST_LEAF_BOOLFALSE,
	AST_LEAF_UOPPLUS,
	AST_LEAF_UOPMINUS
} leaf_type;

/* 
*	optype: specifies the type of operation to be performed between subexpressions
*	AST_LOP: Logical Operator	
*	AST_RELOP: Relational Operator
*	AST_AOP: Arithmetic Operator
*/
typedef enum {
	AST_LOP,
	AST_RELOP,
	AST_AOP
} optype;

/* 
*	typeSize: array specifying the width of each dataType in bytes.
*/
int typeSize[5];

/*	
*	typeName: specifies the string representation corresponding to the enum 'astDataType'
*/
char typeName[5][20];

typedef struct pn {
	/* no particular field needed for Program Node */
} programNode;

typedef struct {
	/* no particular field needed for moduleDeclarationNode node. */
} moduleDeclarationNode; 
/*
* This is a linked list type of structure. 
*/

typedef struct moduleNode {

	int start_line_num;	/* points to the line number of corresponding START Keyword */
	int end_line_num;	/* points to the line number of corresponding END Keyword */
} moduleNode;


typedef struct {

	module_type type;	/* tag AST_MODULE_DRIVER, AST_MODULE_OTHER */
	int start_line_num;	/* points to the line number of corresponding START Keyword */
	int end_line_num;	/* points to the line number of corresponding END Keyword */
} moduleListNode;


typedef struct {
	
	/* no particular field needed for moduleDeclarationNode node. */
} inputListNode;

typedef struct {
	
	int isAssigned;	/* indicates whether the output parameter is being assigned or not */
} outputListNode;

typedef struct {
	
	unsigned is_static:1;	/* Whether Array is static: 0 - Not static, 1 - static */ 
	astDataType dataType;	/* indicates the datatype represented by the node */
} dataTypeNode;

typedef struct {

	unsigned is_static:1; /* Whether Array is static: 0 - Not static, 1 - static */
} rangeArraysNode;

typedef struct {
	
	stmt_type type; 		/* defined above */
	struct ASTNode* next;	/* Points to next element of type statementNode */
} statementNode;

typedef struct {

	stmt_type type; /* defined above */
} simpleStmtNode;

typedef struct {

	boundCheck b;	/* defined above */	
} assignNode;

typedef struct {

	int a;
	int listCheck;
} moduleReuseNode;

typedef struct {
	
	struct ASTNode* next;
} idListNode;

typedef struct {
	int temporaryOffset;
	astDataType dataType;
} AOBExprNode;

typedef struct {
	int a;
	
} declareStmtNode;

typedef struct {
	int def;
	int start_line_num;
	int end_line_num;
	int def_line_num;
	
} condStmtNode;

typedef struct {
	struct ASTNode* next; /* Points to next element of type caseStmtNode */
	int breakLabel;
	int label;
	int lastLabel;
	char switchVar[30];
	astDataType dataType; /* for checking bool int etc */
} caseStmtNode;

typedef struct {
	int a;
	int temporaryOffset;
	astDataType dataType;
	
} unaryNode;

typedef struct {
	int a;
	astDataType dataType;
	
} lvalueARRStmtNode;

typedef struct {
	
	iter_type type; /* tag for iterative statement */
	int start_line_num;
	int end_line_num;
} iterStmtNode;

typedef struct {
	int a;
	
} forNode;

typedef struct {
	
} whileNode;

typedef struct {
	boundCheck b;
	io_type type;
} ioNode;

typedef struct {

	boundCheck b;
	int temporaryOffset;
	astDataType dataType;
	int a;
} varidnumNode;

typedef struct {
	struct treeNode* tn; /* from leaf of parse tree */
	int temporaryOffset;
	astDataType dataType;
	optype op;
	leaf_type type; 
} leafNode;


/**
* Represents a node in the abstract syntax tree (AST)
*/ 

typedef union {
	programNode* program;
	moduleDeclarationNode* moduleDeclaration;
	moduleListNode* moduleList;
	moduleNode* module;
	inputListNode* inputList;
	outputListNode* outputList;
	dataTypeNode* dataType;
	rangeArraysNode* rangeArrays;
	statementNode* statement;
	ioNode* io;
	simpleStmtNode* simpleStmt;
	assignNode* assign;
	moduleReuseNode* moduleReuse;
	idListNode* idList;
	AOBExprNode* AOBExpr;
	declareStmtNode* declareStmt;
	condStmtNode* condStmt;
	caseStmtNode* caseStmt;
	unaryNode* unary;
	lvalueARRStmtNode* lvalueARRStmt;
	iterStmtNode* iterStmt;
	forNode* for_n;
	whileNode* while_n;
	varidnumNode* var;
	leafNode* leaf;
} astNodeData;

struct SymTableFunc;

typedef struct ASTNode {

	/* Attributes specific to the AST node 
	Naming convention: 
		1. Name of node type is the construct name is small case
		2. If the construct name is a keyword in C then append '_n' at the end in (1)
		3. Typedefs not used as they abstract out the record type representing the node and reduce code readability   
	*/ 
	astNodeData nodeData;

	astNodeType type; /* Type of node represented by this AST node */

	/**
	* Include pointer to Symbol Table Entry of nested constructs [if, while etc.].
	* (This contains pointer to variable symbol table)
	*/
	struct SymTableFunc* localST;
	int associatedRule;	
	/* TODO: add data fields later */


	/* n-ary tree pointers */
	struct ASTNode* parent;
	struct ASTNode* prev;
	struct ASTNode* next;
	struct ASTNode* child; 
} ASTNode;

/** 
* -------------------------------------------------------------------------------- 
* 	START OF stDef.h Code here copied from stDef.h to avoid circulardependenncies
* --------------------------------------------------------------------------------
*/

/* defining a symbol table */
typedef HashTable SymbolTable;

SymbolTable globalST;

typedef enum {
	SYM_VARIABLE,
	SYM_FUNCTION,
	SYM_OTHER   /* Ex: If Else Construct */
} SymTableType;

typedef struct arrayInfo {
	astDataType dataType; /* can only be int, real, boolean? */
	int low; /*low..high */
	int high;
	char lowId[30]; /*lowID..highId*/
	char highId[30];
} arrayInfo;

typedef union {
	arrayInfo* r;	
	int intVal;
	float floatVal;
	int boolVal:1;
} SymDataType;

typedef enum {
	SCOPE_FOR,
	SCOPE_COND,
	SCOPE_WHILE,
	SCOPE_DEFAULT
} scopeType;

typedef struct SymTableFunc {
	SymTableType type;  /*to cross check if it is a function (type==SYM_FUNCTION) */
	int isDefined;			/*to check if the function is defined*/
	int isDeclared;			/*to check if the function is declared*/
	struct SymTableFunc * parent; /* pointer to the static parent of the scope. */
	int baseAdd; /* base address of the fuction activation record. */
	char name[30]; /* name of the function */
	List input_plist; /* List of input parameter variables */
	List output_plist; /* List of output parameter variables */
	SymbolTable dataTable; /* symbol table associated with the local elements of this function , it contains entries of type SymTableVar */
	int actRecSize; /* field for storing activation record size */
	int dynamicRecSize;
	char dependentVar[30];
	scopeType scope;
	int level;
	int start_line_num;
	int end_line_num;
	int inputSize;
	int outputSize;
	char nextJump[30];
} SymTableFunc;

typedef struct symTableVar {	
	SymTableType type;
	char name[30];
	int isAssigned;
	int width; /* total memory space to be allocated */
	int offset;
	int whileNest;
	/*
	* datatype of variable -> INT, RNUM, BOOL, ARRAY
	*/
	int declarationLine;
	astDataType dataType;
	SymDataType sdt;
	SymTableFunc * table;
} SymTableVar;

int varPresent;
int globalNest;
int numASTnodes;
int ASTSize;

#endif