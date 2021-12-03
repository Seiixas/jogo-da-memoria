#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Aqui definimos o tamanho do nosso campo em linhas e colunas
#define LINHAS 10
#define COLUNAS 10

int main() {
  // Aqui declaramos as variáveis que vamos utilizar no jogo
  int numeroVerdadeiro, numerosRepetidos, linhaVerdadeiro, colunaVerdeiro, i, j, resultado;

  // Alteramos a seed do rand() para gerar sempre números aleatórios baseados na data
  srand(time(NULL));
  
  // Nós geramos os números aleatórios para cada uma das variáveis (entre 0 e 9)
  linhaVerdadeiro = rand() % LINHAS;
  colunaVerdeiro = rand() % COLUNAS;

  // Sorteia o numerosRepetidos e numeroVerdeiro até que os números gerados sejam diferentes
  do {
    numeroVerdadeiro = rand() % 10;
    numerosRepetidos = rand() % 10;
  } while(numeroVerdadeiro == numerosRepetidos);

  // Desenhamos o nosso campo com (#)
  for(i=0;i<LINHAS;i++) {
    for(j=0;j<COLUNAS;j++) {

      // Verifica se a linha atual e a coluna atual correspondem à linha e coluna geradas randomicamento
      if(i == linhaVerdadeiro && j == colunaVerdeiro) {
        printf ("%d ", numeroVerdadeiro); // Imprimir o número verdadeiro
      } else {
        printf("%d ", numerosRepetidos); // Imprimir os números repetidos
      }
    }
    printf ("\n");
  }

  // Esperar 3 segundos
  system("sleep 3");

  // Limpa a tela
  system("clear");

  // Pedir ao usuário o resultado do jogo
  printf ("\nDigite o número que não foi repetido: ");
  scanf ("%d", &resultado);

  // Verifica se o resultado que o usuário digitou é igual ao número verdadeiro gerado
  if (resultado == numeroVerdadeiro) {
    printf ("\nACERTOU!!");
  } else {
    printf ("\nERROU");
  }

  return 0;
}
