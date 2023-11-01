%{
	#include "y.tab.h"
%}

letter	[A-Za-z]
digit	[0-9]

%%

for						{ return FOR; }
int						{ return INT; }
({letter}|(_))({letter}|{digit}|(_))*		{ return _ID; }
(("+"|"-")?)({digit}+)				{ return NUM; }
= 						{ return EQUALS; }
"<"|"<="|">"|">="|"=="|"!="			{ return REL_OP; }
"++"|"--"					{ return INC_DEC; }
"("						{ return PAR_OPEN; }
")"						{ return PAR_CLOSE; }
"{"						{ return BR_OPEN; }
"}"						{ return BR_CLOSE; }
,						{ return COMMA; }
;						{ return SEMICOLON; }

\n						{ return NL; }

%%

int yywrap() {
	return 1;
}
