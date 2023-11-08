%{
	#include <stdio.h>
	#include <stdlib.h>
%}

%token FOR INT ID NUM EQUALS REL_OP INC_DEC PAR_OPEN PAR_CLOSE COMMA SEMICOLON NL

%%

stmt : S NL 							{ printf("Valid\n"); exit(0); };
S : FOR PAR_OPEN INIT COND ACTION PAR_CLOSE SEMICOLON ;
INIT : INT ID EQUALS NUM SEMICOLON ;
COND : ID REL_OP NUM SEMICOLON | ID REL_OP ID SEMICOLON ; 
ACTION : ID INC_DEC ;

%%

int yyerror(char *msg) {
	printf("Invalid\n");
	exit(0);
}

int main() {
	printf("Enter the string: ");
	yyparse();
}
