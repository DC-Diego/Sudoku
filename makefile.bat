echo off
cls
echo code:
echo '

set tree=C:\Users\Micro\Desktop\C\Sudoku_exes\


gcc -c tabuleiro.c -o %tree%tabuleiro.o

gcc %tree%tabuleiro.o main.c -o %tree%exec



cd %tree%
color 0a



.\exec

pause

