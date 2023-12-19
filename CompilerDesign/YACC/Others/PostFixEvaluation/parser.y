%{
  #include<stdio.h>
%}

%token DIGIT OP NL

%%

start : E NL	{ printf("Result\: %d\n", $$); exit(0); } ;

E : E E '+'	  { $$ = $1 + $2; }
  | E E '-' 	{ $$ = $1 - $2; }
  | E E '*'	  { $$ = $1 * $2; }
  | E E '/'	  { $$ = $1 / $2; }
  | E E '%'	  { $$ = $1 % $2; }
  | '('E')'	  { $$ = $2; }
  | DIGIT	    { $$ = $1; }
;

%%

int yyerror(char *c) {
	printf("Invalid\n");
	return 1;
}

int main () {

	printf("Enter the expression: ");
	yyparse();
	
	return 0;
}
