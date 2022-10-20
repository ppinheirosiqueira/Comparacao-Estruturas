#ifndef RB_H 
#define RB_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "tree.hpp"

void rotacaoSimplesEsquerda(Tree **raiz, Tree *child);
void rotacaoSimplesDireita(Tree **raiz, Tree *child);

void insertFixUp(Tree **raiz, Tree *child);
void insertTreeRB(Tree **t, Tree **pai, Tree **raiz, Record r);

// Remove da Árvore RedBlack
void removeTreeRB(Tree **t, Tree* z);
void RB_Transplant(Tree **t, Tree* u, Tree* v);
Tree* Tree_Minimum(Tree* t);
void RB_Delete_Fixup(Tree** t, Tree *x);
#endif