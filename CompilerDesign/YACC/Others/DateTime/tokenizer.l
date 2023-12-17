%{
	#include "y.tab.h"
%}

digit [0-9]
letter [a-zA-Z]

%%
for 	{return FOR;}
int 	{return INT;}

(("+"|"-")?)({digit}+)	{return NUM;}

"("		{return PARO;}
")"		{return PARC;}

({letter}|(_))|({letter}|{digit}|(_))*	{return ID;}

"="		{return EQUALS;}
";"		{return SEMICOLON;}

("<"|">")		{return RELOP;}

"++"|"--"	{return INC_DEC;}

\n       {return NL;}
.		{}

%%
int yywrap(){
return 1;
}
