# Hash_table
 Trabalho 2 da disciplina de Algoritmos e Estrutura de Dados 2

Discentes: Luís Henrique    
            João Marcos Araújo Maia
            Hugo Moisés

Docente: Wanderley de Souza Alencar


**Descrição do Trabalho
Certifique-se de que você tenha instalado o compilador de c++ (g++/gnu)
Certifique-se que você tenha instalador um interpretador de python que contemple a versão acima do python 3.8

O programa consiste em um armazenador de senhas, onde a senha é uma string e sua chave correspondente na tabela hash é um double

O programa possui todas as funções tradicionais de uma tabela hash abordada em qualquer bibliografia, para mais dúvidas consulte o pdf ou o help do programa

para executar, digite:
g++ hash.cpp -o main

Além disso, nosso programa possui uma automatização para testar a eficiência da tabela hash, onde:
em um script de python (arquivo senhas.py) você pode inserir a quantidade de senhas , bem como o seu tamanho maximo e minimo a serem gerados pelo script
Para executar é só digitar, python3 senhas.py
Todas as senhas serão geradas no arquivo senhas.txt, de acordo com as suas alterações

A partir disso, entre no programa e selecione a funão 7, que lê todas as senhas do arquivo texto
Depois disso, selecione a opção 6 de mostrar a tabela, bem como a opção 3 de mostrar o desempnho e estatística da tabela hash!
Assim você pode ir testando e brincando com seu mais novo gerenciador de senhas feito em uma tabela hash!!

Lembre-se que o número de colisões e o fator de carga são necessariamente dependentes do tamanho da tabela hahs, bem como 
da quantidade de senhas que você colocou
Não adianta nada colocar o tamanho da tabela como 10 e escrever 1000 senhas, obviamente haverá 990 colisões e o fator de carga será ruim
Selecione uma quantidade racional de senhas e um tamanho bom.

Segue um teste prático:

Altere no script python o número de senhas para 100 e execute

no programa escrito em c++, execute-o
crie uma tabela com 300 elementos 
leia o arquivo texto
mostre as estatísticas

Lembre-se que como as senhas são geradas uma por uma
por escolha de implementação, as senhas são inseridas de maneira consecutivas na tabela hash (um senha após a outra) 
e não de forma aleatória... 
Este fato pode acarretar também uma falsa sensação de efetividade nos testes, por isso:
sempre adicione mais casos aleatórios, em posições aleatórias (infelizmente, isso tem que ser feito de maneira manual)

A implementação da tabela hash foi feita por meio de listas ligadas (chains):

m = tamanho da tabela hash
n = número de intens inseridos

fator de carga α = n/m

tempo para procurar = O(1 + α)
tempo para deletar = O(1 + α)
tempo para inserir = O(1)

O manual da tabela hash se encontra no pdf dentro do arquivo .zip