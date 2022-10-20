#ifndef ARQUIVO_HPP
#define ARQUIVO_HPP

#include <fstream> //Input/output stream class to operate on files.
#include <string> //Importando strings para usar na leitura de arquivos
#include <unordered_map> // Importando para o unordered map
#include <map> // Importando para o map
#include "tree.hpp" // Importando para as árvores
#include "vector.hpp" // Importando para o Vector
#include <sys/stat.h> // Teste arquivo existe
#include "avl.hpp" // Importando para a árvore AVL
#include "rb.hpp" //Importando para a árvore RB

vector<float> CriarArquivos();
void CriarEstrutura(int escolhaArquivo, int escolhaEstrutura, Tree** t, vector<float>* v, map<float, float>* m, unordered_map<float, float>* um);
bool exists10k (string name);
vector<float> lerPesquisa();

#endif
