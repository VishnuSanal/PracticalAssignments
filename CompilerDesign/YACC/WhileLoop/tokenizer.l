%{
	#include "y.tab.h"
%}

letter	[A-Za-z]
digit	[0-9]

%%

while						{ return WHILE; }
true|false					{ return BOOL; }
"||"|"&&"					{ return LOG_OP; }
({letter}|(_))({letter}|{digit}|(_))*		{ return ID; }
(("+"|"-")?)({digit}+)				{ return NUM; }
"<"|"<="|">"|">="|"=="|"!="			{ return REL_OP; }
"("						{ return PAR_OPEN; }
")"						{ return PAR_CLOSE; }
,						{ return COMMA; }
;						{ return SEMICOLON; }

\n						{ return NL; }

%%

int yywrap() {
	return 1;
}
