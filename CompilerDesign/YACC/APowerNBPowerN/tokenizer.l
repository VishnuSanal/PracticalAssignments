%{
	#include "y.tab.h"
%}

%%

[aA|a]	{ return A; }
[bB|b]	{ return B; }
\n	{ return NL; }
.	{ return yytext[0]; }

%%

int yywrap() {
	return 1;
}
