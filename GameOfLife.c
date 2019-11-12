#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/*
	Autores: - Breno Fernandes 41890590 - Gustavo Aveloes 41882318 - Thiago Ribeiro 41891147
*/

int mapa[25][25] = { 0 };

int vetProximaGeracao[25][25];

void printMapa()
{
	int i, j;
	//exibindo mapa
	for (i = 0; i < 25; i++) {
		printf("[ ");
		for (j = 0; j < 25; j++) {
			printf("%i  ", mapa[i][j]);
		}
		printf(" ]");
		printf("\n");
	}
}

void limpaVetProximaGeracao()
{
	int i, j;
	for (i = 0; i < 25; i++) {
		for (j = 0; j < 25; j++) {
			vetProximaGeracao[i][j] = 0;
		}
	}
}

void proximaGeracao(int quantidadeDeGeracoes)
{
	int a, b, c, d, e;
	e = 0;
	int vivos;
	while (e < quantidadeDeGeracoes) {
		//Preeche o vetor auxiliar com zeros
		limpaVetProximaGeracao();

		for (a = 0; a < 25; a++) {
			for (b = 0; b < 25; b++) {
				vivos = 0;
				for (c = -1; c < 2; c++) {
					for (d = -1; d < 2; d++) {
						vivos += mapa[a + c][b + d];
					}
				}
				vivos -= mapa[a][b];

				//a celula morre por solidão
				if (mapa[a][b] == 1 && vivos < 2) {
					vetProximaGeracao[a][b] = 0;
				}
				//condição para nascer uma célula
				else if (mapa[a][b] == 0 && vivos == 3) {
					vetProximaGeracao[a][b] = 1;
				}
				//morre de superpopulação
				else if (mapa[a][b] == 1 && vivos > 3) {
					vetProximaGeracao[a][b] = 0;
				}
				//termina de preencher o mapa
				else {
					vetProximaGeracao[a][b] = mapa[a][b];
				}
			}
		}
		int i, j;
		//exibindo mapa
		for (i = 0; i < 25; i++) {
			printf("[ ");
			for (j = 0; j < 25; j++) {
				printf("%i  ", vetProximaGeracao[i][j]);
			}
			printf(" ]");
			printf("\n");
		}
		printf("\n");

		//Atualiza mapa com a nova geracao
		memcpy(mapa, vetProximaGeracao, 25 * 25 * sizeof(int));
		//sleep(2);
		e++;
	}
}

int main()
{
	printf("\tGame Of Life - Conway");
	int i, j, k, l, x, y, quantidade, geracoes;
	printf("\n Insira quantas celula voce quer povoar -> ");
	scanf("%i", &quantidade);
	l = 0;
	while (l < quantidade) {
		printf("\nInsira as coordenadas desejadas -> ");
		printf("\nEixo X -> ");
		scanf("%i", &x);

		printf("\nEixo Y -> ");
		scanf("%i", &y);

		mapa[x][y] = 1;
		l++;
	}

	printMapa();
	printf("\nInsira o numero de geracoes -> ");
	scanf("%i", &geracoes);
	proximaGeracao(geracoes);

	return 0;
}
