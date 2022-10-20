#include "rb.hpp"

void insertFixUp(Tree **raiz, Tree *child){
  Tree *tio;

  while((child != *raiz) && (child->pai->cor == false)){
      
      if(child->pai == child->pai->pai->esq){
        
        tio = child->pai->pai->dir;

        //caso 1:
        if((tio != nullptr) && (tio->cor == false)){
          child->pai->cor = true;
          tio->cor = true;
          child->pai->pai->cor = false;
          child = child->pai->pai;
        
        }else{
          
          //caso 2
          if(child == child->pai->dir){
            child = child->pai;
            rotacaoSimplesEsquerda(raiz, child);
          }
          
          //caso 3
          child->pai->cor = true;
          child->pai->pai->cor = false;
          rotacaoSimplesDireita(raiz, child->pai->pai);
        }

      }else{
        
        tio = child->pai->pai->esq;
        
        //caso 1
        if((tio != nullptr) && (tio->cor == false)){
          child->pai->cor = true;
          tio->cor = true;
          child->pai->pai->cor = false;
          child = child->pai->pai;
        
        }else{
          
          //caso 2
          if(child == child->pai->esq){
            child = child->pai;
            rotacaoSimplesDireita(raiz, child);
          }

          //caso 3
          child->pai->cor = true;
          child->pai->pai->cor = false;
          rotacaoSimplesEsquerda(raiz, child->pai->pai);      
        }

      }

  }

  (*raiz)->cor = true;
}

void rotacaoSimplesEsquerda(Tree **raiz, Tree *child){
  Tree *x, *y;

  x = child;
  y = child->dir;
  x->dir = y->esq;

  if(y->esq != nullptr)
    y->esq->pai = x;

  y->pai = x->pai;
  
  if(x->pai == nullptr)
    *raiz = y;

  else{

    if(x == x->pai->esq)
      x->pai->esq = y;

    else
      x->pai->dir = y;
  
  }

  y->esq = x;
  x->pai = y;
}

void rotacaoSimplesDireita(Tree **raiz, Tree *child){
  Tree *x, *y;

  x = child;
  y = child->esq;
  x->esq = y->dir;

  if(y->dir != nullptr)
    y->dir->pai = x;

  y->pai = x->pai;
  
  if(x->pai == nullptr){
    *raiz = y;
  }

  else{

    if(x == x->pai->dir)
      x->pai->dir = y;

    else
      x->pai->esq = y;
  
  }

  y->dir = x;
  x->pai = y;
  
}

void removeTreeRB(Tree **t, Tree* z){
  Tree *y, *x;
  //y = z;
  bool yOriginal = (*z).cor; // Não vi motivo pra setar o y e usar sendo q posso usar o Z direto e o Y quando vai ser usado é setado de novo 
  if (z->esq == nullptr){
    x = z->dir;
    RB_Transplant(t, z, z->dir);
  }
  else if(z->dir == nullptr){
    x = z->esq;
    RB_Transplant(t, z, z->esq);
  }
  else{
    y = Tree_Minimum(z->dir);
    yOriginal = (*y).cor;
    x = y->dir;
    if (y->pai == z){
      if(x!=nullptr){x->pai = y;}
    }
    else{
      RB_Transplant(t,y,y->dir);
      y->dir = z->dir;
      y->dir->pai = y;
    }
    RB_Transplant(t,z,y);
    y->esq = z->esq;
    y->esq->pai = y;
    (*y).cor = (*z).cor;
  }
  if (yOriginal == true && x!=nullptr){
    RB_Delete_Fixup(t,x); // faz sentido eu não chamar se x for nullptr?
  }
  delete(z);
}

void RB_Transplant(Tree **t, Tree* u, Tree* v){
  if (u->pai == nullptr){
    (*t) = v;
  }
  else if(u == u->pai->esq){
    u->pai->esq = v;
  }
  else{
    u->pai->dir = v;
  }
  if (v!=nullptr){v->pai = u->pai;} // para prevenir caso v seja o último elemento
}

Tree* Tree_Minimum(Tree* t) {
  Tree* aux = t;
	while (aux->esq != nullptr) {
		aux = aux->esq;
	}
	return aux;
}

void RB_Delete_Fixup(Tree** t, Tree *x){
  Tree* w;
  while(x != (*t) && x->cor == true){
    if (x == x->pai->esq){
      cout << "If - 1\n";
      w = x->pai->dir;
      if (w!=nullptr && w->cor == false){
        w->cor = true;
        x->pai->cor = false;
        rotacaoSimplesEsquerda(t, x->pai);
        w = x->pai->dir;
      }
      cout << "If - 2\n";
      if ((w->esq==nullptr ||w->esq->cor == true) && (w->dir == nullptr || w->dir->cor == true)){
        w->cor = false;
        x = x->pai;
      }
      else if(w->dir == nullptr || w->dir->cor == true){
        w->esq->cor = true;
        w->cor = false;
        rotacaoSimplesDireita(t, w);
        w = x->pai->dir;
      }
    cout << "If - 3\n";
    w->cor = x->pai->cor;
    x->pai->cor = true;
    if(w->dir!=nullptr){w->dir->cor = true;}
    rotacaoSimplesEsquerda(t, x->pai);
    x = (*t);
    }  
    else{
      cout << "Else - 1\n";
      w = x->pai->esq;
      if (w!=nullptr && w->cor == false){
        w->cor = true;
        x->pai->cor = false;
        rotacaoSimplesDireita(t, x->pai);
        w = x->pai->esq;
      }
      cout << "Else - 2\n";
      if ((w->dir == nullptr || w->dir->cor == true) && (w->esq == nullptr || w->esq->cor == true)){
        w->cor = false;
        x = x->pai;
      }
      else if(w->esq == nullptr || w->esq->cor == true){
        w->dir->cor = true;
        w->cor = false;
        rotacaoSimplesEsquerda(t, w);
        w = x->pai->esq;
      }
    cout << "Else - 3\n";
    w->cor = x->pai->cor;
    x->pai->cor = true;
    if(w->esq!=nullptr){w->esq->cor = true;}
    rotacaoSimplesDireita(t, x->pai);
    x = (*t);
    }
  }
  x->cor = true;
}

void insertTreeRB(Tree **t, Tree **pai, Tree **raiz, Record r){
  
  if(*t == nullptr){
    *t = new(Tree);
    (*t)->esq = nullptr; 
    (*t)->dir = nullptr; 
    (*t)->pai = pai!=t?*pai:nullptr;
    (*t)->cor = false; //false: vermelho  true:preto
    (*t)->reg = r; 
    insertFixUp(raiz, *t);
    
  } else { 

    if(r.key < (*t)->reg.key){
      insertTreeRB(&(*t)->esq, t, raiz, r);
      return;
    }
    
    if(r.key > (*t)->reg.key){
      insertTreeRB(&(*t)->dir, t, raiz, r);
      return;
    }

  }

}