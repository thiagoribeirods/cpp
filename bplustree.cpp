//código para estudar
#include <climits>
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int MAX = 3;

//definição do Nó
class Node {
  bool IS_LEAF;
  int *key, size;
  Node **ptr;
  friend class BPTree;

   public:
  Node();
};
//Definição da árvore
class BPTree {
  Node *root;
  void insertInternal(int, Node *, Node *);
  Node *findParent(Node *, Node *);

   public:
  BPTree();
  void search(int);
  void insert(int);
  void display(Node *);
  Node *getRoot();
};

//construtr de nós
Node::Node() {
  key = new int[MAX];
  ptr = new Node *[MAX + 1];
}

//construtor de árvore
BPTree::BPTree() {
  root = NULL;
}

//função de pesquisa
void BPTree::search(int x) {
  if (root == NULL) 
  {
    cout << "Sua árvore está vazia!\n";
  } else 
  {
    Node *cursor = root;
    while (cursor->IS_LEAF == false)
    {
      for (int i = 0; i < cursor->size; i++) 
      {
        if (x < cursor->key[i]) 
        {
          cursor = cursor->ptr[i];
          break;
        }
        if (i == cursor->size - 1) 
        {
          cursor = cursor->ptr[i + 1];
          break;
        }
      }
    }
    for (int i = 0; i < cursor->size; i++) 
    {
      if (cursor->key[i] == x) 
      {
        cout << "\nElemento está presente na árvore!\n";
        return;
      }
    }
    cout << "\nElemento não encontrado!\n";
  }
}

//função de inserção
void BPTree::insert(int x) 
{
  //se não houver raiz, insere um elemento raíz
  if (root == NULL) 
  {
    root = new Node;
    root->key[0] = x; //a raiz aponta para o primeiro elemento
    root->IS_LEAF = true; //a raíz é a única folha que temos
    root->size = 1;//definimos como 1 o tamanho da árvore
  } 
  else //se tiver, adicionamos no nó existente
  {
    Node *cursor = root; //criamos um cursor que vai da raíz para cima
    Node *parent;
    while (cursor->IS_LEAF == false) 
    {
      parent = cursor; //pai é a raíz, nesse momento
      for (int i = 0; i < cursor->size; i++) 
      {
        //vamos descendo na árvore conforme as propriedades da árvore B+
        if (x < cursor->key[i]) 
        {
          cursor = cursor->ptr[i];
          break;
        }
        if (i == cursor->size - 1) 
        {
          cursor = cursor->ptr[i + 1];
          break;
        }
      }
    }
    if (cursor->size < MAX) 
    {
      int i = 0;
      while (x > cursor->key[i] && i < cursor->size)
        i++;
      for (int j = cursor->size; j > i; j--) 
      {
        cursor->key[j] = cursor->key[j - 1];
      }
      cursor->key[i] = x;
      cursor->size++;
      cursor->ptr[cursor->size] = cursor->ptr[cursor->size - 1];
      cursor->ptr[cursor->size - 1] = NULL;
    } 
    else 
    {
      Node *newLeaf = new Node;
      int virtualNode[MAX + 1];
      for (int i = 0; i < MAX; i++) 
      {
        virtualNode[i] = cursor->key[i];
      }
      int i = 0, j;
      while (x > virtualNode[i] && i < MAX)
        i++;
      for (int j = MAX + 1; j > i; j--) {
        virtualNode[j] = virtualNode[j - 1];
      }
      virtualNode[i] = x;
      newLeaf->IS_LEAF = true;
      cursor->size = (MAX + 1) / 2;
      newLeaf->size = MAX + 1 - (MAX + 1) / 2;
      cursor->ptr[cursor->size] = newLeaf;
      newLeaf->ptr[newLeaf->size] = cursor->ptr[MAX];
      cursor->ptr[MAX] = NULL;
      for (i = 0; i < cursor->size; i++) 
      {
        cursor->key[i] = virtualNode[i];
      }
      for (i = 0, j = cursor->size; i < newLeaf->size; i++, j++) 
      {
        newLeaf->key[i] = virtualNode[j];
      }
      if (cursor == root) 
      {
        Node *newRoot = new Node;
        newRoot->key[0] = newLeaf->key[0];
        newRoot->ptr[0] = cursor;
        newRoot->ptr[1] = newLeaf;
        newRoot->IS_LEAF = false;
        newRoot->size = 1;
        root = newRoot;
      } 
      else 
      {
        insertInternal(newLeaf->key[0], parent, newLeaf);
      }
    }
  }
}

// Insert Operation
void BPTree::insertInternal(int x, Node *cursor, Node *child) {
  if (cursor->size < MAX) {
    int i = 0;
    while (x > cursor->key[i] && i < cursor->size)
      i++;
    for (int j = cursor->size; j > i; j--) {
      cursor->key[j] = cursor->key[j - 1];
    }
    for (int j = cursor->size + 1; j > i + 1; j--) {
      cursor->ptr[j] = cursor->ptr[j - 1];
    }
    cursor->key[i] = x;
    cursor->size++;
    cursor->ptr[i + 1] = child;
  } else {
    Node *newInternal = new Node;
    int virtualKey[MAX + 1];
    Node *virtualPtr[MAX + 2];
    for (int i = 0; i < MAX; i++) {
      virtualKey[i] = cursor->key[i];
    }
    for (int i = 0; i < MAX + 1; i++) {
      virtualPtr[i] = cursor->ptr[i];
    }
    int i = 0, j;
    while (x > virtualKey[i] && i < MAX)
      i++;
    for (int j = MAX + 1; j > i; j--) {
      virtualKey[j] = virtualKey[j - 1];
    }
    virtualKey[i] = x;
    for (int j = MAX + 2; j > i + 1; j--) {
      virtualPtr[j] = virtualPtr[j - 1];
    }
    virtualPtr[i + 1] = child;
    newInternal->IS_LEAF = false;
    cursor->size = (MAX + 1) / 2;
    newInternal->size = MAX - (MAX + 1) / 2;
    for (i = 0, j = cursor->size + 1; i < newInternal->size; i++, j++) {
      newInternal->key[i] = virtualKey[j];
    }
    for (i = 0, j = cursor->size + 1; i < newInternal->size + 1; i++, j++) {
      newInternal->ptr[i] = virtualPtr[j];
    }
    if (cursor == root) {
      Node *newRoot = new Node;
      newRoot->key[0] = cursor->key[cursor->size];
      newRoot->ptr[0] = cursor;
      newRoot->ptr[1] = newInternal;
      newRoot->IS_LEAF = false;
      newRoot->size = 1;
      root = newRoot;
    } else {
      insertInternal(cursor->key[cursor->size], findParent(root, cursor), newInternal);
    }
  }
}

//encontra no pai
Node *BPTree::findParent(Node *cursor, Node *child) 
{
  Node *parent;
  if (cursor->IS_LEAF || (cursor->ptr[0])->IS_LEAF) 
  {
    return NULL;
  }
  for (int i = 0; i < cursor->size + 1; i++) 
  {
    if (cursor->ptr[i] == child) 
    {
      parent = cursor;
      return parent;
    } else 
    {
      parent = findParent(cursor->ptr[i], child);
      if (parent != NULL)
        return parent;
    }
  }
  return parent;
}

//Exibe árvore
void BPTree::display(Node *cursor) 
{
  if (cursor != NULL) {
    for (int i = 0; i < cursor->size; i++) 
    {
      cout << cursor->key[i] << " ";
    }
    cout << "\n";
    if (cursor->IS_LEAF != true) 
    {
      for (int i = 0; i < cursor->size + 1; i++) 
      {
        display(cursor->ptr[i]);
      }
    }
  }
}

//retorna raíz
Node *BPTree::getRoot() 
{
  return root;
}

int main() 
{
  cout << "\n\t\t\t --- Árvore B+ --- \n";
  //cria um nó
  BPTree node;
  /*
    menu
  */
  int opc = 0;
  bool quit = false;
  while(quit == false)
  {
    cout << "\n\t\t ESCOLHA UMA OPÇÃO \n";
    cout << "\t 1 - Inserir \n";
    cout << "\t 2 - Remover \n";
    cout << "\t 3 - Exibir \n";
    cout << "\t 4 - Procurar elemento \n";
    cout << "\n\t 0 - Sair \n";
    cout << "\nDigite: ";
    cin >> opc;
    
    if(opc == 0)
    {
      quit = true;
    }
    else if(opc == 1)
    {
      int val = 0;
      cout << "\n ---- Inserir valor ---- \n";
      cout << "Digite: ";
      cin >> val;
      node.insert(val);

    }
    else if(opc == 2)
    {
      cout << "\n Ops! Não implementado! \n";
    }
    else if(opc == 3)
    {
      node.display(node.getRoot());
    }
    else if(opc == 4)
    {
      int elemento = 0;
      cout << "\n --- Procurando elemento --- \n";
      cout << "Digite: ";
      cin >> elemento;
      node.search(elemento);
    }
  cout << "\n -- Pressione 0 para sair ou 1 para continuar: ";
  int x = 0;
  cin >> x;
  if(x == 0) 
  {
    quit = true;
    cout << "\n Até a próxima! ";
  }
  
  system("clear||cls");
  }
}
