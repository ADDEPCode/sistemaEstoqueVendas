/*
    ANDERSON LUÍS PINHEIRO
    DIEGO HENRIQUE CARLOS
    EMERSON MILTON FERREIRA
    EVANDRO GABRIEL CAMPOS DE AZEVEDO
    PAULO EDUARDO COROLIN
*/

#include <iostream> // entrada/saída
#include <vector> // vetor dinâmico para produtos
#include <string> // strings
#include <cmath> // funções matemáticas (sqrt, pow)
#include <cstdlib> // rand, srand
#include <ctime> // time para srand
#include <iomanip> // manipulação de formato (setprecision, fixed)

using namespace std; // evita std:: em todo lugar

// Estrutura de produto
struct Produto { // define tipo Produto
    string nome; // nome do produto
    double preco; // preço unitário
    int estoque; // quantidade em estoque
};

// Função para cadastrar produto
void cadastrarProduto(vector<Produto> &produtos) { // recebe referência ao vetor
    Produto p; // cria produto temporário
    cin.ignore(); // descarta '\n' pendente no buffer
    cout << "Nome do produto: "; // pede nome
    getline(cin, p.nome); // lê linha inteira para nome

    cout << "Preco: "; // pede preço
    cin >> p.preco; // lê preço

    cout << "Estoque: "; // pede estoque
    cin >> p.estoque; // lê estoque

    produtos.push_back(p); // adiciona ao vetor
    cout << "Produto cadastrado com sucesso!\n"; // confirmação
}

// Função de cálculo de preço com potência
double calcularPrecoVenda(double custo, double margem, double fator) { // calcula preço final
    double multiplicador = 1 + margem / 100.0; // converte margem percentual
    return custo * pow(multiplicador, fator); // aplica potência e retorna
}

// Relatório de estoque
void relatorioEstoque(const vector<Produto> &produtos) { // recebe vetor const
    cout << "\n--- Relatorio de Estoque ---\n"; // cabeçalho

    for (size_t i = 0; i < produtos.size(); i++) { // itera índices
        string status = (produtos[i].estoque < 10 ? "ESTOQUE BAIXO" : "OK"); // status condicional

        cout << i << " | " << produtos[i].nome // imprime índice e nome
            << " | " << fixed << setprecision(2) << produtos[i].preco // imprime preço formatado
            << " | " << produtos[i].estoque // imprime estoque
            << " | " << status << "\n"; // imprime status e quebra de linha
    }

    cout << "Pressione Enter..."; // pausa
    cin.ignore(); // consome '\n'
    cin.get(); // espera Enter
}

// 🔥 Nova simulação REAL de vendas
void simularVendasMensais(vector<Produto> &produtos) { // simula vendas diminuindo estoque
    if (produtos.empty()) { // verifica lista vazia
        cout << "Nenhum produto cadastrado.\n"; // mensagem
        return; // retorna sem fazer nada
    }

    cout << "\n--- Simulacao de Vendas (Usando Estoque Real) ---\n"; // cabeçalho

    double totalAnual = 0; // acumula faturamento anual

    for (int mes = 1; mes <= 12; mes++) { // loop 12 meses
        cout << "\n=== Mes " << mes << " ===\n"; // mostra mês
        double totalMes = 0; // acumula faturamento do mês

        for (auto &p : produtos) { // percorre produtos por referência

            if (p.estoque == 0) { // sem estoque
                cout << "- " << p.nome << ": sem estoque → vendeu 0 unidades → R$ 0.00\n"; // informa
                continue; // passa para o próximo produto
            }

            int qtdVendida = rand() % (p.estoque + 1); // quantidade vendida aleatória até estoque
            double faturamento = qtdVendida * p.preco; // calcula faturamento

            p.estoque -= qtdVendida; // reduz o estoque

            cout << "- " << p.nome // imprime resumo da venda
                << ": vendeu " << qtdVendida
                << " unidades → R$ " << fixed << setprecision(2)
                << faturamento << "\n";

            totalMes += faturamento; // soma ao total do mês
        }

        cout << "Total do mes: R$ " << fixed << setprecision(2) << totalMes << "\n"; // total mensal
        totalAnual += totalMes; // soma ao anual
    }

    cout << "\nTotal anual: R$ " << totalAnual << "\n"; // imprime total anual
    cout << "Media mensal: R$ " << totalAnual / 12.0 << "\n"; // imprime média mensal

    cout << "Pressione Enter..."; // pausa final
    cin.ignore(); // consome '\n'
    cin.get(); // espera Enter
}

// Área do gerente: valida senha usando WHILE
void areaGerente() { // bloco protegido por senha
    const string senhaCorreta = "1234"; // senha fixa
    string tentativa; // armazena tentativa do usuário

    cout << "\n--- Area do Gerente ---\n"; // cabeçalho
    cout << "Digite a senha: "; // pede senha
    cin >> tentativa; // lê tentativa

    while (tentativa != senhaCorreta) { // enquanto incorreta
        cout << "Senha incorreta. Tente novamente: "; // pede novamente
        cin >> tentativa; // lê nova tentativa
    }

    cout << "Acesso liberado!\n"; // acesso concedido
}

// Análise: raiz e divisão
void analiseDesempenho() { // realiza duas operações simples
    double valor; // valor para raiz

    cout << "Digite um numero para calcular a raiz: "; // pede número
    cin >> valor; // lê valor

    cout << "Raiz quadrada: " << sqrt(valor) << "\n"; // mostra raiz

    int a, b; // inteiros para divisão
    cout << "Digite dois numeros para verificar divisao inteira: "; // pede dois números
    cin >> a >> b; // lê a e b

    if (b != 0 && a % b == 0) // verifica divisibilidade e evita divisão por zero
        cout << a << " é divisível por " << b << "\n"; // caso divisível
    else
        cout << a << " NÃO é divisível por " << b << "\n"; // caso não divisível
}

// =============================
// =========== MAIN ============
// =============================
int main() { // ponto de entrada
    srand(time(0)); // inicializa gerador de números aleatórios

    vector<Produto> produtos = { // lista inicial de produtos
        {"Livro Senhor dos Anéis", 40.00, 50}, // produto 1
        {"Celular", 500.00, 10}, // produto 2
        {"Macbook Air", 5000.00, 5} // produto 3
    };

    int opcao; // armazena opção do menu

    do { // loop do menu
        cout << "\n=== SISTEMA DE CONTROLE DE ESTOQUE E VENDAS ===\n"; // título
        cout << "1. Cadastrar Produto\n"; // opção 1
        cout << "2. Calcular Preco de Venda (com Potencia)\n"; // opção 2
        cout << "3. Relatorio de Estoque (IF/ELSE)\n"; // opção 3
        cout << "4. Simular Vendas Mensais (FOR)\n"; // opção 4
        cout << "5. Area do Gerente (WHILE e Senha)\n"; // opção 5
        cout << "6. Analise de Desempenho (Raiz e Divisao)\n"; // opção 6
        cout << "0. Sair\n"; // opção 0
        cout << "Escolha uma opcao: "; // prompt

        if (!(cin >> opcao)) { // valida entrada numérica
            cin.clear(); // limpa estado de erro
            cin.ignore(1000, '\n'); // descarta entrada inválida
            cout << "Entrada invalida. Use numeros.\n"; // aviso
            continue; // volta ao menu
        }

        switch (opcao) { // trata opções
            case 1:
                cadastrarProduto(produtos); // chama cadastro
                break;

            case 2: {
                double custo, margem, fator; // parâmetros para cálculo
                cout << "Custo: "; // pede custo
                cin >> custo; // lê custo
                cout << "Margem (%): "; // pede margem
                cin >> margem; // lê margem
                cout << "Fator: "; // pede fator
                cin >> fator; // lê fator

                cout << "Preco de venda: R$ "
                    << calcularPrecoVenda(custo, margem, fator) << "\n"; // mostra resultado
                break;
            }

            case 3:
                relatorioEstoque(produtos); // mostra relatório
                break;

            case 4:
                simularVendasMensais(produtos); // simula vendas
                break;

            case 5:
                areaGerente(); // área do gerente
                break;

            case 6:
                analiseDesempenho(); // executa análise
                break;

            case 0:
                cout << "Saindo...\n"; // saída
                break;

            default:
                cout << "Opcao invalida!\n"; // opção inválida
        }

    } while (opcao != 0); // repete até escolher sair

    return 0; // finaliza programa
}

