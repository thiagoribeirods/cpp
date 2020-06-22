#include <iostream>

using namespace std;

// classe Node
class Node
{
private:
	int v;
	Node* next;
public:
	Node(int v) // construtor
	{
		this->v = v;
		this->next = NULL;
	}

	int getValue() // obtém o valor
	{
		return v;
	}

	Node* getNext() // obtém o próximo Node
	{
		return next;
	}

	void setNext(Node* node) // seta o próximo Node
	{
		next = node;
	}
};

// classe Queue
class Queue
{
private:
	Node* head; // inicio
	Node* tail; // fim

public:
	Queue()
	{
		
		head = NULL;
		tail = NULL;
	}

	Queue(int v)
	{
		// se passar elemento, então cria Nodevo Node
		head = new Node(v);
		tail = head;
	}

	virtual ~Queue() // destrutor
	{
		delete head;
	}

	void show() // mostra todos os elementos da Queue
	{
		cout << "\n \t -- Exibindo \n";
		Node* c = head;

		if(empty())
			cout << "\n Não há elementos na fila! \n";
		else
		{
			while(c) // percorre a Queue
			{
				cout << c->getValue() << endl;
				c = c->getNext();
			}
			cout << endl;
		}
	}

	bool empty()
	{
		return (head == NULL);
	}

	void insert_at_the_end(int v)
	{
		Node* node = new Node(v);
    //se vazia, insiro no inicio
		if(empty())
		{
			head = node;
			tail = node;
		}
		else
		{
			tail->setNext(node);
			tail = node;
		}
	}



	void remove()
	{
		if(!empty())
		{
			// se houver só 1 elemento
			if(head->getNext() == NULL)
      {
        head = NULL;
        tail = NULL;
      }
      //caso haja apenas 2 elementos
			else if(head->getNext()->getNext() == NULL)
      {
        head = tail;
        tail = head;
      }
      //se houver mais que três elementos
			else
			{
				head = head->getNext();
			}
		}
	}
};

int main(int argc, char *argv[])
{
  cout << "\n\t\t --> Queue ";
	Queue queue;
  bool op = false;
  while(!op)
  {
    cout << "\n \t -- Menu";
    cout << "\n 1 - Inserir" <<
            "\n 2 - Remover" <<
            "\n 3 - Imprimir" <<
            "\n 0 - Sair";
    
    int option = 0, value;
    cout << "\n Opção: "; cin >> option;
    if(option == 1)
    {
      cout << "\n -> Digite um valor: ";
      cin >> value;
      queue.insert_at_the_end(value);
      cout << "\n Inserido com sucesso!";
      queue.show();
    }
    else if(option == 2)
    {
      queue.remove();
      cout << "\n Removido com sucesso!";
      queue.show();
    }
    else if(option == 3)
    {
      queue.show();
    }
    else if(option == 0)
    {
      op = true;
    }
    else
    {
      cout << "Opção inválida!";
    }
  cout << "\n-> Pressione 0 para continuar ou 1 para sair: ";
  cin >> option;
  if(option == 1)
  {
    op = true;
  }
  system("clear||cls");
  }	
	return 0;
}
