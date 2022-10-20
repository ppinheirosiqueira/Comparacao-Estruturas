#ifndef RB_HPP
#define RB_HPP

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "tree.hpp"

void inicializaTree(Tree **root);

Tree *tree_successor(Tree *aux_succ);

void rotacaoEsquerda(Tree **root, Tree *item);
void rotacaoDireita(Tree **root, Tree *item);
void fix_insert(Tree **root, Tree *aux);
void insertItemRB(Tree **root, Record r);

void rb_insert(Tree **root, Tree *x,Tree *y,Tree *temp);

void RB_delete(Tree **root, Tree* z,Tree* y,Tree *x);
void RB_delete_fix(Tree **root, Tree *x,Tree *w);
void RB_transplant(Tree **root, Tree *aux,Tree *auxchild);

void search_delete(Tree **root, Tree *aux, Record z);

int check(Tree *aux,double z,int chk);
#endif