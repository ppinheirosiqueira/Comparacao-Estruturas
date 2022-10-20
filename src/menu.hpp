#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include "tree.hpp"
#include "vector.hpp"
#include <chrono> // Importando para contar o tempo
#include <unordered_map> // Importando para o unordered map
#include <map> // Importando para o map
#include "arquivo.hpp"
#include "avl.hpp"
#include "rb.hpp"

void MenuAux(bool check, int escolhaEstrutura, int* escolhaArq, vector<float> v10k);
void menu(int escolhaEstrutura, int* escolhaArq, vector<float> v10k);
int escolhaArquivo();
void printEscolha(int escolha);
void printEstrutura(int option);
void printMenuEstrutura(int option);
int PesquisarNaEstrutura(int escolhaEstrutura, Tree** t, Tree** tRB, vector<float> v, map<float, float> m, unordered_map<float, float> um, vector<float>* vp, vector<float> v10k);
void ExcluirDaEstrutura(int escolhaEstrutura, Tree** t, Tree** tRB, vector<float>* v, map<float, float>* m, unordered_map<float, float>* um, vector<float> vp);
void mostrandoEstrutura(int escolhaEstrutura, Tree* raiz, Tree** tRB, vector<float> v, map<float,float> m, unordered_map<float, float> um);

#endif
