#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "tabuleiro.h"





int main() {
    srand(time(NULL));
    criarTabuleiro();
    printarTabuleiro();
    int e;
    scanf("%d", &e);
    return 0;
}
