%{

// int i , arr [ 10 ] , * i ;

	#include "y.tab.h"
%}

letter	[A-Za-z]
digit	[0-9]

%%

int|float|bool|char			{ return D_TYPE; }
({letter}|(_))({letter}|{digit}|(_))*	{ return _ID; }

"["					{ return ARR_START; }
"]"					{ return ARR_END; }
({digit}+)				{ return NUM; }

,					{ return COMMA; }
;					{ return SEMICOLON; }
"*"					{ return STAR; }

\n					{ return NL; }


%%

int yywrap() {
	return 1;
}
