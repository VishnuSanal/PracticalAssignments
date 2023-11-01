%{

// for ( int i = 0 ; i <= 10 ; i ++ ) ;

	#include <stdio.h>
	#include <stdlib.h>
%}

%token FOR INT _ID NUM EQUALS REL_OP INC_DEC PAR_OPEN PAR_CLOSE BR_OPEN BR_CLOSE COMMA SEMICOLON NL

%%

stmt : S NL { printf("Valid\n"); exit(0); };
S : FOR PAR_OPEN INIT COND ACTION PAR_CLOSE SEMICOLON ;
INIT : INT _ID EQUALS NUM SEMICOLON ;
COND : _ID REL_OP NUM SEMICOLON | _ID REL_OP _ID SEMICOLON ; 
ACTION : _ID INC_DEC ;

%%

int yyerror(char *msg) {
	printf("Invalid\n");
	exit(0);
}

int main() {
	printf("Enter the string: ");
	yyparse();
}
