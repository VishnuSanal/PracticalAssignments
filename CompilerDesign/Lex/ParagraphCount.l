%{

#include<stdio.h>
#include<string.h>

int characterCount = 0, wordCount = 0, sentenceCount = 0;

%}
  
%%

[a-zA-Z0-9]	{characterCount++;} 
" "			{wordCount++;}
"."			{sentenceCount++;}

%%
  
int yywrap(void){}
  
int main() {

	printf("\nEnter the input paragraph: \n");

	yylex();
 
 	printf("\nNumber of characters: %d", characterCount);
 	printf("\nNumber of words: %d", wordCount + 1);
 	printf("\nNumber of sentences: %d", sentenceCount);

	printf("\n\n");

	return 0;
}
