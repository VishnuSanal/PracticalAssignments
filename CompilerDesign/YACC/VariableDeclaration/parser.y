%{
	#include <stdio.h>
	#include <stdlib.h>
%}

%token D_TYPE _ID NUM COMMA SEMICOLON ARR_START ARR_END STAR NL

%%

stmt : S NL { printf("Valid\n"); exit(0); };
S : D_TYPE NAMES SEMICOLON ;
NAMES : NAMES COMMA VAR | VAR ;
VAR : _ID | _ID ARR_START NUM ARR_END | STAR _ID ;

%%

int yyerror(char *msg) {
	printf("Invalid\n");
	exit(0);
}

int main() {
	printf("Enter the string: ");
	yyparse();
}
