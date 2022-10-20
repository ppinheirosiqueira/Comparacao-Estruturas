#ifndef AVL_HPP
#define AVL_HPP

#include<stdio.h>
#include<stdlib.h>
#include "tree.hpp"

void insertTreeAVL(Tree **t, Record r);

//muda o remove devido a necessidade de ponteiro para sub-árvore desbalanceada
void removeTreeAVL(Tree **t, Tree **f, Record r);
void rebalanceTreeAVL(Tree **t);

int getWeight(Tree **t);
int getMaxWeight(int left, int right);

void rotacaoSimplesDireitaAVL(Tree **t);
void rotacaoSimplesEsquerdaAVL(Tree **t);
void rotacaoDuplaDireitaAVL(Tree **t);
void rotacaoDuplaEsquerdaAVL(Tree **t);


#endif