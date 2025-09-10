#ifndef TABULEIRO_H
#define TABULEIRO_H

extern int tabuleiro[9][9];
extern int* idHiddens;

int venceuJogo();
int MatrizContem(int *matriz, int num);
int esconderTabuleiro(int dificuldade);
int tabuleiroValido(int i, int j, int num);
void setarTabuleiro(int i, int j, int num);
int criarTabuleiro();
void printarTabuleiro(int posicao);








#endif