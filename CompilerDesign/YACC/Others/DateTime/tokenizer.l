%{
    #include "y.tab.h"
%}

%%

[0-9]+   { yylval = atoi(yytext); return DIGIT; }
"-"     { return HYPHEN; }
" "     { return SPACE; }
":"     { return COLON; }
"\n"    { return NL; }            

.       { return yytext[0]; }

%%

int yywrap() {
    return 1;
}
