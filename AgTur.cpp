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
// Funções de Leitura
void lerPaises(std::vector<Pais>& paises) {
    int codigo_pais;
    std::string nome;
    std::cout << "Digite o código do país: ";
    std::cin >> codigo_pais;
    std::cin.ignore();
    std::cout << "Digite o nome do país: ";
    std::getline(std::cin, nome);
    paises.push_back({codigo_pais, nome});
}

void lerCidades(std::vector<Cidade>& cidades) {
    int codigo_cidade, codigo_pais;
    std::string nome, UF;
    std::cout << "Digite o código da cidade: ";
    std::cin >> codigo_cidade;
    std::cin.ignore();
    std::cout << "Digite o nome da cidade: ";
    std::getline(std::cin, nome);
    std::cout << "Digite a UF da cidade: ";
    std::getline(std::cin, UF);
    std::cout << "Digite o código do país: ";
    std::cin >> codigo_pais;
    cidades.push_back({codigo_cidade, nome, UF, codigo_pais});
}
//Funções de Inclusão
bool guiaExiste(const std::vector<Guia>& guias, int codigo_guia) {
    return std::any_of(guias.begin(), guias.end(), [codigo_guia](const Guia& g) {
        return g.codigo_guia == codigo_guia;
    });
}

void incluirGuia(std::vector<Guia>& guias, const std::vector<Cidade>& cidades, const std::vector<Pais>& paises) {
    int codigo_guia, codigo_cidade;
    std::string nome, endereco, telefone;
    std::cout << "Digite o código do guia: ";
    std::cin >> codigo_guia;
    if (guiaExiste(guias, codigo_guia)) {
        std::cout << "Código de guia já existe!" << std::endl;
        return;
    }
    std::cin.ignore();
    std::cout << "Digite o nome do guia: ";
    std::getline(std::cin, nome);
    std::cout << "Digite o endereço do guia: ";
    std::getline(std::cin, endereco);
    std::cout << "Digite o telefone do guia: ";
    std::getline(std::cin, telefone);
    std::cout << "Digite o código da cidade: ";
    std::cin >> codigo_cidade;

    auto cidade = std::find_if(cidades.begin(), cidades.end(), [codigo_cidade](const Cidade& c) {
        return c.codigo_cidade == codigo_cidade;
    });

    if (cidade != cidades.end()) {
        auto pais = std::find_if(paises.begin(), paises.end(), [cidade](const Pais& p) {
            return p.codigo_pais == cidade->codigo_pais;
        });
        if (pais != paises.end()) {
            std::cout << "Cidade: " << cidade->nome << ", UF: " << cidade->UF << ", País: " << pais->nome << std::endl;
            guias.push_back({codigo_guia, nome, endereco, telefone, codigo_cidade});
        } else {
            std::cout << "País não encontrado!" << std::endl;
        }
    } else {
        std::cout << "Cidade não encontrada!" << std::endl;
    }
}

bool clienteExiste(const std::vector<Cliente>& clientes, int codigo_cliente) {
    return std::any_of(clientes.begin(), clientes.end(), [codigo_cliente](const Cliente& c) {
        return c.codigo_cliente == codigo_cliente;
    });
}

void incluirCliente(std::vector<Cliente>& clientes, const std::vector<Cidade>& cidades, const std::vector<Pais>& paises) {
    int codigo_cliente, codigo_cidade;
    std::string nome, endereco;
    std::cout << "Digite o código do cliente: ";
    std::cin >> codigo_cliente;
    if (clienteExiste(clientes, codigo_cliente)) {
        std::cout << "Código de cliente já existe!" << std::endl;
        return;
    }
    std::cin.ignore();
    std::cout << "Digite o nome do cliente: ";
    std::getline(std::cin, nome);
    std::cout << "Digite o endereço do cliente: ";
    std::getline(std::cin, endereco);
    std::cout << "Digite o código da cidade: ";
    std::cin >> codigo_cidade;

    auto cidade = std::find_if(cidades.begin(), cidades.end(), [codigo_cidade](const Cidade& c) {
        return c.codigo_cidade == codigo_cidade;
    });

    if (cidade != cidades.end()) {
        auto pais = std::find_if(paises.begin(), paises.end(), [cidade](const Pais& p) {
            return p.codigo_pais == cidade->codigo_pais;
        });
        if (pais != paises.end()) {
            std::cout << "Cidade: " << cidade->nome << ", UF: " << cidade->UF << ", País: " << pais->nome << std::endl;
            clientes.push_back({codigo_cliente, nome, endereco, codigo_cidade});
        } else {
            std::cout << "País não encontrado!" << std::endl;
        }
    } else {
        std::cout << "Cidade não encontrada!" << std::endl;
    }
}
//Funções de Exclusão
