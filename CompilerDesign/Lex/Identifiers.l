%{

#include<stdio.h>
#include<string.h>

%}

letter	[A-Za-z]
digit	[0-9]
  
%%

({letter}|(_))({letter}|{digit}|(_))*	{printf("\nValid Identifier");}
.*										{printf("\nInvalid Identifier");}

%%

int yywrap(void){}

int main() {

	printf("\nEnter the input: \n");

	yylex();

	printf("\n\n");

	return 0;
}
