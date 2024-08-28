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
bool clienteExiste(const std::vector<Cliente>& clientes, int codigo_cliente) {
    return std::any_of(clientes.begin(), clientes.end(), [codigo_cliente](const Cliente& c) {
        return c.codigo_cliente == codigo_cliente;
    });
}

void incluirCliente(std::vector<Cliente>& clientes, std::vector<Cidade>& cidades, std::vector<Pais>& paises) {
    // Adicionando dados de exemplo
    clientes = {
        {1, "Cliente 1", "Endereço 1"},
        {2, "Cliente 2", "Endereço 2"},
        {3, "Cliente 3", "Endereço 3"},
        {4, "Cliente 4", "Endereço 4"},
        {5, "Cliente 5", "Endereço 5"}
    };

    cidades = {
        {1, "Cidade 1", "UF1", 1},
        {2, "Cidade 2", "UF2", 2},
        {3, "Cidade 3", "UF3", 3},
        {4, "Cidade 4", "UF4", 4},
        {5, "Cidade 5", "UF5", 5}
    };

    paises = {
        {1, "Pais 1"},
        {2, "Pais 2"},
        {3, "Pais 3"},
        {4, "Pais 4"},
        {5, "Pais 5"}
    };

    int codigo_cliente, codigo_cidade;
    std::string nome, endereco;
    std::cout << "Digite o código do cliente: ";
    std::cin >> codigo_cliente;
    if (clienteExiste(clientes, codigo_cliente)) {
        std::cout << "Código de cliente já existe!" << std::endl;
        return;
    }

    // Resto do código da função...
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
//Funções de Consulta e Exibição
void consultarPacote(const std::vector<Pacote>& pacotes, const std::vector<Guia>& guias) {
    int codigo_pacote;
    std::cout << "Digite o código do pacote a ser consultado: ";
    std::cin >> codigo_pacote;

    auto pacote = std::find_if(pacotes.begin(), pacotes.end(), [codigo_pacote](const Pacote& p) {
        return p.codigo_pacote == codigo_pacote;
    });

    if (pacote != pacotes.end()) {
        auto guia = std::find_if(guias.begin(), guias.end(), [pacote](const Guia& g) {
            return g.codigo_guia == pacote->codigo_guia;
        });
        if (guia != guias.end()) {
            std::cout << "Código: " << pacote->codigo_pacote << ", Descrição: " << pacote->descricao << ", Guia: " << guia->nome << ", Valor por pessoa: " << pacote->valor_por_pessoa << ", Total participantes: " << pacote->total_participantes << ", Valor total arrecadado: " << (pacote->valor_por_pessoa * pacote->total_participantes) << std::endl;
        } else {
            std::cout << "Guia não encontrado!" << std::endl;
        }
    } else {
        std::cout << "Pacote não encontrado!" << std::endl;
    }
}

void exibirPacotesCompletamenteVendidos(const std::vector<Pacote>& pacotes, const std::vector<Guia>& guias) {
    for (const auto& pacote : pacotes) {
        if (pacote.total_participantes == pacote.quant_max_participantes) {
            auto guia = std::find_if(guias.begin(), guias.end(), [pacote](const Guia& g) {
                return g.codigo_guia == pacote.codigo_guia;
            });
            if (guia != guias.end()) {
                std::cout << "Código: " << pacote.codigo_pacote << ", Descrição: " << pacote.descricao << ", Guia: " << guia->nome << ", Valor total arrecadado: " << (pacote.valor_por_pessoa * pacote.total_participantes) << std::endl;
            } else {
                std::cout << "Guia não encontrado!" << std::endl;
            }
        }
    }
}

void exibirVendas(const std::vector<Venda>& vendas, const std::vector<Cliente>& clientes, const std::vector<Pacote>& pacotes) {
    double valor_total_vendido = 0.0;
    for (const auto& venda : vendas) {
        auto cliente = std::find_if(clientes.begin(), clientes.end(), [venda](const Cliente& c) {
            return c.codigo_cliente == venda.codigo_cliente;
        });
        auto pacote = std::find_if(pacotes.begin(), pacotes.end(), [venda](const Pacote& p) {
            return p.codigo_pacote == venda.codigo_pacote;
        });
        if (cliente != clientes.end() && pacote != pacotes.end()) {
            std::cout << "Código: " << venda.codigo_venda << ", Cliente: " << cliente->nome << ", Descrição do pacote: " << pacote->descricao << ", Quantidade de pessoas: " << venda.quantidade_pessoas << ", Valor total: " << venda.valor_total << std::endl;
            valor_total_vendido += venda.valor_total;
        } else {
            std::cout << "Cliente ou pacote não encontrado!" << std::endl;
        }
    }
    std::cout << "Valor total vendido: " << valor_total_vendido << std::endl;
}
// Função de Reorganização
void reorganizarClientes(std::vector<Cliente>& clientes) {
    std::sort(clientes.begin(), clientes.end(), [](const Cliente& a, const Cliente& b) {
        return a.codigo_cliente < b.codigo_cliente;
    });
    std::cout << "Tabela de clientes reorganizada!" << std::endl;
}
//Menu Principal
void exibirMenu() {
    std::cout << "Menu de Opções:" << std::endl;
    std::cout << "1. Ler Países" << std::endl;
    std::cout << "2. Ler Cidades" << std::endl;
    std::cout << "3. Incluir Guia" << std::endl;
    std::cout << "4. Incluir Cliente" << std::endl;
    std::cout << "5. Excluir Cliente" << std::endl;
    std::cout << "6. Excluir Guia" << std::endl;
    std::cout << "7. Incluir Pacote" << std::endl;
    std::cout << "8. Incluir Venda" << std::endl;
    std::cout << "9. Consultar Pacote" << std::endl;
    std::cout << "10. Exibir Pacotes Completamente Vendidos" << std::endl;
    std::cout << "11. Exibir Vendas" << std::endl;
    std::cout << "12. Reorganizar Clientes" << std::endl;
    std::cout << "0. Sair" << std::endl;
}

int main() {
    std::vector<Pais> paises;
    std::vector<Cidade> cidades;
    std::vector<Guia> guias;
    std::vector<Cliente> clientes;
    std::vector<Pacote> pacotes;
    std::vector<Venda> vendas;

    int opcao;
    do {
        exibirMenu();
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;
        std::cin.ignore();

        switch (opcao) {
            case 1:
                lerPaises(paises);
                break;
            case 2:
                lerCidades(cidades);
                break;
            case 3:
                incluirGuia(guias, cidades, paises);
                break;
            case 4:
                incluirCliente(clientes, cidades, paises);
                break;
            case 5:
                excluirCliente(clientes, vendas);
                break;
            case 6:
                excluirGuia(guias, pacotes);
                break;
            case 7:
                incluirPacote(pacotes, guias, cidades, paises);
                break;
            case 8:
                incluirVenda(vendas, pacotes, clientes, cidades, paises);
                break;
            case 9:
                consultarPacote(pacotes, guias);
                break;
            case 10:
                exibirPacotesCompletamenteVendidos(pacotes, guias);
                break;
            case 11:
                exibirVendas(vendas, clientes, pacotes);
                break;
            case 12:
                reorganizarClientes(clientes);
                break;
            case 0:
                std::cout << "Saindo do programa..." << std::endl;
                break;
            default:
                std::cout << "Opção inválida!" << std::endl;
                break;
        }
    } while (opcao != 0);

    return 0;
}
