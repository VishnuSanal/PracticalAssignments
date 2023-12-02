%{
	#include "y.tab.h"
%}

letter	[A-Za-z]
digit	[0-9]

%%

int|float|bool|char				{ return D_TYPE; }
void						{ return VOID; }
({letter}|(_))({letter}|{digit}|(_))*		{ return ID; }

"("						{ return PAR_OPEN; }
")"						{ return PAR_CLOSE; }

,						{ return COMMA; }
;						{ return SEMICOLON; }

\n						{ return NL; }

%%

int yywrap() {
	return 1;
}
