%{
	#include <stdio.h>
	#include <stdlib.h>
%}

%token DIGIT NL 

%%

stmt : E NL	{ printf("Result: %d\n", $$); exit(0); }

E : E'+'E	{ $$=$1+$3; }
  | E'-'E	{ $$=$1-$3; }
  | E'*'E	{ $$=$1*$3; }
  | E'/'E	{ $$=$1/$3; }
  | E'%'E	{ $$=$1%$3; }
  | '('E')'	{ $$=$2; }
  | DIGIT	{ $$=$1; }
;

%%

int yyerror(char *msg) {
	printf("Invalid\n");
	exit(0);
}

int main() {
	printf("Enter the expression: ");
	yyparse();
}
