#include <iostream>
using namespace std;
int vetor[10];

string linear(int buscar){
  for(int i; i < 10;i++){
    if(buscar == vetor[i]){
      return "Encontrei!";
    }
  }
  return "Não encontrei!";
}

string binario(int buscar){
  //ordenando
    int aux = 0;
    for(int i; i < 10; i++){
      for(int j = 1; j<10; j++){
        if (vetor[i] < vetor [j]){
           aux = vetor[i];
           vetor[i] = vetor[j];
           vetor[j] = aux;
        }
      }
    }

    //busca BINÁRIA
    int primeiro = 0, ultimo = 9, meio = 0;
    while(primeiro <= ultimo){
      meio = (primeiro+ultimo)/2;
      if(vetor[meio] == buscar){
        return "Encontrei!";

      }
      else if(vetor[meio] < buscar){
        primeiro = meio + 1;
      }
      else if(vetor[meio] > buscar){
        ultimo = meio - 1;
      }
      else{
        cout << "Deu ruim!";
      }

    }

    return " Não encontrei!";
}



int main() {
  int usu = 0,x = 0;
  cout << "MENU \n 1 - LINEAR\n 2 - BINÁRIA\n SUA ESCOLHA -> ";
  cin >> usu;
  while (x < 10){
    cout << "Insira um valor para a posição " << x << " do vetor -> ";
    cin >> vetor[x];
    x++;
  }

  if(usu == 1){
    //busca LINEAR
    int buscar = 0; string r;
    cout << "Buscar por -> ";
    cin >> buscar;
    r = linear(buscar);
    cout << r;


  }else if(usu == 2){
    //busca binária
    int buscar;
    string r;
    cout << "Procurar por -> ";
    cin >> buscar;
    r = binario(buscar);
    cout << r;

  }else{
    cout << "Insira um valor válido!";
  }

  
}
