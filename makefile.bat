echo off
cls
echo code:
echo '

set tree=.\Sudoku_exes\


gcc -c tabuleiro.c -o %tree%tabuleiro.o

gcc %tree%tabuleiro.o main.c -o %tree%exec1



cd %tree%

.\exec1



