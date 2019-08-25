# 15CSL67 - System Software and Operating System Laboratory

## Installation

Install Lex and Yacc in Ubuntu 18:

```sh
sudo apt install flex bison
```

## Instructions

Execute the [Lex](https://en.wikipedia.org/wiki/Lex_(software)) programs using the following commands in a linux terminal:

```sh
lex prog.l
cc lex.yy.c
./a.out
```

Execute the [Yacc](https://en.wikipedia.org/wiki/Yacc) programs using the following commands in a linux terminal:

```sh
lex prog.l
yacc -d prog.y
cc lex.yy.c y.tab.c
./a.out
```
