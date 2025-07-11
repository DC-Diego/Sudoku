#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tabuleiro.h"



int tabuleiro[9][9] = {0};
int* idHiddens;


int MatrizContem(int *matriz, int size, int num){
  for(int h = 0; h < size;h++){
    if(idHiddens[h]==num)
    return 1;
  }


  return 0;
}


int esconderTabuleiro(int dificuldade){
  idHiddens = (int*) malloc(sizeof(int)*10*dificuldade);
  for (int i = 0; i < 10*dificuldade; i++)
  {
    int num;
    do{
      num = rand()%81;
    }while(MatrizContem(idHiddens, i, num));
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
    if(tabuleiro[i][x]==num)
      return 0;

  } 
  for (int y = 0; y < 9; y++)
  {
    if(tabuleiro[y][j]==num)
      return 0;
  }
  //cubo



  for (int x = i/3*3; x < i/3*3+3; x++)
  {
    for (int y = j/3*3; y< j/3*3+3; y++)
    {

      if(tabuleiro[x][y]== num)
        return 0;
    
   }
  


  }
  


/*

 1 2 3  1 2 3  1 2 3   x
 1 2 3  1 2 3  1 2 3
 1 2 3  1 2 3  1 2 3

 1 2 3  1 2 3  1 2 3
 1 2 3  1 2 3  1 2 3
 1 2 3  1 2 3  1 2 3

 1 2 3  1 2 3  1 2 3
 1 2 3  1 2 3  1 2 3
 1 2 3  1 2 3  1 2 3
y
*/



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


void printarTabuleiro(){
  printf("Tabuleiro:\n");
  for (int i = 0; i < 9; i++)
  {
    for (int j = 0; j < 9; j++)
    {
      printf("%d ",tabuleiro[i][j]);
      if(j%3==2)
        printf("  ");
    }
     if(i%3==2)
        printf("\n");
    printf("\n");
  }



}


