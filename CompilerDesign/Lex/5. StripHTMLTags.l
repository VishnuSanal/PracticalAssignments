%{

#include<stdio.h>

%}

%%

("<")([A-Za-z\"=\/!" "]*)(">") ;

%%

int yywrap(void){}

int main() {

	extern FILE *yyin, *yyout;
	yyin = fopen("input.html", "r");
	yyout = fopen("output.html", "w");
	
	yylex();

	printf("\n\n");

	return 0;
}
