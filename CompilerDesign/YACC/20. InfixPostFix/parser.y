%{
// A+B*C+D => ABC*+D+
// ((A+B)–C*(D/E))+F => AB+CDE/*-F+

	#include <stdio.h>
	#include <stdlib.h>
%}

%token DIGIT ID NL 

%%

stmt : E NL	{ printf("\n"); exit(0); }
E : E'+'T	{ printf("+"); }
  | E'-'T	{ printf("-"); }
  | T		{ }
  ;
T : T'*'F	{ printf("*"); }
  | T'/'F	{ printf("/"); }
  | F		{ }
  ;
F : ID		{ printf("%c", yylval); }	
  | '('E')'	{ }	
  ;

%%

int yyerror(char *msg) {
	printf("\n");
	exit(0);
}

int main() {
	printf("Enter the expression: ");
	yyparse();
	printf("\n\n");
}
