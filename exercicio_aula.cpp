#define TAMANHO 5
#include <iostream>
#include <stdlib.h>
using namespace std;
int numeros[TAMANHO];
//int numeros[TAMANHO] = {0,22,3,4,5};
//==============================================================================000
// Metodo para imprimir o vetor.
void imprimir() {
cout << "\n[ ";
for (int i = 0; i < TAMANHO; i++) {
cout << numeros[i] << " ";
}
cout << "]";
}
//------------------------------------------------------------------------------
/**
* Metodo para incluir um elemento no vetor. A posicao tem que estar vaga

* (valor do elemento igual a zero). O novo elemento tem que ser maior que
* zero.
*
* @param indice - indice do elemento que sera´ incluido.
* @param valor - valor do elemento a ser incluido.
* @return
*/
string incluir(int indice, int valor) {
// verifica se o valor e´ maior que zero
if (valor < 0) {
return "ERRO: o valor tem que ser maior que zero.";
}
// verifica se o indice e´ valido
if (indice < 0 || indice > TAMANHO - 1) {
return "ERRO: o indice esta´ fora dos limites do vetor.";
}
// verifica se a posicao ja´ esta´ ocupada.
if (numeros[indice] > 0) {
return "ERRO: posicao ocupada.";
}
// passou por todas as verificacoes: inserir
numeros[indice] = valor;
return "Inclusao bem sucedida.";
}

string alterar(int index1, int index2){
  if (index1 < 0 || index2 < 0){
    return "Erro: não serão permitidos números negativos";
  }
  //verifica se o índice é válido
  if ((index1 < 0 && index1 > TAMANHO - 1) || (index2 < 0 && index2 > TAMANHO -1)){
    return "Indíce inválido";
  }else{
    int aux = 0;
    aux = numeros[index1];
    numeros[index1] = numeros[index2];
    numeros[index2] = aux;
    return "Deu certo!!";
  }
}

int maiorValor(){

  int aux = 0 ;

  for(int i; i < TAMANHO; i++){
    //[15,3,4,5,6,0]
    if(numeros[i] > aux){
      aux = numeros[i];
    }
  }
  return aux;
}

int menorValor(){
  int aux;
  for(int i = 0; i< TAMANHO; i++){
    if(numeros[i] < aux){
      aux = numeros[i];
    }
  }
  return aux;
}


 
/**
* Excluir um elemento do vetor. Atribui zero `a posicao e retorna o
* elemento (valor).
*
* @param indice - indice do elemento que sera´ excluido.
* @return - valor do elemento excluido. Se retornar zero e´ porque a
* posicao estava vazia; se retornar -1 e´ porque o indice e´ invalido.
*/
int excluir(int indice) {
// verifica se o indice e´ valido
if (indice < 0 || indice > TAMANHO - 1) {
return -1;
}
int numero = numeros[indice];
numeros[indice] = 0;
return numero;
}
//==============================================================================
// MAIN
//==============================================================================
int main() {
//numeros = new int[TAMANHO];
for (int i = 0; i < TAMANHO; i++) {
numeros[i] = 0;
}
while(true) {
system("CLS");
cout << "\n----------------------------------------------";
cout << "\n RELEMBRANDO VETORES";
cout << "\n----------------------------------------------";
cout << "\n0 - sair.";
cout << "\n1 - imprimir o vetor.";
cout << "\n2 - inserir um elemento ( >0 e a posicao no vetor tem que estar livre (=0)";
cout << "\n3 - excluir um elemento.";
cout << "\n4 - trocar dois elementos de lugar entre si.";
cout << "\n5 - localizar o maior e o menor elementos do vetor";
cout << "\n6 - ordenar os elementos do vetor em ordem crescente";
cout << "\n7 - ordenar os elementos do vetor em ordem decrescente";
cout << "\n8 - ordenar os elementos do vetor em um segundo vetor (o metodo cria o novo vetor, copia os dados e retorna o vetor ordenado";
cout << "\n---------------------";
cout << "\nQual a sua opcao -> ";
int opc;
cin >> opc;
if (opc == 0) {
break;
} else if (opc == 1) {
imprimir();
cout << "\n\n";
system("PAUSE");
} else if (opc == 2) {
//= precisa pedir os dados: posicao no vetor (indice) e valor do elemento.
cout << "Indice do novo elemento: ";
int idx;
cin >> idx;
cout << "Valor do novo elemento: ";
int val;
cin >> val;
cout << incluir(idx, val) << endl;
system("PAUSE");
} else if (opc == 3) {
cout << "Indice do elemento a ser removido: ";
int idx;
cin >> idx;
int val = excluir(idx);
if (val == 0) {
cout << "Nao ha´ elemento na posicao " << idx;
} else if (val == -1) {
cout << "ERRO: o indice esta' fora dos limites do vetor.";
} else {
cout << "Valor excluido da posicao " << idx << ": " << val;
} 
cout << "\n\n";
//system("PAUSE");
} else if (opc == 4) {
  //Mudar duas posições
  cout << "Selecione dois índices para trocar de lugar: \n";
  cout << "Indíce 1: ";
  int index1;
  cin >> index1;
  cout << "Indíce 2: ";
  int index2;
  cin >> index2;
  alterar( index1, index2);
} else if (opc == 5) {
  //localizar o maior e menor
  int maior;
  maior = maiorValor();
  cout << "Maior -> " << maior;
  int menor;
  menor = menorValor();
  cout << "Menor -> " << menor;
} else if (opc == 6) {
} else if (opc == 7) {
} else if (opc == 8) {
}
}
system("PAUSE");
cout << "\n-------------------------------------------------";
cout << "\n\nObrigado e ate' a proxima vez.\n\n\n";
return 0;
}

