# YACC

## How to complile?

- `lex tokenizer.l`
- `yacc parser.y -d`
- `cc lex.yy.c y.tab.c -w`
- `./a.out`
