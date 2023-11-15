%{
	#include "y.tab.h"
%}

letter	[A-Za-z]
digit	[0-9]

%%

{letter}({letter}|{digit})*  	{ yylval=*yytext; return ID; }
{digit}+			{ yylval=atoi(yytext); return DIGIT; }
\n				{ return NL; }
.				{ return *yytext; }

%%

int yywrap() {
	return 1;
}
