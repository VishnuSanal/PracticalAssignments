%{

#include<stdio.h>
#include<string.h>

%}

digit	[0-9]
  
%%

(("+"|"-")?)({digit}+)(("."{digit}+)?)((E("+"|"-")?{digit}+)?)		{printf("\nValid Floating Number");}
.*																	{printf("\nInvalid Floating Number");}

%%
  
int yywrap(void){}

int main() {

	printf("\nEnter the input: \n");

	yylex();

	printf("\n\n");

	return 0;
}
