#include "menu.hpp"

void MenuAux(bool check, int escolhaEstrutura, int* escolhaArq, vector<float> v10k){
	if(check){
		menu(escolhaEstrutura,escolhaArq,v10k);
	}
	else{
		cout << "Por favor, antes de tentar criar alguma estrutura, crie/atualize o seu arquivo de pesquisa 10000.txt\n\n";
	}
}

void menu(int escolhaEstrutura, int* escolhaArq, vector<float> v10k){
	int auxMenu = 0;

	while (auxMenu != 3){
		cout << "Escolha entre as opções abaixo: \n\n";
		cout << "1 - Escolher qual arquivo será lido\n";
		cout << "2 - Rodar ";
		printArvore(escolhaEstrutura);
		printEscolha((*escolhaArq));
		cout << "3 - Sair\n";
		cin >> auxMenu;
		cout << "\n";

		switch(auxMenu) {
			case 1:
				(*escolhaArq) = escolhaArquivo();
				break;
			case 2:
				{ // Pela internet, quando quero uma variável em um case do swith, colocar os colchetes impossibilita possíveis erros onde a variável vai para outros cases do switch

				Tree *raiz = CreateTree();
				vector<float> v;
				unordered_map<float, float> um;
				map<float,float> m;

				int numNF; // Numero de pesquisas Not Found

				vector<float> vp; // Posições dos floats ou os próprios floats em que foram encontrados nas estruturas
				vector<Tree*> vpt; // Nós das árvores que foram encontradas nas estruturas

				// Criando a estrutura
				cout << "Criando Estrutura...\n";
				chrono::steady_clock::time_point begin = chrono::steady_clock::now();
				CriarEstrutura((*escolhaArq),escolhaEstrutura,&raiz,&v,&m,&um);
				chrono::steady_clock::time_point end = chrono::steady_clock::now();
				cout << "Tempo criando = " << chrono::duration_cast<chrono::microseconds>(end - begin).count() << "[µs]\n\n";

				//mostrandoEstrutura(escolhaEstrutura, raiz, v, m, um);

				// Pesquisando na estrutura
				cout << "Pesquisando na Estrutura...\n";
				begin = chrono::steady_clock::now();
				numNF = PesquisarNaEstrutura(escolhaEstrutura,&raiz,v,m,um,&vpt,&vp,v10k);
				end = chrono::steady_clock::now();
				cout << "Tempo pesquisando = " << chrono::duration_cast<chrono::microseconds>(end - begin).count() << "[µs]\n";
				cout << "Número de elementos não encontrados: " << numNF << "\n\n";

				// Excluindo da estrutura
				cout << "Excluindo na Estrutura...\n";
				begin = chrono::steady_clock::now();
				ExcluirDaEstrutura(escolhaEstrutura,&raiz,&v,&m,&um,vpt, vp);
				end = chrono::steady_clock::now();
				cout << "Tempo excluindo = " << chrono::duration_cast<chrono::microseconds>(end - begin).count() << "[µs]\n";
				cout << "Elementos excluidos com sucesso\n\n";
				
				//mostrandoEstrutura(escolhaEstrutura, raiz, v, m, um);

				//cout << "\n\n";
				}
				break;
			case 3:
				cout << "\n\n";
				break;
			default:
				cout << "Opção Inválida\n\n";
				break;

		}
	}
}

int escolhaArquivo(){
	int escolha;
	while(true){
		cout << "Escolha qual arquivo será lido: \n";
		cout << "1 para o vetor de 500\n";
		cout << "2 para o vetor de 5.000\n";
		cout << "3 para o vetor de 50.000\n";
		cout << "4 para o vetor de 500.000\n";
		cin >> escolha;
		cout << "\n";
		if (escolha > 0 && escolha < 5){
			return escolha;
		}
		cout << "Escolha Inválida\n\n";
	}
}

void printEscolha(int escolha){
	switch(escolha){
		case 1:
			cout << "de tamanho 500\n";
			break;
		case 2:
			cout << "de tamanho 5.000\n";
			break;
		case 3:
			cout << "de tamanho 50.000\n";
			break;
		case 4:
			cout << "de tamanho 500.000\n";
			break;
		default:
			break;
	}
}

void printArvore(int option){
	switch(option){
		case 2:
			cout << "a árvore binária";
			break;
		case 3:
			cout << "a árvore AVL";
			break;
		case 4:
			cout << "a árvore RedBlack";
			break;
		case 5:
			cout << "o vector";
			break;
		case 6:
			cout << "o map";
			break;
		case 7:
			cout << "o unordered map";
			break;
		default:
			break;
	}
	cout << " com o arquivo ";
}

int PesquisarNaEstrutura(int escolhaEstrutura, Tree** t, vector<float> v, map<float, float> m, unordered_map<float, float> um, vector<Tree*>* vpt, vector<float>* vp, vector<float> v10k){
	ifstream myfile;
	int NF = 0; // Not Found
	
	switch(escolhaEstrutura){
		case 2:
			{
				// Binária
				for (std::vector<float>::iterator it= v10k.begin(); it!= v10k.end(); ++it){
					Record r;
					r.key = *it;
					Tree* aux = CreateTree();
					pesquisa(&(*t),&aux,r);
					if (aux == nullptr){
						NF++;
					}
					else{						
						//cout << aux->reg.key << "\n";
						(*vp).push_back(*it);
					}
				}	
			}
			break;
		case 3:
			{
				// AVL
				for (std::vector<float>::iterator it= v10k.begin(); it!= v10k.end(); ++it){
					Record r;
					r.key = *it;
					Tree* aux = CreateTree();
					pesquisa(&(*t),&aux,r);
					if (aux == nullptr){
						NF++;
					}
					else{
						(*vp).push_back(*it);
					}
				}			
			}
			break;
		case 4:
			{
				// RB
				for (std::vector<float>::iterator it= v10k.begin(); it!= v10k.end(); ++it){
					Record r;
					r.key = *it;
					Tree* aux = CreateTree();
					pesquisa(&(*t),&aux,r);
					if (aux == nullptr){
						NF++;
					}
					else{
						(*vpt).push_back(aux);
					}
				}	
			}
			break;
		case 5:
			{
				// Vector
				for (std::vector<float>::iterator it= v10k.begin(); it!= v10k.end(); ++it){
					int aux = pesquisarVector(v,*it);
					if (aux != -1){
						(*vp).push_back(aux);
					}
					else{
						NF++;
					}
				}
			}
			break;
		case 6:
			{
				// Map
				for (std::vector<float>::iterator it= v10k.begin(); it!= v10k.end(); ++it){
					map<float, float>::iterator itM = m.find(*it);
					if (itM != m.end()){
						(*vp).push_back(*it);
					}
					else{
						NF++;
					}
				}
			}
			break;
		case 7:
			{
				// Unordered Map
				for (std::vector<float>::iterator it= v10k.begin(); it!= v10k.end(); ++it){
					unordered_map<float, float>::iterator itUM = um.find(*it);
					if (itUM != um.end()){
						(*vp).push_back(*it);
					}
					else{
						NF++;
					}
				}
			}
			break;
		default:
			break;
	}
	return NF;
}

void ExcluirDaEstrutura(int escolhaEstrutura, Tree** t, vector<float>* v, map<float, float>* m, unordered_map<float, float>* um, vector<Tree*> vpt, vector<float> vp){
	switch(escolhaEstrutura){
		case 2:
			for (std::vector<float>::iterator it= vp.begin(); it!= vp.end(); ++it){
				Record r;
				r.key = *it;
				removeTree(t,r);
			}
			break;
		case 3:
			for (std::vector<float>::iterator it= vp.begin(); it!= vp.end(); ++it){
				Record r;
				r.key = *it;
				removeTreeAVL(t, t, r);
			}
			break;
		case 4:
			for (std::vector<Tree*>::iterator it= vpt.begin(); it!= vpt.end(); ++it){
				removeTreeRB(t, *it);
			}
			break;
		case 5:
			{
				int aux = 0;
				for (std::vector<float>::iterator it= vp.begin(); it!= vp.end(); ++it){
					(*v).erase( (*v).begin() + *it + aux , (*v).begin() + *it + aux + 1 );
					aux--;
				}
			}
			break;
		case 6:
			// Map
			for (std::vector<float>::iterator it= vp.begin(); it!= vp.end(); ++it){
				(*m).erase(*it);
			}
			break;
		case 7:
			// Unordered Map
			for (std::vector<float>::iterator it= vp.begin(); it!= vp.end(); ++it){
				(*um).erase(*it);
			}
			break;
		default:
			break;
	}
}

void mostrandoEstrutura(int escolhaEstrutura, Tree* raiz, vector<float> v, map<float,float> m, unordered_map<float, float> um){
	if (escolhaEstrutura < 5){
		widthPath(raiz);
	}
	else if(escolhaEstrutura == 5){
		for (std::vector<float>::iterator it= v.begin(); it!= v.end(); ++it){
			std::cout << ' ' << *it;
			std::cout << '\n';
		}
	}
	else if(escolhaEstrutura == 6){
  		for (map<float,float>::iterator it = m.begin(); it!=m.end(); ++it)
    		cout << it->first << " => " << it->second << '\n';
		}
	else{
  		for (unordered_map<float,float>::iterator it = um.begin(); it!=um.end(); ++it)
    		cout << it->first << " => " << it->second << '\n';
	}
}