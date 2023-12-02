# YACC

## How to complile?

- `lex tokenizer.l`
- `yacc parser.y -d`
- `cc lex.yy.c y.tab.c -w`
- `./a.out`

## Questions

- **10:** `a^n b^n` (`n >= 1`)
- **11:** `(a|b)*abb`
- **12:** `a^n b^m c^m d^n` (`n,m >= 1`)
- **13:** `a^n b^(n+m) c^m` (`n,m >= 1`)
- **14:** `w c w^R` (`w = (a|b)*`)
- **15:** `a*b*`
- **16:** YACC program to check syntax of C variable declaration
- **17:** YACC program to check syntax of for loop declaration in C
- **18:** YACC program to check syntax of Function Declaration in C
- **19:** YACC program to implement Calculator
- **20:** YACC program for Infix to Postfix Conversion
