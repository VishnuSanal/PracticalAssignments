%{

// while ( true ) ;
// while ( i <= 10 ) ;
// while ( i <= j ) ;
// while ( i <= j && j > 10 ) ;
// while ( i <= j || j > 10 ) ;

	#include <stdio.h>
	#include <stdlib.h>
%}

%token WHILE ID NUM BOOL LOG_OP REL_OP PAR_OPEN PAR_CLOSE COMMA SEMICOLON NL

%%

stmt : S NL 							{ printf("Valid\n"); exit(0); };
S : WHILE PAR_OPEN COND PAR_CLOSE SEMICOLON ;
COND : COND LOG_OP SINGLE_COND | SINGLE_COND ;
SINGLE_COND : BOOL | ID REL_OP NUM | ID REL_OP ID ;

%%

int yyerror(char *msg) {
	printf("Invalid\n");
	exit(0);
}

int main() {
	printf("Enter the string: ");
	yyparse();
}
