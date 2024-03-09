%{

#include<stdio.h>
#include<string.h>

int vowelCount = 0, consonantCount = 0;

%}
  
%%

[aeiouAEIOU]		{vowelCount++;} 
[a-zA-Z]		{consonantCount++;}
.			{}

%%
  
int yywrap(void){}
  
int main() {

	printf("\nEnter the input: \n");

	yylex();
 
 	printf("\nNumber of vowels: %d", vowelCount);
 	printf("\nNumber of consonants: %d", consonantCount);

	printf("\n\n");

	return 0;
}
