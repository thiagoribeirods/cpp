#include <iostream>
using namespace std;
string buscaBin(int *vetor, int high, int buscar){

//O vetor precisa estar ordenad

  int low = 0, m = 0, cont = 0;
    while(low<=high){
    cont+=1;
    
    m = (low+high)/2;
    if(buscar == vetor[m]){
      cout <<"Comparações -> " << cont << endl;
      return "Encontrei";
    }
  else if(buscar < vetor[m]){
    high = m -1 ;
  }else{
    low = m + 1;
  }
  }

  cout <<"Comparações -> " << cont;
  return "Não encontrei";

}
int main() {
  int vetor[10];
  
  for(int i = 0; i<10;i++){
    cout << "Insira um valor para a posição " << (i+1) << "-> ";
    cin >> vetor[i];
  }

  for(int i = 0; i < 10; i++){
    cout << '[';
    cout << ' ' << vetor[i] << ' ';
    cout << ']';
  }
   int buscar = 0;
  cout << endl;
  cout << "Buscar por -> ";
  cin >>  buscar; 

  //implementando a busca binária
  int high = sizeof(vetor)/4; string resultado;
  resultado = buscaBin(vetor, high, buscar);
  cout << resultado;






}
