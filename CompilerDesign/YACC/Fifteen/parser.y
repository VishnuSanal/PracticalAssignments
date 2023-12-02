%{
	#include <stdio.h>
	#include <stdlib.h>
%}

%token A B NL

%%

stmt : S NL { printf("Valid string\n"); exit(0); };
S : X Y ;
X : A X | ;
Y : B Y | ;

%%

int yyerror(char *msg) {
	printf("Invalid string\n");
	exit(0);
}

int main() {
	printf("Enter the string: ");
	yyparse();
}
