#include <iostream>
#define tamanho 8


using namespace std;

typedef struct{
      int topo;
      int item [tamanho] ;
}PILHA;

void iniciaPilha (PILHA &p) {
     p.topo = -1 ;
}

bool pilhaVazia(PILHA &p){
    if(p.topo == -1 )
        return true;
    else
        return false;
}

bool pilhaCheia(PILHA &p){
    if (p.topo == tamanho-1)
        return true;
    else
        return false;
}

void empilha(PILHA &p, char x){
    p.item[++p.topo]=x;
}

int desempilha(PILHA &p){
    return (p.item[p.topo--]) ;
}

string verificaExpressao(PILHA &s, string empilhar, int limite){
	int i = 0;
	while(i < limite){
		
		if(empilhar[i] == '(' || empilhar[i] == '[')
		{
			empilha(s,empilhar[i]);
			i+=1;
		}
		else if(empilhar[i] == ')' || empilhar[i] == ']'){
			if(s.topo == '(' && empilhar[i] == ')'){
				desempilha(s);
				i+=1;
				
			}
			else if(s.topo == '[' && empilhar[i] == ']' ){
				desempilha(s);
				i+=1;
			}else{
				cout << "Expressão inválida!" << endl;
				break;
			}
		}else{
			cout << "Vc não digitou uma expressão válida!";
			break;
		}
    	return "Expressão válida!";
	}

	
}
int main(){
    PILHA s ;

    iniciaPilha (s);
    //empilhando a sequência da expressão
	string empilhar, r;
	int x = 0;
	//pego a expressão
	cout << "Insira uma expressão -> ";
	cin >> empilhar;
	int j = 0, limite = 0;
	while(empilhar[j] != '\0'){
	
		j += 1;
		limite += 1;	
	}
	r = verificaExpressao(s, empilhar, limite);
	cout << r;

  return 0;
}
