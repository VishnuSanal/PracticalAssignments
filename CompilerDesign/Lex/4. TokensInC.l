%{

#include<stdio.h>
#include<string.h>

char keywords[100][100], identifiers[100][100], punctuators[100][100], operators[100][100], numbers[100][100], strings[100][100];

int i = 0, j = 0, k = 0, l = 0, m = 0, n = 0;

%}

letter	[A-Za-z]
digit	[0-9]
  
%%

auto|break|case|char|continue|do|default|const|double|else|enum|extern|for|if|goto|float|int|long|register|return|signed|static|sizeof|short|struct|switch|typedef|union|void|while|volatile|unsigned	{strcpy(keywords[i++], yytext);}
({letter}|(_))({letter}|{digit}|(_))*				{strcpy(identifiers[j++], yytext);}
"++"|"--"|"+"|"-"|"*"|"/"|"%"|"<"|"<="|">"|">="|"=="|"!="|"&&"|"||"|"!"|"&"|"|"|"<<"|">>"|"~"|"^"|"="|"+="|"-="|"/="|"%="|"?:"							{strcpy(operators[l++], yytext);}
"["|"]"|"("|")"|"{"|"}"|","|";"|":"|"*"|"#"			{strcpy(punctuators[k++], yytext);}
(("+"|"-")?)({digit}+)(("."{digit}+)?)((E("+"|"-")?{digit}+)?)	{strcpy(numbers[m++], yytext);}
\"(.)*\"							{strcpy(strings[n++], yytext);}
" "*|"\t"*|"\n"*|"#"(.*)					{}
.								{}

%%

int yywrap(void){}

int main() {

	printf("\nEnter the input: \n");

	yylex();
	
	printf("\n\nKeywords:\n");
	for (int idx = 0; idx < i; idx++)
		printf("%s\t", keywords[idx]);
	
	printf("\n\nIdentifier:\n");
	for (int idx = 0; idx < j; idx++)
		printf("%s\t", identifiers[idx]);
		
	printf("\n\nOperators:\n");
	for (int idx = 0; idx < l; idx++)
		printf("%s\t", operators[idx]);
		
	printf("\n\nPunctuators:\n");
	for (int idx = 0; idx < k; idx++)
		printf("%s\t", punctuators[idx]);
		
	printf("\n\nNumbers:\n");
	for (int idx = 0; idx < m; idx++)
		printf("%s\t", numbers[idx]);
		
	printf("\n\nString Literals:\n");
	for (int idx = 0; idx < n; idx++)
		printf("%s\t", strings[idx]);
		
	printf("\n\n");

	return 0;	
}
