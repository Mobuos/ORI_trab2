# Trabalho de ORI 2

## Introdução
O programa se trata de uma CLI que cria uma árvore B em memória principal (RAM) com grau mínimo ou ordem, definido pelo usuário e permitindo que sejam feitas inserções e buscas nesta respeitando suas propriedades de balanceamento e gerenciamento de chaves. 
O projeto foi realizado com controle de versão, e é possível visualizar o histórico de alterações no repositório do projeto, disponível no github junto de todos os arquivos compondo o programa.
## Principais conceitos
Para compilar basta alimentar ao compilador os arquivos **main.c**, **arvoreB.c**, **interface.c** e **testes.c**. Ao ser executado é pedido que o usuário insira a ordem (número inteiro maior ou igual a 2) da árvore para que o programa a gere, em seguida é mostrado um menu com as operações disponíveis deixando o usuário livre para que faça inserções e buscas à vontade. As opções são:

* Ao digitar 1 o usuário pode buscar uma chave previamente inserida na árvore.
    - Se a chave existir será exibido o endereço na memória no qual o nó que a contém está armazenado e o seu índice dentro deste nó.
    - Se a chave não existir, será retornada a mensagem `“CHAVE NÃO ENCONTRADA!”`.
* Ao digitar 2 o usuário pode inserir uma chave nova na árvore.
    - Se a chave não foi inserida anteriormente ela será encaixada entre duas outras chaves ou na extremidade de um nó e a árvore irá se rebalancear para acomodá-la caso necessário.
    - Se a chave já foi inserida anteriormente o endereço na memória usado será sobrescrito com o mesmo valor
* Ao digitar 3 o programa é finalizado e a árvore é descartada.

É possível também iniciar o programa informando um arquivo de entrada como parâmetro na execução, fazendo com que ele seja executado sem aceitar inputs do usuário e sim linhas do arquivo o que é ideal para a realização de testes automatizados.

Exemplo de uso para entrada manual:

`$ ./main`


Exemplo de uso utilizando um arquivo de testes:

`$ ./main teste1.in`

Também foram disponibilizadas as saídas dos testes em arquivos de extensão .out.
## Decisões do projeto
O grupo começou separando o projeto em três componentes fundamentais para implementação: a própria árvore B, as funcionalidades para teste e a interface com o usuário. Esses três aspectos foram separados em bibliotecas para serem implementadas em C de acordo com o diagrama:

![Diagrama da estrutura](https://i.imgur.com/nNiGyEJ.png)

## Estruturas de dados
### Árvore B
Para a estrutura da árvore B foi decidido criar uma struct de nó que contivesse um vetor de chaves de tipo int para serem armazenadas e o tamanho atual n desse vetor. 
E uma árvore B é importante saber se um nó é uma folha ou não pois isso define se uma inserção será feita no mesmo ou se será passada para outro nó, então todo nó tem um valor booleano para indicar isso. O tipo bool foi usado em C por meio da biblioteca <stdbool.h>.
Por fim, todos os nós devem ter uma referência a todos os nós à sua volta, e isso foi implementado por uma vetor de referências.
A segunda struct se trata de uma referência a raiz da árvore e seu tamanho, que são mantidas em sua própria estrutura pois são usados juntos por várias das funções.
### Interface
Foram utilizadas algumas estruturas auxiliares para manter a interface com código legível e intuitivo, padronizando as funções de busca e inserção na árvore, assim como a transferência de informações de entrada dentre as diferentes entradas (usuário e testes) para a função principal (main).
## Bateria de testes
Foram feitos três arquivos de testes (**teste1.in**, **teste2.in** e **teste3.in**), cada teste contém três partes: na primeira são inseridas várias chaves na árvore, na segunda são feitas várias buscas de chaves que se espera que estão na árvore após a inserção e por último várias buscas de chave que não foram inseridas e não devem ser encontradas.
## O código
### Função main()
A main começa verificando se o programa deve receber entradas de um arquivo ou diretamente do usuário e a árvore B é criada assim que o grau é fornecido por uma dessas duas fontes. por fim o programa entre no seu loop principal no qual podem ser realizadas buscas e inserções na árvore até a finalização da execução.
Como já dito, a troca de informação entre a interface/testes ocorre por meio das estruturas especificadas em **interface.h**.
### Funções da árvore B
Para a árvore B em si além de funções padrão para estruturas de dados como essa como a alocação de nós e criação da árvore também são usadas as funções de divisão dos filhos e deslocamento de um nó que são invocadas na inserção de uma chave e são essenciais para que o balanceamento seja mantido e a busca seja eficiente.
O funcionamento de cada função, incluindo seus parâmetros e valores de retornos estão explicitados em **árvore.h**.
### Funções da interface
Nesse projeto o grupo optou por não utilizar o tradicional scanf() para ler entradas, a fim de experimentar um outro método que facilitasse o tratamento das entradas do usuário (código de tratamento que utilizou como base o texto disponível em [“A beginners' guide away from scanf()”](http://sekrit.de/webdocs/c/beginners-guide-away-from-scanf.html). Além disso, as funções da interface apenas garantem que seja lida uma operação e um parâmetro que por meio da main() são usados para realizar operações na árvore B.
A leitura com tratamento da entrada foi abstraída em uma função a fim de facilitar a leitura de dados da entrada padrão. Verificações adicionais, como na leitura da ordem utilizada na árvore foram feitas em suas respectivas funções, ainda usando a função lerInteiro() como base.
### Funções de teste
As funções do arquivo teste.c servem primariamente para acomodar as entradas em forma de arquivo e imprimir informações sobre na tela para que o usuário acompanhe e diagnostique os possíveis problemas que podem surgir nos testes.
Os testes automatizados incluem uma “operação” nova, utilizada exclusivamente para imprimir uma mensagem na tela com o fim de ajudar no entendimento do resultado esperado para uma dada seção dos testes. Como sempre, comentários mais aprofundados sobre os parâmetros, objetivos da função e valores de retorno estão explicitados em teste.h.