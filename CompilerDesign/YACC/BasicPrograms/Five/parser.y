%{
	#include <stdio.h>
	#include <stdlib.h>
%}

%token A B C D NL

%%

stmt : S NL { printf("Valid string\n"); exit(0); };
S : A S D | X ;
X : B X C | ;

%%

int yyerror(char *msg) {
	printf("Invalid string\n");
	exit(0);
}

int main() {
	printf("Enter the string: ");
	yyparse();
}
