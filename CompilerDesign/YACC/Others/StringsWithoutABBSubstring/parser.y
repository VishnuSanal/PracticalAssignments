%{
	#include <stdio.h>
	#include <stdlib.h>
%}

%token A B NL

%%

stmt : S NL 	{ printf("Valid string\n"); exit(0); };

S : X | X A Z | X A Z B ;

X : X B | ;

Y : A | B A ;
Z : Z Y | ;

%%

int yyerror(char *msg) {
	printf("Invalid string\n");
	exit(0);
}

int main() {
	printf("Enter the string: ");
	yyparse();
}
