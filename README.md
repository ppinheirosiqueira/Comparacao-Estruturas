# Comparação de Estruturas

[![Linguagem C++](https://img.shields.io/badge/Linguagem-C%2B%2B-green.svg)](https://github.com/PedroLouback/Exercicio3-ListaAEDs)
[![requirement](https://img.shields.io/badge/IDE-Visual%20Studio%20Code-informational)](https://code.visualstudio.com/docs/?dv=linux64_deb)
![ISO](https://img.shields.io/badge/ISO-Linux-blueviolet)

---
 
## Problema

<p align=justify>Até o momento trabalhamos com três modelos de árvore, binária, avl e redblack. Chegou o momento de compararmos tais estruturas, observando seu comportamento sob diferentes volumes de dados. Para tanto, elabore arquivos que contenham 500 , 5.000 , 50.000 , 500.000 entradas numéricas do tipo ponto flutuante. Para tanto, tente evitar repetições de valores em grande escala para que possamos ter uma estrutura profunda. Considere produzir os menores a partir dos maiores volumes de forma randômica. Feito a isso, vamos testar os seguintes processos:

1. Qual o tempo gasto com pesquisa para um arquivo de entrada com 10.000 consultas. Considere como consulta a busca de um determinado número na estrutura escolhida. Para cada pesquisa, é preciso remover o elemento da árvore, retornando esse número para o usuário. Então, considere o processo de remoção como parte final do processo. 

2. Qual o tempo necessário para montar a estrutura em memória. 

3. Qual o ganho dessas estruturas ao compará-las a vetores ordenados e aplicados à pesquisa binária. Qual o tempo gasto com a ordenação do vetor? Foi possível produzi-lo em memória? 

4. Adotando como estrutura o map e unorder_map do C++, há ganhos maiores nesse processo de pesquisa?

Elabore um relatório detalhando a implementação dessas estruturas, funcionamento da aplicação, exemplo de resultado, modo de compilação e conclusões. Considere essa última seção como uma discussão de quando adotar cada estrutura acima citada e o por quê de tal escolha. Para toda essa discussão, apresentar gráficos que demonstrem os resultados obtidos durante o processo de análise.</p>

---
## Implementação

### Arquivos
<p align=justify>Foi implementada uma opção para o usuário de criar arquivos aleatórios se assim desejar. Esses arquivos já conterão a quantidade de elementos requisitada pelo professor e sobreescreverão quaisquer arquivos que já existam e possuam o mesmo nome que o utilizado no programa. Os arquivos são feitos de forma proposital para que existam alguns elementos no arquivo de pesquisa que não existe em nenhum dos outros arquivos.</p>

### Binária

### AVL

### RedBlack

### Vector
<p align=justify>O Vector inicialmente foi feito com um quick sort para sua inserção, no entanto, por mais que o quick sort seja rápido, para as entradas maiores o seu tempo era simplesmente inviável. Portanto, a inserção no vector foi feita pela criação de uma árvore binária padrão e em seguida foi utilizado o método central para a inserção dos dados dessa árvore no vector. Assim, não só agilizando o processo, como também filtrando qualquer dado repetido que poderia existir.</p>

<p align=justify>Para sua busca foi utilizada a Binary Search, padrão por ser a melhor busca possível para vetores ordenados, estando em O(log<sub>2</sub><sup>n</sup>). As posições dos números encontrados foram salvos em um vetor que será utilizado posteriormente para a exclusão dos elementos deste vector.</p>

### Map

### Unordered Map

---
## Resultados Testes
Foram executados baterias de testes em cada estrutura e para cada arquivo de entrada em dois computadores diferentes. O primeiro tem um processador i7-9750H, Windows 11 e está rodando o programa pelo Ubuntu via WSL. O segundo é um i7-3630QM, Windows 10 e está rodando o programa pelo Ubuntu via WSL. Essa bateria de testes consiste em 10 testes realizando o ciclo proposto no enunciado, onde são coletados os tempos de inserção nas estruturas, o tempo de pesquisa e o tempo de remoção.

Abaixo se encontram as tabelas com os tempos médios obtidos (e seus respectivos desvios padrões) e os gráficos destas tabelas, para mera visualização mais fácil se desejado.

### Inserção

<table class="tg">
<thead>
  <tr>
    <th class="tg-amwm">Arquivo</th>
    <th class="tg-amwm" colspan="6">Tempo i7-9750H (μs)</th>
    <th class="tg-amwm" colspan="6">Tempo i7-3630QM (μs)</th>
  </tr>
</thead>
<tbody>
  <tr>
    <td class="tg-baqh"></td>
    <td class="tg-baqh">Binária</td>
    <td class="tg-baqh">AVL</td>
    <td class="tg-baqh">RB</td>
    <td class="tg-baqh">Vector</td>
    <td class="tg-baqh">Map</td>
    <td class="tg-baqh">Unordered Map</td>
    <td class="tg-baqh">Binária</td>
    <td class="tg-baqh">AVL</td>
    <td class="tg-baqh">RB</td>
    <td class="tg-baqh">Vector</td>
    <td class="tg-baqh">Map</td>
    <td class="tg-baqh">Unordered Map</td>
  </tr>
  <tr>
    <td class="tg-baqh">500</td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
  </tr>
  <tr>
    <td class="tg-baqh">5.000</td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
  </tr>
  <tr>
    <td class="tg-baqh">50.000</td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
  </tr>
  <tr>
    <td class="tg-baqh">500.000</td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
  </tr>
</tbody>
</table>

--Imagem Comparando os Tempos-- 

### Pesquisa

<table class="tg">
<thead>
  <tr>
    <th class="tg-amwm">Arquivo</th>
    <th class="tg-amwm" colspan="6">Tempo i7-9750H (μs)</th>
    <th class="tg-amwm" colspan="6">Tempo i7-3630QM (μs)</th>
  </tr>
</thead>
<tbody>
  <tr>
    <td class="tg-baqh"></td>
    <td class="tg-baqh">Binária</td>
    <td class="tg-baqh">AVL</td>
    <td class="tg-baqh">RB</td>
    <td class="tg-baqh">Vector</td>
    <td class="tg-baqh">Map</td>
    <td class="tg-baqh">Unordered Map</td>
    <td class="tg-baqh">Binária</td>
    <td class="tg-baqh">AVL</td>
    <td class="tg-baqh">RB</td>
    <td class="tg-baqh">Vector</td>
    <td class="tg-baqh">Map</td>
    <td class="tg-baqh">Unordered Map</td>
  </tr>
  <tr>
    <td class="tg-baqh">500</td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
  </tr>
  <tr>
    <td class="tg-baqh">5.000</td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
  </tr>
  <tr>
    <td class="tg-baqh">50.000</td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
  </tr>
  <tr>
    <td class="tg-baqh">500.000</td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
  </tr>
</tbody>
</table>

--Imagem Comparando os Tempos-- 

### Remoção

<table class="tg">
<thead>
  <tr>
    <th class="tg-amwm">Arquivo</th>
    <th class="tg-amwm" colspan="6">Tempo i7-9750H (μs)</th>
    <th class="tg-amwm" colspan="6">Tempo i7-3630QM (μs)</th>
  </tr>
</thead>
<tbody>
  <tr>
    <td class="tg-baqh"></td>
    <td class="tg-baqh">Binária</td>
    <td class="tg-baqh">AVL</td>
    <td class="tg-baqh">RB</td>
    <td class="tg-baqh">Vector</td>
    <td class="tg-baqh">Map</td>
    <td class="tg-baqh">Unordered Map</td>
    <td class="tg-baqh">Binária</td>
    <td class="tg-baqh">AVL</td>
    <td class="tg-baqh">RB</td>
    <td class="tg-baqh">Vector</td>
    <td class="tg-baqh">Map</td>
    <td class="tg-baqh">Unordered Map</td>
  </tr>
  <tr>
    <td class="tg-baqh">500</td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
  </tr>
  <tr>
    <td class="tg-baqh">5.000</td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
  </tr>
  <tr>
    <td class="tg-baqh">50.000</td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
  </tr>
  <tr>
    <td class="tg-baqh">500.000</td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
    <td class="tg-baqh"></td>
  </tr>
</tbody>
</table>

--Imagem Comparando os Tempos-- 

---
## Discussão

---

## Compilação e Execução

<p align="justify">O exercício disponibilizado possui um arquivo Makefile cedido pelo professor que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:</p>


| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |
