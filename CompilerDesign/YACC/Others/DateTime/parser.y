// Valid    : 2021-09-21 12:24:60
// Invalid  : 2021-23-21 12:24:60
%{
    #include <stdio.h>
    #include <stdlib.h>
%}

%token DIGIT HYPHEN SPACE COLON NL

%%
 
stmt: S NL { printf("Valid\n"); exit(0); };

S : DATE SPACE TIME ;

DATE    : YEAR HYPHEN MONTH HYPHEN DAY ;
YEAR    : DIGIT ;
MONTH   : DIGIT { if (yylval > 12) { printf("Invalid Month\n"); exit(0); } } ;
DAY     : DIGIT { if (yylval > 31) { printf("Invalid Day\n"); exit(0); } } ;

TIME    : HOUR COLON MINUTE COLON SECOND ;
HOUR    : DIGIT { if (yylval > 23) { printf("Invalid Hour\n"); exit(0); } } ;
MINUTE  : DIGIT { if (yylval > 60) { printf("Invalid Minute\n"); exit(0); } } ;
SECOND  : DIGIT { if (yylval > 60) { printf("Invalid Minute\n"); exit(0); } } ;

%%

int main() {
    printf("Enter the string: ");
    yyparse();

    return 0;
}

int yyerror(char* c) {
    printf("Invalid\n");
    return 1;
}
