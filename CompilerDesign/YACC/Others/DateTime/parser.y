%{
#include<stdio.h>
#include<stdlib.h>



%}

%token FOR PARO PARC INT ID EQUALS NUM SEMICOLON RELOP INC_DEC NL

%% 
stmt : S NL   {printf("valid\n"); exit(0);};

S : FOR PARO INIT COND ACTION PARC ;

INIT : INT ID EQUALS NUM SEMICOLON ;

COND : ID RELOP NUM SEMICOLON ;

ACTION : ID INC_DEC ;

%%

int yyerror(char *msg){
printf("\ninvalid string\n");

exit(0);
}

int main(){
printf("enter for\n");
yyparse();
}
