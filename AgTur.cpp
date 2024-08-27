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
bool clienteTemVendas(const std::vector<Venda>& vendas, int codigo_cliente) {
    return std::any_of(vendas.begin(), vendas.end(), [codigo_cliente](const Venda& v) {
        return v.codigo_cliente == codigo_cliente;
    });
}

void excluirCliente(std::vector<Cliente>& clientes, const std::vector<Venda>& vendas) {
    int codigo_cliente;
    std::cout << "Digite o código do cliente a ser excluído: ";
    std::cin >> codigo_cliente;

    auto cliente = std::find_if(clientes.begin(), clientes.end(), [codigo_cliente](const Cliente& c) {
        return c.codigo_cliente == codigo_cliente;
    });

    if (cliente != clientes.end()) {
        if (clienteTemVendas(vendas, codigo_cliente)) {
            std::cout << "Não é possível excluir o cliente. Ele possui vendas cadastradas." << std::endl;
        } else {
            clientes.erase(cliente);
            std::cout << "Cliente excluído com sucesso!" << std::endl;
        }
    } else {
        std::cout << "Cliente não encontrado!" << std::endl;
    }
}

bool guiaTemPacotes(const std::vector<Pacote>& pacotes, int codigo_guia) {
    return std::any_of(pacotes.begin(), pacotes.end(), [codigo_guia](const Pacote& p) {
        return p.codigo_guia == codigo_guia;
    });
}

void excluirGuia(std::vector<Guia>& guias, const std::vector<Pacote>& pacotes) {
    int codigo_guia;
    std::cout << "Digite o código do guia a ser excluído: ";
    std::cin >> codigo_guia;

    auto guia = std::find_if(guias.begin(), guias.end(), [codigo_guia](const Guia& g) {
        return g.codigo_guia == codigo_guia;
    });

    if (guia != guias.end()) {
        if (guiaTemPacotes(pacotes, codigo_guia)) {
            std::cout << "Não é possível excluir o guia. Ele possui pacotes cadastrados." << std::endl;
        } else {
            guias.erase(guia);
            std::cout << "Guia excluído com sucesso!" << std::endl;
        }
    } else {
        std::cout << "Guia não encontrado!" << std::endl;
    }
}
// Funções de Inclusão de Pacotes e Vendas
void incluirPacote(std::vector<Pacote>& pacotes, const std::vector<Guia>& guias, const std::vector<Cidade>& cidades, const std::vector<Pais>& paises) {
    int codigo_pacote, codigo_guia, quant_max_participantes;
    std::string descricao;
    double valor_por_pessoa;
    std::cout << "Digite o código do pacote: ";
    std::cin >> codigo_pacote;
    std::cin.ignore();
    std::cout << "Digite a descrição do pacote: ";
    std::getline(std::cin, descricao);
    std::cout << "Digite o código do guia: ";
    std::cin >> codigo_guia;

    auto guia = std::find_if(guias.begin(), guias.end(), [codigo_guia](const Guia& g) {
        return g.codigo_guia == codigo_guia;
    });

    if (guia != guias.end()) {
        auto cidade = std::find_if(cidades.begin(), cidades.end(), [guia](const Cidade& c) {
            return c.codigo_cidade == guia->codigo_cidade;
        });
        if (cidade != cidades.end()) {
            auto pais = std::find_if(paises.begin(), paises.end(), [cidade](const Pais& p) {
                return p.codigo_pais == cidade->codigo_pais;
            });
            if (pais != paises.end()) {
                std::cout << "Guia: " << guia->nome << ", Cidade: " << cidade->nome << ", País: " << pais->nome << std::endl;
                std::cout << "Digite o valor por pessoa: ";
                std::cin >> valor_por_pessoa;
                std::cout << "Digite a quantidade máxima de participantes: ";
                std::cin >> quant_max_participantes;
                pacotes.push_back({codigo_pacote, descricao, codigo_guia, valor_por_pessoa, 0, quant_max_participantes});
            } else {
                std::cout << "País não encontrado!" << std::endl;
            }
        } else {
            std::cout << "Cidade não encontrada!" << std::endl;
        }
    } else {
        std::cout << "Guia não encontrado!" << std::endl;
    }
}

void incluirVenda(std::vector<Venda>& vendas, std::vector<Pacote>& pacotes, const std::vector<Cliente>& clientes, const std::vector<Cidade>& cidades, const std::vector<Pais>& paises) {
    int codigo_venda, codigo_cliente, codigo_pacote, quantidade_pessoas;
    std::cout << "Digite o código da venda: ";
    std::cin >> codigo_venda;
    std::cout << "Digite o código do cliente: ";
    std::cin >> codigo_cliente;

    auto cliente = std::find_if(clientes.begin(), clientes.end(), [codigo_cliente](const Cliente& c) {
        return c.codigo_cliente == codigo_cliente;
    });

    if (cliente != clientes.end()) {
        auto cidade = std::find_if(cidades.begin(), cidades.end(), [cliente](const Cidade& c) {
            return c.codigo_cidade == cliente->codigo_cidade;
        });
        if (cidade != cidades.end()) {
            auto pais = std::find_if(paises.begin(), paises.end(), [cidade](const Pais& p) {
                return p.codigo_pais == cidade->codigo_pais;
            });
            if (pais != paises.end()) {
                std::cout << "Cliente: " << cliente->nome << ", Cidade: " << cidade->nome << ", País: " << pais->nome << std::endl;
                std::cout << "Digite o código do pacote: ";
                std::cin >> codigo_pacote;

                auto pacote = std::find_if(pacotes.begin(), pacotes.end(), [codigo_pacote](const Pacote& p) {
                    return p.codigo_pacote == codigo_pacote;
                });

                if (pacote != pacotes.end()) {
                    std::cout << "Descrição do pacote: " << pacote->descricao << ", Valor por pessoa: " << pacote->valor_por_pessoa << std::endl;
                    std::cout << "Digite a quantidade de pessoas: ";
                    std::cin >> quantidade_pessoas;

                    if (pacote->total_participantes + quantidade_pessoas <= pacote->quant_max_participantes) {
                        double valor_total = quantidade_pessoas * pacote->valor_por_pessoa;
                        vendas.push_back({codigo_venda, codigo_cliente, codigo_pacote, quantidade_pessoas, valor_total});
                        pacote->total_participantes += quantidade_pessoas;
                        std::cout << "Valor total a ser pago: " << valor_total << std::endl;
                    } else {
                        std::cout << "Quantidade de participantes excede o limite máximo!" << std::endl;
                    }
                } else {
                    std::cout << "Pacote não encontrado!" << std::endl;
                }
            } else {
                std::cout << "País não encontrado!" << std::endl;
            }
        } else {
            std::cout << "Cidade não encontrada!" << std::endl;
        }
    } else {
        std::cout << "Cliente não encontrado!" << std::endl;
    }
}
