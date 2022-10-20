#ifndef TREE_HPP
#define TREE_HPP

#include <iostream> //Header that defines the standard input/output stream objects
#include <stdbool.h> // Usada na árvore por causa da redblack
#include <vector>
using namespace std; // Ainda não utilizei outra para entender melhor como isso funciona

typedef struct Record Record;
typedef struct Tree Tree;

struct Record{
	float key;
};

struct Tree{
	Record reg;
	Tree *esq, *dir;
	Tree *pai; //específico para rubro negra
	bool cor;  //específico para rubro negra (FALSE = VERMELHOR, TRUE = PRETO)
	int weight; // específico para AVL
};

// auxiliar de árvores em geral
Tree* CreateTree();
bool TVazia(Tree **t);
void pesquisa(Tree **t, Tree **aux, Record r);
int isInTree(Tree *t, Record r);
void widthPath(Tree *t);
void central(Tree *t, vector<float>* aux);
void antecessor(Tree **t, Tree *aux);

// Insere nas árvores
void insertTree(Tree **t, Record r);

// Remover das árvores
void removeTree(Tree **t, Record r); // Remove da árvore Binária


#endif
