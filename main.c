#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

#include "tabuleiro.h"


int posicao = 00;
int jogando = 1;

void cleanBuffer(){
    while (kbhit()) getch(); 
}

void jogo(){
    while(1){
        if(kbhit()){
            int tecla = getch();
            if(tecla == 27){ // ESC
                jogando = 0;
                printf("Saindo...\n");
                break;
            }else if(tecla >= '0' && tecla <= '9'){
                if(MatrizContem(idHiddens, posicao)){
                    int num = tecla - '0';
                    setarTabuleiro( posicao/9, posicao%9 ,num);
                  //  printf("%d",num);
                    
                }
            }else if(tecla = 224){ // setas
                tecla = getch();
                int ddx;
                switch (tecla)
                {
                    case 72: // ↑
                    ddx = (posicao / 9) - 1;
                    posicao = 9 * (ddx < 0 ? 8 : (ddx > 8 ? 0 : ddx)) + (posicao % 9);
                    break;

                case 80: // ↓
                    posicao = (posicao + 9) % 81;
                    break;

                case 75: // ←
                    ddx = (posicao % 9) - 1;
                    posicao = (posicao / 9) * 9 + (ddx > 8 ? 0 : (ddx < 0 ? 8 : ddx));
                    break;

                case 77: // →
                    ddx = (posicao % 9) + 1;
                    posicao = (posicao / 9) * 9 + (ddx > 8 ? 0 : (ddx < 0 ? 8 : ddx));
                    break;
                    default: printf("Outra tecla especial: %d\n", tecla);
                }


            }
            cleanBuffer();
            system("cls");
            printarTabuleiro(posicao);
        }
        if(venceuJogo()){
            printf("VOCE VENCEU!");
            getchar();
        }
        Sleep(400);
    }
}


int main() {
    srand(time(NULL));
    criarTabuleiro();
    esconderTabuleiro(2);
    printarTabuleiro(posicao);
    jogo();
    return 0;
}
