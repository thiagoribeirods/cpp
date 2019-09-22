#include <stdio.h>
#include <stdlib.h>
//criando max heap
void afunda(int *vetor, int tamanho, int i)
{
	int r, valor;
	valor = vetor[i];
	
	while(i <= tamanho/2)
	{
		r = 2 * i;
		
		if(r < tamanho && vetor[r] < vetor[r + 1]) r++;
		
		if(valor >= vetor[r]) break;
		
		vetor[i] = vetor[r];
		i = r;
	}
	
	vetor[i] = valor;
	
	
}
//def para ordenar
void heapsort(int *vetor, int tamanho)
{
	int i = 0, aux = 0;
	for(i = tamanho/2; i >= 0; i--) heapmax(vetor, tamanho, i); //precisa transformar/verificar se é max heap
	
	while(tamanho > 0)
	{
		aux = vetor[0];
		vetor[0] = vetor[tamanho];
		vetor[tamanho] = aux;
		heapmax(vetor, --tamanho, 0);
	}	
	
}

//classe principal
int main(int argc, char *argv[]) 
{
	int vetor[] = {20, 15, 14, 10, 8, 13, 9, 6};
	int tamanho = 8;
	int i;
	
	heapSort(vetor, tamanho);
	
	for(i=0;i<=tamanho-1;i++)
	{
		printf("[ %d ", vetor[i]);
		printf("]");

	}
	
	printf("\n");
	system("pause");
	
	return 0;
}
