%{
	#include "y.tab.h"
%}

letter	[A-Za-z]
digit	[0-9]

%%

{digit}+		{ yylval=atoi(yytext); return DIGIT; }
\n			{ return NL; }
.			{ return yytext[0]; }

%%

int yywrap() {
	return 1;
}
