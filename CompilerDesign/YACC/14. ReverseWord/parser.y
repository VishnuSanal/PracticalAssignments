%{
	#include <stdio.h>
	#include <stdlib.h>
%}

%token CHAR A B C NL 

%%

stmt : S NL		{ printf("Valid\n"); exit(0); };
S : A S A | B S B | C ;

%%

int yyerror(char *msg) {
	printf("Invalid\n");
	exit(0);
}

int main() {
	printf("Enter the string: ");
	yyparse();
}
