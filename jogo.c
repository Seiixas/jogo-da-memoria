#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Aqui definimos o tamanho do nosso campo em linhas e colunas
#define LINHAS 35
#define COLUNAS 20

int main() {
  // Aqui declaramos as variáveis que vamos utilizar no jogo
  int numeroVerdadeiro, numerosRepetidos, linhaVerdadeiro, colunaVerdeiro, i, j;

  // Alteramos a seed do rand() para gerar sempre números aleatórios baseados na data
  srand(time(NULL));
  
  // Nós geramos os números aleatórios para cada uma das variáveis (entre 0 e 9)
  numeroVerdadeiro = rand() % 10;
  numerosRepetidos = rand() % 10;
  linhaVerdadeiro = rand() % 10;
  colunaVerdeiro = rand() % 10;

  // Desenhamos o nosso campo com (#)
  for(i=0;i<LINHAS;i++) {
    for(j=0;j<COLUNAS;j++) {
      printf("# ");
    }
    printf ("\n");
  }

  return 0;
}
