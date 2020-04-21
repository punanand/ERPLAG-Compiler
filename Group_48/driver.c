/*  
	GROUP 48:
	PUNEET ANAND    2016B4A70487P
	MAYANK JASORIA  2016B1A70703P
	SHUBHAM TIWARI  2016B4A70935P
	VIBHAV OSWAL    2016B4A70594P 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"

#include "lexer.h"
#include "parser.h"
#include "ast.h"
#include "semanticAnalyzer.h"
#include "symbolTable.h"
#include "codeGen.h"


/**
 * Performs lexical analysis and parsing of a given file, and 
 * prints the inorder traversal of the generated parse tree
 * to a given output file
 * @param inputfile     The source code file
 * @param outputfile    The file into which the inorder traversal
 *                      of the parse tree is to be written
 */
void lexAndParse(char* inputfile) {
	parseInputSourceCode(inputfile);
	printf("\n");
	printParseTree(PT);
}

int main(int argc, char* argv[]) {
	if(argc < 3) {
		fprintf(stderr, KRED "Expected two arguments, found %d\nUsage:\t./compiler <source-code> <assembly-output-file>\nTerminating\n" KNRM, argc-1);
		exit(0);
	}

	/* initializing lexer and parser */
	lexerinit();
	parserInit("grammar_new.erp");
	ComputeFirstAndFollowSets();
	createParseTable();

	printf(KCYN "**************** IMPLEMENTATION STATUS ****************\n" KNRM);
	// printf("1: FIRST and FOLLOW set automated\n");
	// printf("2: Both lexical and syntax analyzer modules implemented\n");
	// printf("3: Code works on all given test cases\n");
	printf("Level 4: All errors have been handled\n");
	printf(KCYN "*******************************************************\n" KNRM);

	int option = 0;
	boolean executed = False;
	ASTNode* root = NULL;
	do {
		printf("\nEnter an option\n");
		printf("1: Print token list from lexer\n");
		printf("2: Run Parser and produce Parse Tree\n");
		printf("3: Print AST (Abstract Syntax Tree) \n");
		printf("4: Amount of memory used by Parse Tree and AST\n");
		printf("5: Print Symbol Table\n");
		printf("6: Print Activation Record size of each function\n");
		printf("7: Print type expressions and width of array variables\n");
		printf("8: Print errors and time required\n");
		printf("9: Produce NASM Assembly Code\n");
		printf("0: Exit\n\n");
		printf("Enter your choice:\n");
		scanf("%d", &option);

		switch(option) {
			case 0: {
				/* exit from the loop */
				printf("\nExited\n");
				break;
			}
			case 1: {
				/* Lexer: For printing the token list generated by the lexer (on the console) */
				/* Call lexer getNextToken() */
				FILE * fp = fopen(argv[1], "r");
				int i = 1;
				token * tok;
				lexerinit();
				printf(KGRN "%-25s%-25s%s\n" KNRM, "line_num", "lexeme", "Token_name");
				while((tok = getNextToken(fp))->id != DOLLAR) {
					printf("%-25d%-25s%d\n", tok->line_num, tok->lex, tok->id);
					i++;
				}
				fclose(fp);
			}
			break;

			case 2: {
				/**
				 * Parser: For parsing to verify the syntactic correctness of the input 
				 * source code and to produce parse tree (On Console)
				 */
				lexerinit();
				
				lexAndParse(argv[1]);
				break;
			}
			break;

			case 3: {
				/**
				 * AST: For printing the Abstract Syntax Tree in appropriate format. 
				 * Also specify the traversal order at the beginning. (On Console)
				 */
			
				if(PT == NULL) {
					/* generate parse tree */
					parseInputSourceCode(argv[1]);
				}

				/* Construct the AST */
				if(root == NULL && syntacticallyCorrect) {
					root = constructAST(NULL, NULL, PT);
				}

				if(syntacticallyCorrect) {
					/* Print the AST */
					printf("\nTraversal Order of AST: Preorder, DFS\n");
					printAST(root);
				} else {
					/* Syntactically incorrect. Report error instead */
					fprintf(stderr, "AST not generated due to syntactic errors, hence it was not printed\n");
				}

			}
			break;

			case 4: {
				/** 
				 * Memory: For displaying the amount of allocated memory and 
				 * number of nodes to each of parse tree and abstract syntax 
				 * tree for the test case used. 
				 */
				if(PT == NULL) {
					// generate parse tree
					parseInputSourceCode(argv[1]);
				}

				if(root == NULL && syntacticallyCorrect) {
					root = constructAST(NULL, NULL, PT);
				}

				int parseTreeSize = getParseTreeSize();
				int numParseTreeNodes = getParseTreeNumNodes();

				char buf[40];
				sprintf(buf, "Number of parse tree nodes: %d", numParseTreeNodes);
				printf("%-40s", buf);

				sprintf(buf, "Allocated Memory for Parse Tree: %d", parseTreeSize);
				printf("%-40s\n", buf);

				if(syntacticallyCorrect) {
					int astSize = getASTSize();
					int astNodesCount = getASTnumNodes();

					sprintf(buf, "Number of AST nodes: %d", astNodesCount);
					printf("%-40s", buf);

					sprintf(buf, "Allocated Memory for AST Tree: %d", astSize);
					printf("%-40s\n", buf);

					float compression = ((parseTreeSize-astSize)/((float)parseTreeSize)) * 100.0;
					printf("Compression is %f\n",compression);
				} else {
					/* Syntactically incorrect. Report error instead */
					fprintf(stderr, "AST not generated due to syntactic errors, hence no computation was possible\n");
				}
			}
			break;

			case 5: {
				/**
				 * Symbol Table: For printing the Symbol Table giving following
				 * information (ten in number) for each variable identifier at 
				 * each line using formatted output. [Use width of variables of 
				 * type integer as 2, of real as 4 and of boolean as 1 for printing 
				 * the symbol table]
				 */
				if(PT == NULL) {
					parseInputSourceCode(argv[1]);
				}
				if(syntacticallyCorrect == False) {
					fprintf(stderr, "Symbol Table not generated due to syntactic errors\n\n");
					break;
				}

				if(root == NULL) {
					root = constructAST(NULL, NULL, PT);
				}
				
				/**
				 * TODO: find a way to ensure no errors are reported here
				 */
				if(globalST == NULL) {
					destroyError();
					globalST = getSymbolTable();
					traverseAST(root, "");
					pass2AST(root, "");
				}

				/* print the symbol table */
				outputSymbolTable(root, 0);
			}
			break;
			
			case 6: {
				/**
				 * Activation record size (fixed, excluding system related):
				 * For printing the total memory requirement (sum total of widths
				 * of all variables in the function scope) for each function.
				 */
				
				if(PT == NULL) {
					parseInputSourceCode(argv[1]);
				}

				if(syntacticallyCorrect == False) {
					fprintf(stderr, "Activation Record not generated due to syntactic errors\n\n");
					break;
				}

				if(root == NULL) {
					root = constructAST(NULL, NULL, PT);
				}
				/**
				 * TODO: find a way to ensure no errors are reported here
				 */ 
				if(globalST == NULL) {
					destroyError();
					globalST = getSymbolTable();
					traverseAST(root, "");
					pass2AST(root, "");
				}
				outputActivationRecords();
			}
			break;
			
			case 7: {
				/**
				 * Static and dynamic arrays: Printing the type expressions and 
				 * width of array variables in a line for a test case
				 */
				if(PT == NULL) {
					parseInputSourceCode(argv[1]);
				}

				if(syntacticallyCorrect == False) {
					fprintf(stderr, "Type expression and widths of arrays not generated due to syntactic errors\n\n");
					break;
				}

				if(root == NULL) {
					root = constructAST(NULL, NULL, PT);
				}
				/**
				 * TODO: find a way to ensure no errors are reported here
				 */
				if(globalST == NULL) {
					destroyError();
					globalST = getSymbolTable();
					traverseAST(root, "");
					pass2AST(root, "");
				}
				outputArrayExprs(root);
			}
			break;

			case 8: {
				/** 
				 * 1) Reports syntatical and semantic errors and 2) Prints total compilation time
				 * If code is syntactically incorrect, only syntax errors are reported 
				 * If the code is syntactically correct, then all type checking and semantic errors are reported
				 */

				/* Cleanup to prevent incorrect time computation */
				PT = NULL;
				root = NULL;
				globalST = NULL;
				destroyError();
				
				/* initialize timer */
				clock_t	start_time, end_time;

				double total_CPU_time, total_CPU_time_in_seconds;

				start_time = clock();

				lexerinit();
				/* Generate Parse Table: */
				parseInputSourceCode(argv[1]);

				if(syntacticallyCorrect == False) {
					fprintf(stderr, "Semantic tests not performed due to syntactic errors\n\n");
					break;
				}

				/* Construct AST */
				root = constructAST(NULL, NULL, PT);

				/* Construct Symbol Table */
				globalST = getSymbolTable();

				/* Pass 1 */
				traverseAST(root, "");

				/* Pass 2 */
				pass2AST(root, "");

				/* prints all errors */
				printErrorList();

				end_time = clock();


				/* Calculating Total Time */
				total_CPU_time  =  (double) (end_time - start_time);
				total_CPU_time_in_seconds =   total_CPU_time / CLOCKS_PER_SEC;
				printf("Total CPU Time: %lf ticks (= %lf seconds)\n\n", total_CPU_time,total_CPU_time_in_seconds);
			}
			break;

			case 9: {
				/**
				 * Produces NASM assembly code 
				 * Assumption: There is no syntactic, semantic or type mismatch error in the test cases 
				 */
				if(PT == NULL) {
					parseInputSourceCode(argv[1]);
				}

				if(syntacticallyCorrect == False) {
					fprintf(stderr, "Semantic check not performed due to syntactic errors\n\n");
					break;
				}

				if(root == NULL) {
					root = constructAST(NULL, NULL, PT);
				}
				/**
				 * TODO: find a way to ensure no errors are reported here
				 */
				if(globalST == NULL) {
					destroyError();
					globalST = getSymbolTable();
					traverseAST(root, "");
					pass2AST(root, "");
				}

				if(syntacticallyCorrect && semanticallyCorrect) {
					emitCodeInit(argv[2]);
					emitCodeAST(root, NULL);
					emitCodeFinalize();
					printf("Code compiles successfully....\n");
				} else {
					fprintf(stderr, "Code not generated due to semantic errors\n");
				}
			}
			break;
			
			default: printf(KYEL "Option %d is invalid, please try again\n" KNRM, option);
		}
	} while(option != 0);
	
	return 0;
}

