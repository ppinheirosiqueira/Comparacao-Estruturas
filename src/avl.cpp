#include "avl.hpp"

void insertTreeAVL(Tree **t, Record r){

  if(*t == NULL){
    *t = new(Tree);
    (*t)->esq   = NULL; 
    (*t)->dir  = NULL; 
    (*t)->weight = 0;
    (*t)->reg    = r; 

  } else {
    
    if(r.key < (*t)->reg.key){
      insertTreeAVL(&(*t)->esq, r);
      if ((getWeight(&(*t)->esq) - getWeight(&(*t)->dir)) == 2){
      	if(r.key < (*t)->esq->reg.key)
      		rotacaoSimplesDireitaAVL(t);
      	else
      		rotacaoDuplaDireitaAVL(t);
      }
    }
    
    if(r.key > (*t)->reg.key){
      insertTreeAVL(&(*t)->dir, r);
      if ((getWeight(&(*t)->dir) - getWeight(&(*t)->esq)) == 2){
      	if(r.key > (*t)->dir->reg.key)
      		rotacaoSimplesEsquerdaAVL(t);
      	else
      		rotacaoDuplaEsquerdaAVL(t);
      }
    }
  
  }

  (*t)->weight = getMaxWeight(getWeight(&(*t)->esq), getWeight(&(*t)->dir)) + 1;
}

void rebalanceTreeAVL(Tree **t){
	int balance;
  	int esq = 0;
  	int dir = 0;

	balance = getWeight(&(*t)->esq) - getWeight(&(*t)->dir);
	if((*t)->esq)
		esq = getWeight(&(*t)->esq->esq) - getWeight(&(*t)->esq->dir);
	if((*t)->dir)
		dir = getWeight(&(*t)->dir->esq) - getWeight(&(*t)->dir->dir);

	if(balance == 2 && esq >= 0)
		rotacaoSimplesDireitaAVL(t);
	if(balance == 2 && esq < 0)
		rotacaoDuplaDireitaAVL(t);

	if(balance == -2 && dir <= 0)
		rotacaoSimplesEsquerdaAVL(t);
	if(balance == -2 && dir > 0)
		rotacaoDuplaEsquerdaAVL(t); 	

}

void removeTreeAVL(Tree **t, Tree **f, Record r){
	Tree *aux;
  	
  	if (*t == NULL){ 
  		cout << "[ERROR]: Record not found!!!\n";
    	return;
  	}

  	if (r.key < (*t)->reg.key){ removeTreeAVL(&(*t)->esq, t, r); return;}
  	if (r.key > (*t)->reg.key){ removeTreeAVL(&(*t)->dir, t, r); return;}

  	if ((*t)->dir == NULL){ 
  		aux = *t;  
  		*t = (*t)->esq;
    	delete(aux);
    	rebalanceTreeAVL(f);
    	return;
  	}

  	if ((*t)->esq != NULL){ 
  		antecessor(&(*t)->esq, *t);
  		rebalanceTreeAVL(t);
  		rebalanceTreeAVL(f);
  		return;
  	}

  	aux = *t;  
  	*t = (*t)->dir;
  	delete(aux);
  	rebalanceTreeAVL(t);
  	rebalanceTreeAVL(f); 	
}

int getWeight(Tree **t){
	if(*t == NULL)
		return -1;
	return (*t)->weight;
}

int getMaxWeight(int esq, int dir){
	if(esq > dir)
		return esq;
	return dir;
}

void rotacaoSimplesDireitaAVL(Tree **t){
	Tree *aux;
	aux = (*t)->esq;
	(*t)->esq = aux->dir;
	aux->dir = (*t);
	(*t)->weight = getMaxWeight(getWeight(&(*t)->esq), getWeight(&(*t)->dir)) + 1;
	aux->weight  = getMaxWeight(getWeight(&aux->esq), (*t)->weight) + 1;
	(*t) = aux;
}

void rotacaoSimplesEsquerdaAVL(Tree **t){
	Tree *aux;
	aux = (*t)->dir;
	(*t)->dir = aux->esq;
	aux->esq = (*t);
	(*t)->weight = getMaxWeight(getWeight(&(*t)->esq), getWeight(&(*t)->dir)) + 1;
	aux->weight  = getMaxWeight(getWeight(&aux->esq), (*t)->weight) + 1;
	(*t) = aux;
}

void rotacaoDuplaDireitaAVL(Tree **t){
	rotacaoSimplesEsquerdaAVL(&(*t)->esq);
	rotacaoSimplesDireitaAVL(t);
}

void rotacaoDuplaEsquerdaAVL(Tree **t){
	rotacaoSimplesDireitaAVL(&(*t)->dir);
	rotacaoSimplesEsquerdaAVL(t);
}