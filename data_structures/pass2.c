#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "st.h"
#include "ast.h"
#include "pass1.h"

char typeName[][20] = {"Integer", "Real", "Boolean", "Array", "Pointer"};

void pass2Children(ASTNode * head, char * fname) {
	
	ASTNode* ch = head;
	while(ch != NULL) {
		pass2AST(ch, fname);
		ch = ch -> next;
	}
}

void pass2AST(ASTNode* curr, char* fname) {
	
	switch(curr -> type) {
		case AST_NODE_PROGRAM: {
			ASTNode* ch = curr -> child;
			pass2Children(ch, fname);
		}
		break;

		case AST_NODE_MODULEDECLARATION: {
			ASTNode* ch = curr -> child;
			pass2Children(ch, fname);
		}
		break;

		case AST_NODE_MODULELIST: {
			ASTNode* ch = curr -> child;
			if(curr -> nodeData.moduleList -> type == AST_MODULE_DRIVER) {
				if(ch == NULL)
					return;
				pass2AST(ch, "driver");
			}
			else
				pass2Children(ch, fname);
		}
		break;

		case AST_NODE_MODULE: {
			ASTNode* ch = curr -> child;
			pass2Children(ch, fname);
		}
		break;

		case AST_NODE_INPUTLIST: {
			/* Verify: nothing to do*/
		}
		break;

		case AST_NODE_OUTPUTLIST: {
			/* Verify: nothing to do*/
		}
		break;

		case AST_NODE_ARRAY: {
			/* do nothing */
		}
		break;

		case AST_NODE_RANGEARRAYS: {
			/* do nothing */
		}
		break;

		case AST_NODE_STATEMENT: {
			ASTNode* ch = curr -> child;
			pass2Children(ch, fname);
		}
		break;

		case AST_NODE_IO: {
			ASTNode* ch = curr -> child;	
			ch -> localST = curr -> localST;		
			if(curr -> nodeData.io -> type == AST_IO_GETVAL) {
				SymTableVar* tmp = fetchVarData(curr -> localST, ch -> nodeData.leaf -> tn -> lex); //Args: Symbol Table, Name
				if(tmp == NULL) {
					fprintf(stderr, 
					"The variable taken as input is not being declared line %d.\n", ch -> nodeData.leaf -> tn -> line_num);
				}
				else {
					tmp -> isAssigned = 1;
				}
			}
			else { // AST_IO_PRINT
				if(ch -> type == AST_LEAF_ID) {
					SymTableVar* tmp = fetchVarData(curr -> localST, ch -> nodeData.leaf -> tn -> lex); //Args: Symbol Table, Name
					if(tmp == NULL) {
						fprintf(stderr, 
						"The variable to be output is not declared line %d.\n", ch -> nodeData.leaf -> tn -> line_num);
					}
					else if(ch -> next != NULL && tmp -> dataType != AST_TYPE_ARRAY) {   //int a; a[4];  --> error
						fprintf(stderr, 
						"A non array type variable access using whichId on line %d\n", ch -> nodeData.leaf -> tn -> line_num);
					}
					else if(ch -> next != NULL) {
						boundChecking(tmp, curr);
					}
				} 
			}
		}
		break;

		case AST_NODE_SIMPLESTMT: {
			ASTNode* ch = curr -> child;
			pass2Children(ch, fname);
		}
		break;

		case AST_NODE_ASSIGN: {
			ASTNode* ch = curr -> child;
			SymTableVar* tmp = fetchVarData(curr->localST, ch -> nodeData.leaf -> tn -> lex);
			if(tmp == NULL) {
				fprintf(stderr, 
				"The lhs of the Assignment statement %s on line %d is not defined.\n",
				ch -> nodeData.leaf -> tn -> lex,
				ch -> nodeData.leaf -> tn -> line_num);
			}

			ch = ch -> next;
			ch -> localST = curr -> localST;
			pass2AST(ch, fname);
			if(tmp == NULL)
				return;
			ch = curr -> child -> next;
			if(ch -> type == AST_NODE_LVALARRSTMT) {
				if(tmp -> dataType == AST_TYPE_ARRAY){
					if(ch -> child -> next -> type == AST_NODE_VARIDNUM) {
						if(tmp -> sdt.r -> dataType != ch -> child -> nodeData.var -> dataType) {
							fprintf(stderr, 
							"Type mismatch1 in assignment statement on line %d.\n",
							ch -> child -> next -> child -> nodeData.leaf -> tn -> line_num);
						}
					}
					else {
						astDataType t;
						if(ch -> child -> next -> type == AST_NODE_LEAF)
							t = ch -> child -> next -> nodeData.leaf -> dataType;
						if(ch -> child -> next -> type == AST_NODE_AOBEXPR)
							t = ch -> child -> next -> nodeData.AOBExpr -> dataType;
						if(tmp -> sdt.r -> dataType != t) { 
							fprintf(stderr, 
							"Type mismatch2 in assignment statement on line %d.\n",
							curr -> child -> nodeData.leaf -> tn -> line_num);
						}
					}
				}
				else {
					fprintf(stderr, 
					"Non array type element accessed with index on line %d.\n",
					curr -> child -> nodeData.leaf -> tn -> line_num);
				}
			}
			else {
				astDataType t;
				if(ch -> type == AST_NODE_VARIDNUM)
					t = ch -> nodeData.var -> dataType;
				else if(ch -> type == AST_NODE_LEAF)
					t = ch -> nodeData.leaf -> dataType;
				else if(ch -> type == AST_NODE_AOBEXPR)
					t = ch -> nodeData.AOBExpr -> dataType;
				if(tmp -> dataType != t) {
					fprintf(stderr, 
					"Type mismatch3 in assignment statement on line %d.\n",
					curr -> child -> nodeData.leaf -> tn -> line_num);
					return;
				}
				if(tmp -> dataType == AST_TYPE_ARRAY) {
					SymTableVar *rhs = fetchVarData(curr -> localST, ch -> child -> nodeData.leaf -> tn -> lex);
					if((tmp -> sdt.r -> dataType != rhs -> sdt.r -> dataType)||
						(tmp -> sdt.r -> low != rhs -> sdt.r -> low)||
						(tmp -> sdt.r -> high != rhs -> sdt.r -> high)) {
						fprintf(stderr, 
						"Type mismatch4 in assignment statement on line %d.\n",
						curr -> child -> nodeData.leaf -> tn -> line_num);
						return;
					}
				}
			}
		}
		break;
		
		case AST_NODE_MODULEREUSE: {
			ASTNode* ch = curr -> child;
			pass2Children(ch, fname);
			ch = curr -> child;

			if(ch -> type == AST_NODE_IDLIST)
				ch = ch -> next;

			int line_num = ch -> nodeData.leaf -> tn -> line_num;
			SymTableFunc* tmp = fetchFuncData(ch -> nodeData.leaf -> tn -> lex);
			if(tmp == NULL) {
				fprintf(stderr, 
				"Function called (reused)'%s' is not defined on line %d.\n", ch -> nodeData.leaf -> tn -> lex, line_num);
				return;
			}
			if(strcmp(fname, tmp -> name) == 0) {
				fprintf(stderr, 
				"Recursion is not supported on line %d.\n", line_num);
				return;
			}
			/* To be done in pass2 if the function is not defined. */
			if(tmp -> isDefined == 0)
				return;
			if(ch -> prev != NULL && !listTypeMatch(tmp -> output_plist -> head, ch -> prev, curr -> localST)) {
				fprintf(stderr, 
				"Output list type mismatch on line %d.\n", line_num);
			}
			
			/* searching the idList in case 38, optioanal may be NULL*/
			ch = ch -> next;
			while(ch -> type != AST_NODE_IDLIST)
				ch = ch -> next;

			if(!listTypeMatch(tmp -> input_plist -> head, ch, curr -> localST)) {
				fprintf(stderr, 
				"Input list type mismatch name : %s on line %d.\n", tmp -> name, line_num);
			}
		}
		break;

		case AST_NODE_IDLIST: {
			/* no need*/
		}
		break;

		case AST_NODE_EXPR: {
			/* no need*/
		}
		break;

		case AST_NODE_AOBEXPR: {
			ASTNode* ch = curr -> child;
			ch -> localST = curr -> localST;
			ch -> next -> next -> localST = curr -> localST;
			ch -> next -> localST = curr -> localST;
			pass2AST(ch, fname);
			pass2AST(ch -> next, fname);
			pass2AST(ch -> next -> next, fname);
			astDataType tl, tr;
			ch = curr -> child;
			if(ch -> type == AST_NODE_LEAF) {
				tl = ch -> nodeData.leaf -> dataType;
			}
			else if(ch -> type == AST_NODE_AOBEXPR) {
				tl = ch -> nodeData.AOBExpr -> dataType;
			}
			else if(ch -> type == AST_NODE_VARIDNUM) {
				tl = ch -> nodeData.var -> dataType;
			}
			if(ch -> next -> next -> type == AST_NODE_LEAF) {
				tr = ch -> next -> next -> nodeData.leaf -> dataType;
			}
			else if(ch -> next -> next -> type == AST_NODE_AOBEXPR) {
				tr = ch -> next -> next -> nodeData.AOBExpr -> dataType;
			}
			else if(ch -> next -> next -> type == AST_NODE_VARIDNUM) {
				tr = ch -> next -> next -> nodeData.var -> dataType;
			}
			if(tl == AST_TYPE_ARRAY) {
				if(ch -> type == AST_NODE_VARIDNUM && ch -> child -> next != NULL) {
					SymTableVar * var = fetchVarData(curr -> localST, ch -> child -> nodeData.leaf -> tn -> lex);
					tl = var -> sdt.r -> dataType;
				}
				else if(ch -> type == AST_NODE_VARIDNUM){
					fprintf(stderr, 
					"Array type variable '%s' in arithmetic operation on line %d.\n", ch -> child -> nodeData.leaf -> tn -> lex, ch -> child -> nodeData.leaf -> tn -> line_num);
					return;
				}
			}
			if(tr == AST_TYPE_ARRAY) {
				if(ch -> next -> next -> type == AST_NODE_VARIDNUM && ch -> next -> next -> child -> next != NULL) {
					SymTableVar * var = fetchVarData(curr -> localST, ch -> next -> next -> child -> nodeData.leaf -> tn -> lex);
					tr = var -> sdt.r -> dataType;
				}
				else {
					fprintf(stderr, 
					"Array type variable '%s' in arithmetic operation on line %d.\n", ch -> next -> next -> child -> nodeData.leaf -> tn -> lex, ch -> next -> next -> child -> nodeData.leaf -> tn -> line_num);
					return;
				}
			}
			// tr = (ch -> next -> next) -> nodeData.AOBExpr -> dataType;
			if((ch -> next) -> nodeData.leaf -> op == AST_AOP) {
				if(tl != tr) {
					fprintf(stderr, 
					"Type mismatch in the expression line %d, tl = %s, tr = %s.\n", (ch -> next) -> nodeData.leaf -> tn -> line_num,
						typeName[tl], typeName[tr]);
				}
				else if(tl == AST_TYPE_BOOLEAN) {
					fprintf(stderr, 
					"Bool type variables in arithmetic operation on line %d.\n", (ch -> next) -> nodeData.leaf -> tn -> line_num);
				}
				else 
					curr -> nodeData.AOBExpr -> dataType = tl;
			}
			else if((ch -> next) -> nodeData.leaf -> op == AST_RELOP) {
				if(tl != tr) {
					fprintf(stderr, 
					"Type mismatch in the expression line %d, tl = %s, tr = %s.\n", (ch -> next) -> nodeData.leaf -> tn -> line_num,
						typeName[tl], typeName[tr]);
				}
				else if(tl == AST_TYPE_BOOLEAN) {
					fprintf(stderr, 
					"Bool type variables in arithmetic operation on line %d.\n", (ch -> next) -> nodeData.leaf -> tn -> line_num);
				}
				curr -> nodeData.AOBExpr -> dataType = AST_TYPE_BOOLEAN;
			}
			else if((ch -> next) -> nodeData.leaf -> op == AST_LOP) {
				if(tl != AST_TYPE_BOOLEAN) {
					fprintf(stderr, 
					"Left operator of LOP is not boolean type line %d.\n", 
					(ch -> next) -> nodeData.leaf -> tn -> line_num);		
				}
				if(tr != AST_TYPE_BOOLEAN) {
					fprintf(stderr, 
					"Right operator of LOP is not boolean type line %d.\n",
					(ch -> next) -> nodeData.leaf -> tn -> line_num);
				}
				curr -> nodeData.AOBExpr -> dataType = AST_TYPE_BOOLEAN;
			}
		}
		break;

		case AST_NODE_DECLARESTMT: {
			ASTNode* ch = curr -> child;
			ch -> next -> localST = curr -> localST;
			pass2AST(ch -> next, fname);
			ASTNode* tmp = ch;
			while(tmp != NULL) {

				ASTNode* idNode = tmp -> child;

				if(ch -> next -> type == AST_NODE_ARRAY) {

					ASTNode* lft = (ch -> next) -> child -> child;
					ASTNode* right = lft -> next; 
					astDataType t = (ch -> next) -> child -> next -> nodeData.leaf -> dataType;
					addArrToFunction(curr -> localST, fname, idNode -> nodeData.leaf -> tn -> lex, lft, right, t);
				}
				else {
					addDataToFunction(curr -> localST, fname, idNode -> nodeData.leaf -> tn -> lex, ch -> next -> nodeData.leaf -> dataType, idNode -> nodeData.leaf -> tn -> line_num);
				}
				tmp = tmp -> child;
				tmp = tmp -> next;
			}
		}
		break;

		case AST_NODE_CONDSTMT: {
			ASTNode* ch = curr -> child;
			ch -> localST = curr -> localST;
			pass2AST(ch, fname);
			if((ch -> nodeData).leaf -> dataType == AST_TYPE_REAL) {
				fprintf(stderr, 
				"Switch variable('%s') is of real type on line %d.\n", ch -> nodeData.leaf -> tn -> lex,
					ch -> nodeData.leaf -> tn -> line_num);
				return;
			}

			SymTableFunc* newST = getFuncTable(fname, curr -> localST);
			ASTNode* ch1 = ch -> next;
			ch1 -> localST = newST;
			ch1 -> nodeData.dataType = ch -> nodeData.dataType;
			strcpy(ch1 -> nodeData.caseStmt -> switchVar, ch -> nodeData.leaf -> tn -> lex);
			pass2AST(ch1, fname);

			ASTNode* ch2 = ch1 -> next;
			if(ch -> nodeData.leaf -> dataType == AST_TYPE_BOOLEAN) {
				if(curr -> nodeData.condStmt -> def == 1) {
					fprintf(stderr, 
					"Default case in bool type switch statement on line %d.\n", ch -> nodeData.leaf -> tn -> line_num);
				}
			}
			else if(ch -> nodeData.leaf -> dataType == AST_TYPE_INT) {
				if(curr -> nodeData.condStmt -> def == 0) {
					fprintf(stderr, 
					"Default case not present in int type switch statement line %d.\n", ch -> nodeData.leaf -> tn -> line_num);
				}
				else {
					if(ch2 == NULL) {
						return;
					}
					ch2 -> localST = newST;
					// ch2 -> nodeData.statement -> type = ch -> nodeData.leaf -> dataType;
					pass2AST(ch2, fname);
				}
			}
			else {
				fprintf(stderr, 
				"Switch variable not of feasible type on line %d.\n", ch -> nodeData.leaf -> tn -> line_num);
			}
		}
		break;
		
		case AST_NODE_CASESTMT: {
			ASTNode* ch = curr -> child;
			ch -> localST = curr -> localST;
			pass2AST(ch, fname);

			ch = ch -> next;
			if(ch == NULL)
				return;
			ch -> localST = curr -> localST;
			pass2AST(ch, fname);

			ch = ch -> next;
			if(ch == NULL) {
				return;
			}

			ch -> localST = curr -> localST;
			ch -> nodeData.dataType = curr -> nodeData.dataType;
			strcpy(ch -> nodeData.caseStmt -> switchVar, curr -> nodeData.caseStmt -> switchVar);
			pass2AST(ch, fname);
		}
		break;

		case AST_NODE_UNARY: {
			ASTNode* ch = curr -> child;
			ch = ch -> next;
			ch -> localST = curr -> localST;
			pass2AST(ch, fname);
		}
		break;
		
		case AST_NODE_LVALARRSTMT: {
			ASTNode* ch = curr -> child;
			SymTableVar* tmp = fetchVarData(curr -> localST, ch -> nodeData.leaf -> tn -> lex);
			SymTableVar* par = fetchVarData(curr -> localST, curr -> parent -> child -> nodeData.leaf -> tn -> lex);
			if(par == NULL) {
				// fprintf(stderr, 
				// "Lvalue The variable taken as input is not being declared.\n");
				/* already been taken care of */
			}
			else if(par -> dataType != AST_TYPE_ARRAY) {
				fprintf(stderr, 
				"A non array type variable('%s') access using whichId on line %d\n", par -> name,
					ch -> nodeData.leaf -> tn -> line_num);
			}
			else if(ch -> next != NULL) {
				boundChecking(par, curr -> parent);
			}
			ch = ch -> next;
			ch -> localST = curr -> localST;
			pass2AST(ch, fname);
			ch = curr -> child -> next;
			curr -> nodeData.lvalueARRStmt -> dataType = ch -> nodeData.AOBExpr -> dataType;
		}
		break;

		case AST_NODE_ITERSTMT: {
			ASTNode* ch = curr -> child;
			ch -> localST = curr -> localST;
			pass2AST(ch, fname);
			ch = curr -> child;
			if(ch -> nodeData.leaf -> dataType != AST_TYPE_INT) {
				fprintf(stderr, 
				"For loop variable('%s') is not of int type on line %d.\n",
				ch -> nodeData.leaf -> tn -> lex,
				ch -> nodeData.leaf -> tn -> line_num);
				return;
			}

			SymTableFunc* newST = getFuncTable(fname, curr -> localST);
			ASTNode* ch1 = ch -> next;
			if(ch1 == NULL) {
				return;
			}
			ch1 -> localST = newST;
			pass2AST(ch1, fname);

			ASTNode* ch2 = ch1 -> next;
			if(ch2 == NULL) {
				return;
			}
			ch2 -> localST = newST;
			pass2AST(ch2, fname);
		}
		break;

		case AST_NODE_VARIDNUM: {
			ASTNode* ch = curr -> child;
			pass2Children(ch, fname);
			ch = curr -> child;
			SymTableVar * idNode = fetchVarData(curr -> localST, ch -> nodeData.leaf -> tn -> lex);
			if(idNode == NULL) {
				fprintf(stderr, 
				"VarIdNum id('%s') not declared before %d\n", ch -> nodeData.leaf -> tn -> lex, ch -> nodeData.leaf -> tn -> line_num);
				return;
			}
			curr -> nodeData.var -> dataType = idNode -> dataType;
			if(curr -> nodeData.var -> dataType == AST_TYPE_ARRAY && ch-> next == NULL && curr -> parent -> type != AST_NODE_ASSIGN) {
				fprintf(stderr, 
				"Array variable('%s') used without index on line %d.\n",
				idNode -> name, ch -> nodeData.leaf -> tn -> line_num);
				return;
			}
			if(curr -> nodeData.var -> dataType != AST_TYPE_ARRAY && ch-> next != NULL) {
				fprintf(stderr, 
				"Non Array variable('%s') used with index line %d.\n", 
				idNode -> name,
				ch -> nodeData.leaf -> tn -> line_num);
			}
			if(ch -> next != NULL) {
				curr -> nodeData.var -> dataType = idNode -> sdt.r -> dataType;
			}
		}
		break;

		case AST_NODE_LEAF: {
			/* 
				For ID: (As in ast.c)
				CASE: 3, 7, 10, 13, 16, 17, 18 
			*/
			switch(curr -> nodeData.leaf -> type) {
				case AST_LEAF_INT: {
					curr -> nodeData.leaf -> dataType = AST_TYPE_INT;
					return;
				}
				break;
				case AST_LEAF_RNUM: {
					curr -> nodeData.leaf -> dataType = AST_TYPE_REAL;
					return;	
				}
				break;
				case AST_LEAF_BOOL: {
					curr -> nodeData.leaf -> dataType = AST_TYPE_BOOLEAN;
					return;	
				}
				break;
				case AST_LEAF_ID: {
					char str[30];
					strcpy(str, curr -> nodeData.leaf -> tn -> lex);
					switch(curr -> parent -> type) {
						case AST_NODE_MODULEDECLARATION: {
							SymTableFunc * tmp = insertFuncRecord(str);
							if(tmp == NULL) {
								fprintf(stderr, "A record with the given already exists within the symbol table on line %d.", curr -> nodeData.leaf -> tn -> line_num);
							}
							return;
						}
						break;
						case AST_NODE_MODULE: {
							SymTableFunc* tmp = fetchFuncData(str);
							if(tmp != NULL && tmp -> isDeclared == 1) {
								fprintf(stderr, 
								"Redundant declaration of the function '%s'.\n", str);
								return;
							}
							if(tmp != NULL && tmp -> isDefined == 1) {
								fprintf(stderr, 
								"Multiple definitions for the function '%s' on line %d.\n", str,
								curr -> nodeData.leaf -> tn -> line_num);
								return;
							}
							if(tmp == NULL) {
								tmp = insertFuncRecord(str);
								tmp -> isDeclared = 0;
								tmp -> isDefined = 1;
							}
							curr -> localST = tmp;
							insertplist(curr -> next, str);
							insertplist(curr -> next -> next, str);
						}
						break;
						case AST_NODE_INPUTLIST: {
							/* handled in insertinputplist();*/
						}
						break;
						case AST_NODE_OUTPUTLIST: {
							/* handled in insertoutputplist();*/
						}
						break;
						case AST_NODE_IO: {
							/* handles above*/
						}
						break;
						case AST_NODE_VARIDNUM: {
							if(curr -> prev != NULL) {
								SymTableVar* idx = fetchVarData(curr -> localST, str);
								if(idx == NULL) {
									fprintf(stderr, 
									"Index variable('%s') is not defined on line %d.\n", str,
									curr -> nodeData.leaf -> tn -> line_num);
									return;
								}
								if(idx -> dataType != AST_TYPE_INT) {
									fprintf(stderr, 
									"Index variable('%s') is not Integer on line %d.\n", str,
									curr -> nodeData.leaf -> tn -> line_num);
								}
								curr -> nodeData.leaf -> dataType = idx -> dataType;
							}
							else {
								SymTableVar* tmp = fetchVarData(curr -> localST, str);
								if(tmp == NULL) {
									// fprintf(stderr, 
									// "The identifier('%s') not declared on line %d.\n", str, 
									// curr -> nodeData.leaf -> tn -> line_num);
									return;
								}
								curr -> nodeData.leaf -> dataType = tmp -> dataType;
							}
						}
						break;
						case AST_NODE_LVALARRSTMT: {
							SymTableVar* idx = fetchVarData(curr -> localST, str);
							if(idx == NULL) {
								fprintf(stderr, 
								"Index variable('%s') is not defined on line %d.\n", str,
									curr -> nodeData.leaf -> tn -> line_num);
								return;
							}
							if(idx -> dataType != AST_TYPE_INT) {
								fprintf(stderr, 
								"Range Arrays variable('%s') is not Integer on line %d.\n", str,
									curr -> nodeData.leaf -> tn -> line_num);
							}
						}
						break;
						case AST_NODE_ASSIGN: {
							// SymTableVar* idx = fetchVarData(curr -> localST, str);
							// if(idx == NULL) {
							// 	fprintf(stderr, 
							// 	"The variable to be assigned is not declared.\n");
								return;
							// }
							/* No need */
						}
						break;
						case AST_NODE_MODULEREUSE: {
							SymTableFunc* func = fetchFuncData(str);
							if(func == NULL) {
								fprintf(stderr, 
								"The function used('%s') is not declared and defined on line %d.\n", str, curr -> nodeData.leaf -> tn -> line_num);
								return;
							}
							if(func -> isDefined == 0) {
								func -> isDeclared++;
							}
						}
						break;
						case AST_NODE_IDLIST: {
							/* handled above in typelistmatch()*/
						}
						break;
						case AST_NODE_CONDSTMT: {
							SymTableVar* idx = fetchVarData(curr -> localST, str);
							if(idx == NULL) {
								fprintf(stderr, 
								"Switch variable('%s') is not defined line %d.\n",
								str, curr -> nodeData.leaf -> tn -> line_num);
								return;
							}
							else {
								curr -> nodeData.leaf -> dataType = idx -> dataType;
							}
						}
						break;
						case AST_NODE_ITERSTMT: {
							SymTableVar* idx = fetchVarData(curr -> localST, str);
							if(idx == NULL) {
								fprintf(stderr, 
								"Loop variable('%s') is not defined line %d.\n",
								str, curr -> nodeData.leaf -> tn -> line_num);
								/* not declared, still giving it a type*/
								curr -> nodeData.leaf -> dataType = AST_TYPE_INT;
								return;
							}
							else {
								curr -> nodeData.leaf -> dataType = idx -> dataType;
							}
						}
						break;
					}
				}
				break;
				case AST_LEAF_NUM: {
					curr -> nodeData.leaf -> dataType = AST_TYPE_INT;
				}
				break;
				case AST_LEAF_IDXNUM: {
					
					curr -> nodeData.leaf -> dataType = AST_TYPE_INT;
					if(curr -> parent -> type == AST_NODE_VARIDNUM) {
						SymTableVar* arr = fetchVarData(curr -> localST, curr -> parent -> child -> nodeData.leaf -> tn -> lex);
						if(arr == NULL) {
							// fprintf(stderr, 
							// "The array variable is not defined.\n");
							return;
						}
						boundChecking(arr, curr -> parent);
					}
					return;
				}
				break;
				case AST_LEAF_IDXID: {
					char str[30];
					strcpy(str, curr -> nodeData.leaf -> tn -> lex);
					SymTableVar* idx = fetchVarData(curr -> localST, str);
					if(idx == NULL) {
						fprintf(stderr, 
						"Index variable is not defined.\n");
						return;
					}
					if(idx -> dataType != AST_TYPE_INT) {
						fprintf(stderr, 
						"Index variable in range arrays is not Integer.\n");
					}
				}
				break;
				case AST_LEAF_PLUS: {
					curr -> nodeData.leaf -> op = AST_AOP;
				}
				break;
				case AST_LEAF_MINUS: { 
					curr -> nodeData.leaf -> op = AST_AOP;
				}
				break;
				case AST_LEAF_MUL: { 
					curr -> nodeData.leaf -> op = AST_AOP;
				}
				break;
				case AST_LEAF_DIV: { 
					curr -> nodeData.leaf -> op = AST_AOP;
				}
				break;
				case AST_LEAF_OR: { 
					curr -> nodeData.leaf -> op = AST_LOP;
				}
				break;
				case AST_LEAF_AND: {
					curr -> nodeData.leaf -> op = AST_LOP;
				}
				break;
				case AST_LEAF_LT: {
					curr -> nodeData.leaf -> op = AST_RELOP;
				}
				break;
				case AST_LEAF_LE: {
					curr -> nodeData.leaf -> op = AST_RELOP;
				}
				break;
				case AST_LEAF_GT: {
					curr -> nodeData.leaf -> op = AST_RELOP;
				}
				break;
				case AST_LEAF_GE: {
					curr -> nodeData.leaf -> op = AST_RELOP;
				}
				break;
				case AST_LEAF_EQ: {
					curr -> nodeData.leaf -> op = AST_RELOP;
				}
				break;
				case AST_LEAF_NE: {
					curr -> nodeData.leaf -> op = AST_RELOP;
				}
				break;
				case AST_LEAF_TRUE: {
					curr -> nodeData.leaf -> dataType = AST_TYPE_BOOLEAN;
				}
				break;
				case AST_LEAF_FALSE: {
					curr -> nodeData.leaf -> dataType = AST_TYPE_BOOLEAN;
				}
				break;
				case AST_LEAF_VALNUM: {
					curr -> nodeData.leaf -> dataType = AST_TYPE_INT;
				}
				break;
				case AST_LEAF_VALTRUE: {
					curr -> nodeData.leaf -> dataType = AST_TYPE_BOOLEAN;
				}
				break;
				case AST_LEAF_VALFALSE: {
					curr -> nodeData.leaf -> dataType = AST_TYPE_BOOLEAN;
				}
				break;
				case AST_LEAF_VARIDNUM_NUM: {
					curr -> nodeData.leaf -> dataType = AST_TYPE_INT;
				}
				break;
				case AST_LEAF_VARIDNUM_ID: {
					char str[30];
					strcpy(str, curr -> nodeData.leaf -> tn -> lex);
					SymTableVar* tmp = fetchVarData(curr -> localST, str);
					if(tmp == NULL) {
						fprintf(stderr, 
						"The identifier not declared.\n");
					}
					curr -> nodeData.leaf -> dataType = tmp -> dataType;
				}
				break;
				case AST_LEAF_VARIDNUM_RNUM: {
					curr -> nodeData.leaf -> dataType = AST_TYPE_REAL;
				}
				break;
				case AST_LEAF_BOOLTRUE: {
					curr -> nodeData.leaf -> dataType = AST_TYPE_BOOLEAN;
				}
				break;
				case AST_LEAF_BOOLFALSE: {
					curr -> nodeData.leaf -> dataType = AST_TYPE_BOOLEAN;
				}
				break;
				case AST_LEAF_UOPPLUS: {
					/* nothing required as of now*/
				}
				break;
				case AST_LEAF_UOPMINUS: {
					/* nothing required as of now*/
				}
				break;
				default: {
					/* nothing required as of now*/
				}
			}
		}
		break;
		default: {
			fprintf(stderr, "Default error!\n");
		}
	}
}