# AgenciaTurismo
Algoritmos II
Trabalho 2 BCC - T1 - Data de entrega: 01/10/2024

Escreva um programa para criar as seguintes estruturas que simularão arquivos indexados para uma aplicação de gerenciamento para uma Agência de Turismo:

Países: código_país, nome

Cidades: código_cidade, nome, UF, código_país

Guias: código_guia, nome, endereço, telefone, código_cidade

Clientes: código_cliente, nome, endereço, código_cidade

Pacotes: código_pacote, descrição, código_guia, valor_por_pessoa, total_participantes, quant_max_participantes

** Criar dois índices: código_pacote e código_guia

Vendas: código_venda, código_cliente, código_pacote, quantidade_pessoas, valor_total

** Criar dois índices: código_venda e código_cliente

1) Escreva funções específicas para a leitura dos dados das estruturas: Países, Cidades.

2) Escreva uma função para permitir a inclusão de novos registros na tabela de Guias.

2.1) O programa deverá garantir que o código do guia a ser inserido não existe na tabela de Guias.

2.2) Quando o usuário digitar o código da cidade, o programa deverá buscar este código na tabela de Cidades e exibir o nome da cidade e UF e o nome do País.



3) Escreva uma função para permitir a inclusão de novos registros na tabela de Clientes.

3.1) O programa deverá garantir que o código do cliente a ser inserido não existe na tabela de clientes.

3.2) Quando o usuário digitar o código da cidade, o programa deverá buscar este código na tabela de Cidades e exibir o nome da cidade e UF e o nome do País.



4) Escreva uma função para permitir a exclusão de registros na tabela de Clientes.

4.1) O programa não deverá permitir a exclusão de clientes que possuam vendas cadastradas em seu nome.



5) Escreva uma função para permitir a exclusão de registros na tabela de Guias.

5.1) O programa não deverá permitir a exclusão de guias que possuam pacotes cadastrados em seu nome.



6) Escreva uma função para permitir a inclusão de novos registros na tabela de Pacotes.

6.1) Quando o usuário digitar o código do guia, o programa deverá buscar este código na tabela de Guias e exibir o nome do guia, o nome da cidade e o nome do país.



7) Escreva uma função para permitir a inclusão de novos registros na tabela de Vendas.

7.1) Quando o usuário digitar o código_cliente, o programa deverá buscar este código na tabela de Clientes e exibir seu nome e o nome da sua cidade.

7.2) Quando o usuário digitar o código_pacote, o programa deverá buscar este código na tabela de Pacotes e exibir a descrição, o nome do guia e o valor por pessoa.

7.3) Quando o usuário digitar quantidade_pessoas, o programa deverá adicionar esta informação ao total_participantes da tabela de Pacotes.

7.3.1) O programa não deverá permitir que o total_participantes seja maior do que quant_max_participantes.

7.4) O programa deverá calcular e exibir o valor total a ser pago pelo cliente e gravar essa informação em valor_total na tabela Vendas.



8) Escreva uma função para permitir ao usuário consultar os dados de determinado pacote.

8.1) Para cada pacote consultado, exibir: todos os seus dados e o valor total arrecadado pelo pacote (valor_por_pessoa * total_participantes).



9) Escreva uma função para exibir todos os registros da tabela Pacotes que tenham sido completamente vendidos (total_participantes = quant_max_participantes).

9.1) As seguintes informações devem ser exibidas: código, descrição, nome do guia, valor total arrecadado pelo pacote (valor_por_pessoa * total_participantes).



10) Escreva uma função para exibir todos os registros da tabela de vendas. 

10.1) As seguintes informações devem ser exibidas: código, nome do cliente, descrição do pacote, quantidade_pessoas e valor_total da venda.

10.2) Ao final, a função deverá exibir o valor total vendido.



11) Escreva uma função para reorganização da tabela de Clientes.

Todas as funções descritas acima deverão ser chamadas através de um menu de opções que será chamado a partir da função main().

Obs: não utilizar variáveis globais.
