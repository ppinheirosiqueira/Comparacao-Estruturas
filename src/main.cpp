#include "menu.hpp"
#include "arquivo.hpp"
#include <cstdlib> // Para número random
#include <ctime> // Para utilizar o time na raiz do rand

int main(){
	int auxMenu = 0, escolhaArq = 1;
	srand (static_cast <unsigned> (time(0))); // Caso crie novos arquivos
	bool check10k;
	vector<float> v10k;

	check10k = exists10k ("10000.txt");
	if (!check10k){
		cout << "\nVocê não possui um arquivo de pesquisa preparado, por favor, crie um na primeira opção antes de tentar rodar o resto\n";
	}
	else{
		v10k = lerPesquisa();
		cout << "\nArquivo de pesquisa lido e pronto para uso\n";
	}

	while (auxMenu != 9){
		cout << "Escolha entre as opções abaixo: \n\n";
		cout << "1 - Criar novos arquivos para serem lidos (incluindo o de pesquisa)\n";
		cout << "2 - Árvore Binária Normal\n";
		cout << "3 - AVL\n";
		cout << "4 - RedBlack\n";
		cout << "5 - Vector\n";
		cout << "6 - Map\n";
		cout << "7 - Unordered Map\n";
		cout << "8 - Atualizar arquivo de pesquisa\n";
		cout << "9 - Sair\n";
		cin >> auxMenu;
		cout << "\n";

		switch(auxMenu) {
			case 1:
				v10k = CriarArquivos();
				check10k = exists10k ("10000.txt");
				cout << "\nArquivo de pesquisa lido e pronto para uso\n\n";
				break;
			case 2:
				MenuAux(check10k,2,&escolhaArq,v10k);
				break;
			case 3:
				MenuAux(check10k,3,&escolhaArq,v10k);			
				break;
			case 4:
				MenuAux(check10k,4,&escolhaArq,v10k);			
				break;
			case 5:
				MenuAux(check10k,5,&escolhaArq,v10k);			
				break;
			case 6:
				MenuAux(check10k,6,&escolhaArq,v10k);			
				break;
			case 7:
				MenuAux(check10k,7,&escolhaArq,v10k);
				break;
			case 8:
				check10k = exists10k ("10000.txt");
				if (!check10k){
					cout << "\nAinda não existe um arquivo 10000.txt em sua pasta\n";
				}
				else{
					v10k = lerPesquisa();
					cout << "\nArquivo de pesquisa lido e pronto para uso\n";
				}
				break;
			case 9:
				cout << "Obrigado por usar o programa\n\n";
				break;
			default:
				cout << "Opção Inválida\n\n";
				break;

		}
	}
}
