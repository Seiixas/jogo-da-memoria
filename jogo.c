#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Aqui definimos o tamanho do nosso campo em linhas e colunas
#define LINHAS 20
#define COLUNAS 35

/*
 * Função desenharCampo();
 * Parâmetros     : repetidos, verdadeiro, posLInha e posColuna (todos inteiros)
 * Retorno        : nenhum
 * Funcionalidade : desenhar o tabuleiro (ou campo) do jogo contendo os números
 *
*/
void desenharCampo(int repetidos, int verdadeiro, int posLinha, int posColuna) {
	int i, j;
	
	// Desenha o campo do jogo
	for(i = 0; i < LINHAS; i++) {
		for(j = 0; j < COLUNAS; j++) {
			
			// Verifica se a posição atual (linha x coluna) é igual a posição gerada randomicamente
			if (posLinha == i && posColuna == j) {
				printf ("%d ", verdadeiro); // Caso sim, imprime o valor verdadeiro
			} else {
				printf ("%d ", repetidos);  // Caso não, imprime os números repetidos
			}
		}
		printf ("\n");
	}
}

/*
 * Função mostrarMenu();
 * Parâmetros     : nenhum
 * Retorno        : nenhum
 * Funcionalidade : mostrar em tela o menu do nosso jogo
 *
*/
void mostarMenu() {
	printf (" ========================= JOGO DA MEMÓRIA ========================= \n");
	printf (" =        O jogo consiste em um tabuleiro de 35 x 20 números       = \n");
	printf (" =       Neste tabuleiro serão gerados vários números repetidos    = \n");
	printf (" = Com exceção de um número! O jogador deve descobrir esse número  = \n");
	printf (" =  O tabuleiro desaparecerá em 3 segundos para testar a agilidade = \n");
	printf (" =                            BOA SORTE!                           = \n");
	printf (" =================================================================== \n");
	printf ("\n\n");
	printf ("Desenvolvedores: Pedro Lucas | Suellen Alves | Mateus Seixas | Thiago");
	printf ("\nCopyright: Rocket Team");
	
	printf ("\n\nPressione ENTER para começar!!");
	
	setbuf(stdin, NULL);
	getchar();
	
	system ("clear");
}

int main() {
  // Aqui declaramos as variáveis que vamos utilizar no jogo
  int numeroVerdadeiro, numerosRepetidos, linhaVerdadeiro, colunaVerdeiro, resultado, pontuacao = 0, tentativas;  

  mostarMenu();

  for(tentativas = 1; tentativas <= 10; tentativas++) {
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

	desenharCampo(numerosRepetidos, numeroVerdadeiro, linhaVerdadeiro, colunaVerdeiro);

    // Esperar 3 segundos
    system("sleep 3");

    // Limpa a tela
    system("clear");

    // Pedir ao usuário o resultado do jogo
    printf ("\nDigite o número que não foi repetido: ");
    scanf ("%d", &resultado);

    // Verifica se o resultado que o usuário digitou é igual ao número verdadeiro gerado
    if (resultado == numeroVerdadeiro) {
      printf ("\nACERTOU!!\n");
      pontuacao++; // Acresentar a pontuação do jogo
    } else {
      printf ("\nERROU\n");
      
      // Verifica se a pontuação do jogador é maior que 0;
      if (pontuacao > 0) {
		  pontuacao--; // Remover a pontuação do jogo
	  }
	  
    }
  }
    
  printf ("PONTUAÇÃO FINAL : %d\n\n", pontuacao);

  return 0;
}
