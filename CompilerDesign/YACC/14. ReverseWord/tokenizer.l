%{
	#include "y.tab.h"
%}

letter	[A-Za-z]
digit	[0-9]

%%

a						{ return A; }
b						{ return B; }
c						{ return C ;}

\n						{ return NL; }

%%

int yywrap() {
	return 1;
}
