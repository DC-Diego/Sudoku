#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tabuleiro.h"



int tabuleiro[9][9] = {0};
int* idHiddens;
int hiddenSize = 0;

int MatrizContem(int *matriz, int num){
  for(int h = 0; h < hiddenSize;h++){
    if(idHiddens[h]==num)
    return 1;
  }


  return 0;
}


int esconderTabuleiro(int dificuldade){
  idHiddens = (int*) malloc(sizeof(int)*10*dificuldade);
  hiddenSize = 10*dificuldade;
  for (int i = 0; i < 10*dificuldade; i++)
  {
    int num;
    do{
      num = rand()%81;
    }while(MatrizContem(idHiddens, num));
    idHiddens[i] = num;

  }
  for(int i =0; i < 10*dificuldade; i++){
    tabuleiro[idHiddens[i]/9][idHiddens[i]%9] = 0;
  }


}



int tabuleiroValido(int i, int j, int num){
  //linha
  for (int x = 0; x < 9; x++)
  {
    if(tabuleiro[i][x]==num && x!=j)
      return 0;

  } 
  for (int y = 0; y < 9; y++)
  {
    if(tabuleiro[y][j]==num && y!=i)
      return 0;
  }
  //cubo



  for (int x = i/3*3; x < i/3*3+3; x++)
  {
    for (int y = j/3*3; y< j/3*3+3; y++)
    {

      if(tabuleiro[x][y]== num && x!=i &&y!=j )
        return 0;
   }
  


  }
  return 1;
}
int venceuJogo(){
  for (int i = 0; i < 9; i++)
  {
    for (int j = 0; j < 9; j++)
    {
      if(tabuleiro[i][j]==0 || tabuleiroValido(i,j,tabuleiro[i][j]) == 0){
        return 0;
      }
    }
  }
  return 1;  





}

void setarTabuleiro(int i, int j, int num){
  tabuleiro[i][j] = num;
}

int criarTabuleiro(){
  
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (tabuleiro[i][j] == 0) {
        int numeros[9] = {1,2,3,4,5,6,7,8,9};

        // Embaralha os números
        for (int k = 8; k > 0; k--) {
          int r = rand() % (k + 1);
          int temp = numeros[k];
          numeros[k] = numeros[r];
          numeros[r] = temp;
        }

        for (int k = 0; k < 9; k++) {
          if (tabuleiroValido(i, j, numeros[k])) {
            tabuleiro[i][j] = numeros[k];

            if (criarTabuleiro())
              return 1;
            tabuleiro[i][j] = 0; // desfaz tentativa (backtrack)
          }
        }
        return 0; 
      }
    }
  }
  return 1;
}

int aux = 1;
void printarTabuleiro(int posicao){
  aux = (aux)?0:1;
  for (int i = 0; i < 9; i++)
  {
    for (int j = 0; j < 9; j++)
    {
      int color = (i*9+j==posicao )  ?91:(MatrizContem(idHiddens, i*9+j))?37:33  ;
      
      if(tabuleiro[i][j]) 
        printf("|\033[1;%dm %d \033[0m", color,tabuleiro[i][j]);
      else
        printf("|\033[1;91m %c \033[0m", (color==91)?'*':' ');
      
      if(j%3==2)
        printf("|  ");
      
    }
    if(i%3==2)
      printf("\n");
    printf("\n");
  }

}


