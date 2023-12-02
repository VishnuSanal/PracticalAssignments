%{

#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>

int STACK[100];
int TOP = -1;

void push(int);
int pop();

int calculate(int, int, char);

%}

digit		[0-9]
operator	("+"|"-"|"*"|"/")

%%

{digit}+	{push(atoi(yytext));}
{operator}	{push(calculate(pop(), pop(), yytext[0]));}
.		;

%%
  
int yywrap(void){}

int main() {

	printf("\nEnter the operation: \n");

	yylex();
	
	printf("%d", pop());

	printf("\n\n");

	return 0;
}

int calculate(int one, int two, char op) {

	switch (op) {
		case '+':
			return one + two;
		case '-':
			return one - two;
		case '*':
			return one * two;
		case '/':
			return one / two;
		case '%':
			return one % two;
		default:
			return 0;
	}
	
}

bool isOperator(char c) { return c == '+' || c == '-' || c == '*' || c == '/';}

void push(int i) { STACK[++TOP] = i; }

int pop() { return STACK[TOP--]; }
