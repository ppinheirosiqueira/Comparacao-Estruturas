#include "arquivo.hpp"

vector<float> CriarArquivos(){	
	FILE *MyFile500, *MyFile5000, *MyFile50000, *MyFile500000, 	*MyFile10000;

	MyFile500    = fopen("500.txt", "w");
	MyFile5000   = fopen("5000.txt", "w");
	MyFile50000  = fopen("50000.txt", "w");
	MyFile500000 = fopen("500000.txt", "w");
	MyFile10000  = fopen("10000.txt", "w");
	
	int i = 0;
	int auxR = 350 + ( rand() % ( 101 ) ); // Gerar número randomico entre 350 e 450

	for(;i<auxR;i++){
		float randFloat = rand();
		// Write to the file
		fprintf(MyFile10000, "%0.4f\n", randFloat/10000);

		fprintf(MyFile500, "%0.4f\n", randFloat/10000);
		fprintf(MyFile5000, "%0.4f\n", randFloat/10000);
		fprintf(MyFile50000, "%0.4f\n", randFloat/10000);
		fprintf(MyFile500000, "%0.4f\n", randFloat/10000);
	}

	for(;i<500;i++){
		float randFloat = rand();
		// Write to the file

		fprintf(MyFile500, "%0.4f\n", randFloat/10000);
		fprintf(MyFile5000, "%0.4f\n", randFloat/10000);
		fprintf(MyFile50000, "%0.4f\n", randFloat/10000);
		fprintf(MyFile500000, "%0.4f\n", randFloat/10000);
	}
	
	fclose(MyFile500);
	cout << "Arquivo de 500 Criado\n";

	int aux = 500 - auxR;
	auxR = 4800 + ( rand() % ( 101 ) ); // Gerar número randomico entre 4800 e 4900

	for(;i<auxR;i++){
		float randFloat = rand();
		// Write to the file
		fprintf(MyFile10000, "%0.4f\n", randFloat/10000);

		fprintf(MyFile5000, "%0.4f\n", randFloat/10000);
		fprintf(MyFile50000, "%0.4f\n", randFloat/10000);
		fprintf(MyFile500000, "%0.4f\n", randFloat/10000);
	}

	for(;i<5000;i++){
		float randFloat = rand();
		// Write to the file

		fprintf(MyFile5000, "%0.4f\n", randFloat/10000);
		fprintf(MyFile50000, "%0.4f\n", randFloat/10000);
		fprintf(MyFile500000, "%0.4f\n", randFloat/10000);
	}
	
	fclose(MyFile5000);
	cout << "Arquivo de 5.000 Criado\n";
	
	aux = aux + 5000 - auxR;
	auxR = 9800 + ( rand() % ( 101 ) ); // Gerar número randomico entre 9800 e 9900

	for(;i<auxR;i++){
		float randFloat = rand();
		// Write to the file
		fprintf(MyFile10000, "%0.4f\n", randFloat/10000);

		fprintf(MyFile50000, "%0.4f\n", randFloat/10000);
		fprintf(MyFile500000, "%0.4f\n", randFloat/10000);
	}

	aux = aux + 10000 - auxR;

	for(;i<50000;i++){
		float randFloat = rand();
		// Write to the file
		fprintf(MyFile50000, "%0.4f\n", randFloat/10000);
		fprintf(MyFile500000, "%0.4f\n", randFloat/10000);
	}
	
	fclose(MyFile50000);
	cout << "Arquivo de 50.000 Criado\n";
	
	for(;i<500000;i++){
		float randFloat = rand();
		// Write to the file
		fprintf(MyFile500000, "%0.4f\n", randFloat/10000);
	}

	fclose(MyFile500000);
	cout << "Arquivo de 500.000 Criado\n";

	// Completar os 10000 com números aleatórios
	for(int i = 0;i<aux;i++){
		float randFloat = rand();
		// Write to the file
		fprintf(MyFile10000, "%0.4f\n", randFloat/10000);
	}

	fclose(MyFile10000);
	cout << "Arquivo de 10.000 para pesquisa criado\n";

	return lerPesquisa();
}

void CriarEstrutura(int escolhaArquivo, int escolhaEstrutura, Tree** t, vector<float>* v, map<float, float>* m, unordered_map<float, float>* um){
	string nome;
	switch (escolhaArquivo){
	case 1:
		nome = "500.txt";
		break;
	case 2:
		nome = "5000.txt";
		break;
	case 3:
		nome = "50000.txt";
		break;
	case 4:
		nome = "500000.txt";
		break;
	default:
		break;
	}

	ifstream myfile;
	string linha;

	// Abrir Arquivo
	myfile.open(nome);

	if (myfile.is_open()){
		while (!myfile.eof()){
			getline(myfile, linha); // Pegando a linha
			if (linha.empty()){
				break;
			}
			switch(escolhaEstrutura){
				case 2:
				case 5:
					{
						// binária normal
						Record r;
						r.key = stof(linha);
						insertTree(&(*t),r);
						break;
					}
				case 3:
					{
						// Avl
						Record r;
						r.key = stof(linha);
						insertTreeAVL(&(*t),r);
						break;
					}
				case 4:
					{
						// RedBlack
						Record r;
						r.key = stof(linha);
						insertTreeRB(&(*t),&(*t),&(*t),r);
						break;
					}
				case 6:
					// Map
					(*m).insert(pair<float,float>(stof(linha),stof(linha)));
					break;
				case 7:
					// Unordered Map
					(*um).insert(pair<float,float>(stof(linha),stof(linha)));
					break;
				default:
					break;
			}
		}
	}

	myfile.close();

	if (escolhaEstrutura == 5){
		central((*t),v); 
	}
}

bool exists10k (string name) {
  struct stat buffer;   
  return (stat (name.c_str(), &buffer) == 0); 
}

vector<float> lerPesquisa(){
	ifstream myfile;
	string linha;
	vector<float> aux;
	map<float,float> auxVector;
	float auxLinha;

	// Abrir Arquivo
	myfile.open("10000.txt");

	if (myfile.is_open()){
		while (!myfile.eof()){
			getline(myfile, linha); // Pegando a linha
			if(linha.empty()){
				break;
			}
			auxLinha = stof(linha);
			map<float, float>::iterator itM = auxVector.find(auxLinha);
			if (itM == auxVector.end()){
				auxVector.insert(pair<float,float>(auxLinha,auxLinha));
				aux.push_back(auxLinha);
			}
		}
	}

	myfile.close();
	return aux;
}