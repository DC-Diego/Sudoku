#ifndef TABULEIRO_H
#define TABULEIRO_H

extern int tabuleiro[9][9];


int tabuleiroValido(int i, int j, int num);
void setarTabuleiro(int i, int j, int num);
int criarTabuleiro();
void printarTabuleiro();








#endif