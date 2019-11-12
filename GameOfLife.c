#include <stdio.h>
#include <stdlib.h>

int mapa[15][15];
int vetProximaGeracao[15][15];

void printMapa(int mapa[15][15])
{	
	int i, j;
	//exibindo mapa
	for(i = 0; i < 15; i++)
    {
        printf("[ ");
        for(j = 0; j < 15; j++)
        {
            printf("%i  ", mapa[i][j]);
        }
        printf(" ]");
        printf("\n");
    }
}

void proximaGeracao(int mapa[15][15], int quantidadeDeGeracoes)
{
	int a,b,c,d, e;
	e = 0;
	while(e < quantidadeDeGeracoes)
	{
		for(a = 0; a < 15; a++)
		{
			for(b = 0; b < 15; b++)
			{
				int vivos = 0;
				for(c = -1; c < 2; c++)
				{
					for(d = -1; d < 2; d++)
					{
						vivos+=mapa[a+c][b+d];
					}
				}
				vivos -= mapa[a][b];
				//a celula morre por solidão
				if(mapa[a][b] == 1 && vivos < 2)
				{
					vetProximaGeracao[a][b] = 0;
					
				}
				//condição para nascer uma célula
				else if(mapa[a][b] == 0 && vivos == 3)
				{
					vetProximaGeracao[a][b] = 1;
				}
				//morre de superpopulação
				else if(mapa[a][b] == 1 && vivos > 3)
				{
					vetProximaGeracao[a][b] = 0;
				}
				//termina de preencher o mapa
				else
				{
					vetProximaGeracao[a][b] = mapa[a][b];	
				}
			}
		}
		int i, j;
		//exibindo mapa
		for(i = 0; i < 15; i++)
    	{
        	printf("[ ");
        	for(j = 0; j < 15; j++)
        	{
            	printf("%i  ", vetProximaGeracao[i][j]);
        	}
        	printf(" ]");
        	printf("\n");
    	}
		printf("\n");
		sleep(2);
		e++;	
	}
}

int main(int argc, char *argv[]) {
    printf("\tGame Of Life - Conway");
    int i,j,k,l,x,y,quantidade,geracoes;
    printf("\n Insira quantas celula voce quer povoar -> ");
    scanf("%i",&quantidade);
    l=0;
    while(l<quantidade)
    {
        printf("\nInsira as coordenadas desejadas -> ");
        printf("\nEixo X -> ");
        scanf("%i", &x);
        printf("\nEixo Y -> ");
        scanf("%i", &y);
        for(i=0;i<15;i++)
        {
            for(j=0;j<15;j++)
            {
                if(i==x && j==y)
                {
                    mapa[i][j]=1;
                }
                else
                {
                	if(mapa[i][j]==1)
                	{
                		mapa[i][j]=1;
					}
					else
					{
						mapa[i][j]=0;
					}
				}  
            }
        }
        l++;     
    }
    printMapa(mapa);
    printf("\nInsira o numero de geracoes -> ");
    scanf("%i",&geracoes);
	proximaGeracao(mapa,geracoes);
	system("pause");
    return 0;
}
