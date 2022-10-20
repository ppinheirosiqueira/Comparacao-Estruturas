#include "rb.hpp"

Tree *temp, *nill;

/**
 * @brief Prepara a estrutura RB para receber valores
 * 
 * @param root ponteiro da estrutura RB
 */
void inicializaTree(Tree **root){
    nill        = new Tree;
    nill->cor = true;
    nill->esq    = NULL;
    nill->dir    = NULL;
    nill->pai     = NULL;
    nill->reg.key   = 0;
    (*root)     = nill;
}

/**
 * @brief Realiza a insedirao na estrutura RB
 * 
 * @param root ponteiro da estrutura RB
 * @param r valor a ser inserido
 */
void insertItemRB(Tree **root, Record r) {
    int chk = 0;

    if ((temp = new(Tree)) != NULL){
        temp->pai     = nill;
        temp->esq    = nill;
        temp->dir    = nill;
        temp->reg   = r;
        temp->cor = true;
        chk         = check(*root,r.key,0);

        if(chk == 0){
            rb_insert(root, *root, nill, temp);
        }
        else{
            //printf("Node already registered: %lf\n", r.key);
            delete temp;
        }
    }
}

/**
 * @brief Realiza a rotacao a esquerda
 * 
 * @param root ponteiro raiz da estrutura RB
 * @param item ponteiro da estrutura RB
 */
void rotacaoEsquerda(Tree **root, Tree *item){
    Tree *aux;
    aux = item->dir;
    item->dir = aux->esq;
    if (aux->esq != nill)
        aux->esq->pai = item;
    aux->pai = item->pai;
    if (item->pai == nill)
        (*root) = aux;
    else if (item == item->pai->esq)
        item->pai->esq = aux;
    else if (item == item->pai->dir)
        item->pai->dir = aux;
    aux->esq = item;
    item->pai  = aux;
}

/**
 * @brief Realiza a rotacao a direita
 * 
 * @param root ponteiro raiz da estrutura RB
 * @param item ponteiro da estrutura RB
 */
void rotacaoDireita(Tree **root, Tree *item){
    Tree *aux;
    aux = item->esq;
    item->esq = aux->dir;
    if (aux->dir != nill)
        aux->dir->pai = item;
    aux->pai = item->pai;
    if (item->pai == nill)
        (*root) = aux;
    else if (item == item->pai->dir)
        item->pai->dir = aux;
    else if (item == item->pai->esq)
        item->pai->esq = aux;
    aux->dir = item;
    item->pai  = aux;
}

/**
 * @brief Balanceia a estrutura RB
 * 
 * @param root ponteiro raiz da estrutrua RB
 * @param aux ponteiro auxiliar da estrutura RB
 */
void fix_insert(Tree **root, Tree *aux){
    Tree *y;
    while (aux->pai->cor == false){	
        if (aux->pai == aux->pai->pai->esq){
            y = aux->pai->pai->dir;
            //case 1
            if (y->cor == false){				
                aux->pai->cor    = true;		
                y->cor         = true;
                aux->pai->pai->cor = false;
                aux              = aux->pai->pai;
            }
            else{
                //case 2
                if (aux == aux->pai->dir){		
                    aux = aux->pai;
                    rotacaoEsquerda(root, aux);		
                }
                //case 3
                aux->pai->cor    = true;		
                aux->pai->pai->cor = false;
                rotacaoDireita(root, aux->pai->pai);
            }
        }
        else if (aux->pai == aux->pai->pai->dir){
            //case 1
            y = aux->pai->pai->esq;
            if (y->cor == false) {
                aux->pai->cor    = true;
                y->cor         = true;
                aux->pai->pai->cor = false;	
                aux              = aux->pai->pai;
            }
            //case 2
            else{
                if (aux == aux->pai->esq){
                    aux = aux->pai;
                    rotacaoDireita(root, aux);
                }
                //case 3
                aux->pai->cor    = true;		
                aux->pai->pai->cor = false;
                rotacaoEsquerda(root, aux->pai->pai);
            }
        }
    }
    (*root)->cor = true;
}

/**
 * @brief Insere na estrutura RB
 * 
 * @param root ponteiro raiz da estrutura RB
 * @param x ponteiro auxiliar da estrutura RB
 * @param y ponteiro auxiliar da estrutura RB
 * @param temp ponteiro auxiliar da estrutura RB
 */
void rb_insert(Tree **root, Tree *x, Tree *y, Tree *temp){
    while (x != nill){				
        y = x;					
        if (temp->reg.key < x->reg.key)
            x = x->esq;
        else 
            x = x->dir;
    }

    temp->pai=y;
    if (y == nill)
        (*root) = temp;
    else if (temp->reg.key < y->reg.key)
        y->esq = temp;
    else
        y->dir = temp;
    temp->esq    = nill;
    temp->dir    = nill;
    temp->cor = false;
    fix_insert(root, temp);
}

/**
 * @brief Busca o sucessor
 * 
 * @param aux_succ ponteiro auxiliar da estrutura RB
 */
Tree *tree_successor(Tree *aux_succ){
    while (aux_succ->esq != nill)
        aux_succ = aux_succ->esq;
    return aux_succ;
}

/**
 * @brief Exclui um elemento da arvore 
 * 
 * @param root ponteiro da estrutura RB para exclusao
 * @param aux ponteiro da estrutura RB utilizado como pesquisa do elemento
 * @param z valor utilizado para pesquisa
 */
void search_delete(Tree **root, Tree *aux, Record z){
    while (aux != nill && z.key != aux->reg.key){
        if (z.key < aux->reg.key)
            aux = aux->esq;
        else 
            aux = aux->dir;
    }
    if (aux->reg.key == z.key) {
        // printf("Node (%lf) found\n", z.key);
        RB_delete(root, aux, aux, aux);
    }
    else 
        printf("Node (%lf) does not exist\n", z.key);
}

/**
 * @brief verifica se um valor ja existe na estrutura RB
 * 
 * @param aux ponteiro da estrutura RB utiliza para pesquisa do elemento
 * @param z valor pesquisa na estrutura
 * @param chk valor utilizado para controle, 1 -> encontrou
 */
int check(Tree *aux, double z, int chk){
    while (aux != nill && z != aux->reg.key){
        if (z < aux->reg.key)
            aux = aux->esq;
        else 
            aux = aux->dir;
    }
    if (aux->reg.key == z)
        chk = 1;
    return chk;
}

/**
 * @brief Balanceia apoz excluir um elemento
 * 
 * @param root  ponteiro raiz da estrutura RB
 * @param x ponteiro auxiliar da estrutura RB
 * @param w ponteiro auxiliar da estrutura RB
 */
void RB_delete_fix(Tree **root, Tree *x, Tree *w){
    while (x != (*root) && x->cor == true) {
        if (x == x->pai->esq){
            w = x->pai->dir;
            if (w->cor == false){	
                w->cor    = true;
                x->pai->cor = false;
                rotacaoEsquerda(root, x->pai);
                w = x->pai->dir;
            }
            else if (w->esq->cor == true && w->dir->cor == true){	
                w->cor = false;
                x = x->pai;
            }
            else if (w->dir->cor == true){
                w->esq->cor = true;
                w->cor     = false;
                rotacaoDireita(root, w);
                w = x->pai->dir;
            }
            else{
                w->cor     = x->pai->cor;				
                x->pai->cor  = true;	
                w->dir->cor = true;	
                rotacaoEsquerda(root, x->pai);
                x = (*root);
            }
        }
        else{
            w = x->pai->esq;
            if (w->cor == false){
                w->cor    = true;
                x->pai->cor = false;
                rotacaoDireita(root, x->pai);
                w = x->pai->esq;
            }
            else if (w->dir->cor == true && w->esq->cor == true){
                w->cor = false;
                x=x->pai;
            }
            else if (w->esq->cor == true) {
                w->dir->cor = true;
                w->cor     = false;
                rotacaoEsquerda(root, w);
                w = x->pai->esq;
            }
            else{
                w->cor     = x->pai->cor;
                x->pai->cor  = true;
                w->esq->cor = true;
                rotacaoDireita(root, x->pai);
                x = (*root);
            }
        }
    }
    x->cor = true;
}

/**
 * @brief Remove um valor da estrutura RB
 * 
 * @param z ponteiro auxiliar da estrutura RB
 * @param y ponteiro auxiliar da estrutura RB
 * @param x ponteiro auxiliar da estrutura RB
 */
void RB_delete(Tree **root, Tree* z, Tree* y, Tree *x){	
    bool yOriginal;	//keep track of x which moves into y's original position
    yOriginal = y->cor;	//Keep track of original cor

    //case 1
    if (z->esq == nill){
        x = z->dir;
        RB_transplant(root, z, z->dir);
    }
    //case 2
    else if (z->dir == nill){
        x = z->esq;
        RB_transplant(root, z, z->esq);
    }
    //two cases: z has both Children
    else{
        y = tree_successor(z->dir);
        yOriginal = y->cor;
        x=y->dir;

        if (y->pai == z){
            x->pai = y;
        }
        //swap subtree of y->dir pointing to y->pai (before we move y to z)
        else {
            RB_transplant(root, y, y->dir);		
            y->dir    = z->dir;		//partial change of y
            y->dir->pai = y;
        }
        //replacement of z with y (also builds subtrees)
        RB_transplant(root, z, y);
        y->esq    = z->esq;
        y->esq->pai = y;
        y->cor = z->cor;
    }
    //imbalanced RBT only possible when we delete a true node
    if (yOriginal == true)
        RB_delete_fix(root, x,x);
    delete z;
}

/**
 * @brief replace the subtree rooted at node aux with the subtree rooted at aux-esq or aux->dir
 * 
 * @param root ponteiro raiz da estrutura RB
 * @param aux ponteiro auxiliar da estrutura RB
 * @param auxchild ponteiro da estrutura RB
 */
void RB_transplant(Tree **root, Tree *aux, Tree *auxchild){
    if (aux->pai == nill)
        (*root) = auxchild;
    else if (aux == aux->pai->esq)
        aux->pai->esq = auxchild;
    else 
    	aux->pai->dir = auxchild;
    auxchild->pai = aux->pai;
}