#include "tree.hpp"
#include "fila.hpp"

Tree* CreateTree(){
	return nullptr;
}

bool TVazia(Tree **t){
  return *t == nullptr;
}

void pesquisa(Tree **t, Tree **aux, Record r){

  if(*t == nullptr){
    //cout << "[ERROR]: Node not found!" << endl;
    return;
  }

  if((*t)->reg.key > r.key){ pesquisa(&(*t)->esq, aux, r); return;}
  if((*t)->reg.key < r.key){ pesquisa(&(*t)->dir, aux, r); return;}

  *aux = *t;
}

int isInTree(Tree *t, Record r) {
  
  if(t == nullptr){ 
    return 0;
  }
  
  return t->reg.key == r.key || isInTree(t->esq, r) || isInTree(t->dir, r);
}

void antecessor(Tree **t, Tree *aux){ 

	if ((*t)->dir != nullptr){ 
		antecessor(&(*t)->dir, aux);
		return;
  }
  	
  aux->reg = (*t)->reg;
  aux = *t; 
  *t = (*t)->esq;
  delete aux;
} 

void removeTree(Tree **t, Record r){
	Tree *aux;

  if (*t == nullptr){ 
  	cout << "[ERROR]: Record not found!!!\n";
   	return;
  }

  if (r.key < (*t)->reg.key){ removeTree(&(*t)->esq, r); return; }
  if (r.key > (*t)->reg.key){ removeTree(&(*t)->dir, r); return; }
  
  if ((*t)->dir == nullptr){
 		aux = *t;  
 		*t = (*t)->esq;
   	delete aux;
   	return;
 	}

 	if ((*t)->esq != nullptr){antecessor(&(*t)->esq, *t); return; }

 	aux = *t;  
 	*t = (*t)->dir;
 	delete aux;
}

void central(Tree *t, vector<float>* aux){
  if(!(t == NULL)){
    central(t->esq, aux); 
    (*aux).push_back(t->reg.key);
    central(t->dir, aux); 
  }
}

void widthPath(Tree *t){
  Fila q;
  Item no, filho;

  FFVazia(&q);
  no.p = t;
  Enfileira(&q, no);

  while (!isVazia(&q)){
    Desenfileira(&q, &no);
    cout << no.p->reg.key << "\n";

    if(no.p->esq != nullptr){
      filho.p = no.p->esq;
      Enfileira(&q, filho);
    }

    if(no.p->dir != nullptr){
      filho.p = no.p->dir;
      Enfileira(&q, filho);
    }

  }
}

void insertTree(Tree **t, Record r){

  if(TVazia(t)){
    *t = new(Tree);
    (*t)->esq = NULL; 
    (*t)->dir = NULL; 
    (*t)->reg = r; 
  
  } else {
    
    if(r.key < (*t)->reg.key){
      insertTree(&(*t)->esq, r);
    }
    
    if(r.key > (*t)->reg.key){
      insertTree(&(*t)->dir, r);
    }
  
  }

}