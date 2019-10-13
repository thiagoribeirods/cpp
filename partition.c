//implementação do partition
int partition(int vetor[], int pivo, int right){
	//declarção das variáveis
	int aux = 0 /*ajuda na hora da troca */, j = pivo /*para comparar com o pivô*/;
	int i = pivo + 1;
	for(i; i < right; i++){
		if(vetor[i] < vetor[pivo]){
			aux = vetor[i];
			vetor[i] = vetor[j];
			vetor[j] = aux;
			j+=1;	
		}	
	}
	
	aux = vetor[pivo];
	vetor[pivo] = vetor[j];
	vetor[j] = aux;
	
	return j;

}
