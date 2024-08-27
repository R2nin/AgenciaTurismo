#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Pais {
    int codigo_pais;
    std::string nome;
};

struct Cidade {
    int codigo_cidade;
    std::string nome;
    std::string UF;
    int codigo_pais;
};

struct Guia {
    int codigo_guia;
    std::string nome;
    std::string endereco;
    std::string telefone;
    int codigo_cidade;
};

struct Cliente {
    int codigo_cliente;
    std::string nome;
    std::string endereco;
    int codigo_cidade;
};

struct Pacote {
    int codigo_pacote;
    std::string descricao;
    int codigo_guia;
    double valor_por_pessoa;
    int total_participantes;
    int quant_max_participantes;
};

struct Venda {
    int codigo_venda;
    int codigo_cliente;
    int codigo_pacote;
    int quantidade_pessoas;
    double valor_total;
};
