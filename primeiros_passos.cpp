#include <iostream>

using namespace std;
int main() {
  //HelloWord
  string olamundo("Hello Word!!!!");
  cout << olamundo;
  //Contando de 0 à 20 com While
  int x = 0;
  while(x>=0 and x<=20){
    cout << '\n';
    cout << x;
    x+=1;
  }
  //Contando em forma decrescente com for
  if (x>20){
  x = x - 1;
  }
  cout << "\n\n\n";
  int i;
  for(i = x; i >=0;i--){
    cout << '\n' << i;
  }
}
