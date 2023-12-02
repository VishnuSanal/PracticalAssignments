%{

// int print ( int , int ) ;

	#include <stdio.h>
	#include <stdlib.h>
%}

%token D_TYPE ID PAR_OPEN PAR_CLOSE COMMA SEMICOLON VOID NL

%%

stmt : S NL 							{ printf("Valid\n"); exit(0); };
S : RET_TYPE ID PAR_OPEN ARG_LIST PAR_CLOSE SEMICOLON ;
RET_TYPE : D_TYPE | VOID ;
ARG_LIST : D_TYPE COMMA ARG_LIST | D_TYPE

%%

int yyerror(char *msg) {
	printf("Invalid\n");
	exit(0);
}

int main() {
	printf("Enter the string: ");
	yyparse();
}
