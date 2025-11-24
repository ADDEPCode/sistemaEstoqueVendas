#include <iostream>  // Permite usar cout e cin (entrada e saída de dados)
#include <string>    // Permite usar o tipo string
#include <vector>    // Permite usar vetores dinâmicos
#include <cmath>     // Funções matemáticas: pow(), sqrt()
#include <iomanip>   // Formatação de saída: setprecision(), fixed
#include <limits>    // Para limpar o buffer quando há erro no cin
#include <cstdlib>   // system("cls") ou system("clear")

using namespace std;

/* ================================================================
    DECLARAÇÃO DE FUNÇÕES
    (As funções são criadas aqui e implementadas no final do arquivo)
   ================================================================ */

/**
 * Pede uma senha ao usuário e valida.
 * Usa WHILE e limita 3 tentativas.
 */
bool realizarLogin(string senhaCorreta);

/**
 * Calcula preço de venda usando potência.
 * Ex.: custo * (1 + margem/100)^fator
 */
double calcularPrecoVenda(double custo, double margem, double fator);


/* ================================================================
    FUNÇÃO PRINCIPAL - MENU DO SISTEMA
   ================================================================ */
int main() {
    // Vetores usados para armazenar todos os produtos cadastrados
    vector<string> nomesProdutos;
    vector<double> precosCusto;
    vector<int> quantidadesEstoque;

    string senhaGerente = "estoque789"; // Senha da área restrita
    int opcao;

    // Configura saída para sempre mostrar valores com 2 casas decimais
    cout << fixed << setprecision(2);

    // Estrutura DO-WHILE que mantém o menu funcionando até o usuário sair
    do {
        // Exibição do menu
        cout << "\n\n=== SISTEMA DE CONTROLE DE ESTOQUE E VENDAS ===\n";
        cout << "1. Cadastrar Produto\n";
        cout << "2. Calcular Preco de Venda (com Potencia)\n";
        cout << "3. Relatorio de Estoque (com IF/ELSE)\n";
        cout << "4. Simular Vendas Mensais (com FOR)\n";
        cout << "5. Area do Gerente (com WHILE e Senha)\n";
        cout << "6. Analise de Desempenho (Raiz e Divisao)\n";
        cout << "0. Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        // Tratamento de erros caso o usuário digite algo inválido
        if (cin.fail()) {
            cout << "Entrada invalida. Digite um numero.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            opcao = -1;
            continue;
        }

        /* SWITCH CASE — Executa a opção escolhida */
        switch (opcao) {

            /* ---------------------- OPÇÃO 1 ---------------------- */
            case 1: {
                cout << "\n--- Cadastro de Produto ---\n";

                string nome;
                double preco;
                int qtd;

                // Limpa o buffer para permitir nome com espaços
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Nome do produto: ";
                getline(cin, nome);

                cout << "Preco de custo: ";
                cin >> preco;

                cout << "Quantidade: ";
                cin >> qtd;

                // Salva os dados nos vetores
                nomesProdutos.push_back(nome);
                precosCusto.push_back(preco);
                quantidadesEstoque.push_back(qtd);

                cout << "\nProduto cadastrado com sucesso!\n";
                break;
            }

            /* ---------------------- OPÇÃO 2 ---------------------- */
            case 2: {
                cout << "\n--- Calculo de Preco de Venda ---\n";

                if (nomesProdutos.empty()) {
                    cout << "Nenhum produto cadastrado.\n";
                    break;
                }

                // Mostra todos os produtos com seus índices
                for (int i = 0; i < nomesProdutos.size(); ++i)
                    cout << i << ": " << nomesProdutos[i] << "\n";

                int idx;
                cout << "Escolha o indice: ";
                cin >> idx;

                if (idx < 0 || idx >= nomesProdutos.size()) {
                    cout << "Indice invalido.\n";
                    break;
                }

                double margem, fator;
                cout << "Margem (%): ";
                cin >> margem;

                cout << "Fator de potencia: ";
                cin >> fator;

                // Chamada da função
                double precoVenda = calcularPrecoVenda(precosCusto[idx], margem, fator);

                cout << "Preco calculado: R$ " << precoVenda << "\n";
                break;
            }

            /* ---------------------- OPÇÃO 3 ---------------------- */
            case 3: {
                cout << "\n--- Relatorio de Estoque ---\n";

                if (nomesProdutos.empty()) {
                    cout << "Nenhum produto cadastrado.\n";
                    break;
                }

                // Exibe tabela de produtos
                for (int i = 0; i < nomesProdutos.size(); ++i) {
                    cout << i << " | "
                        << nomesProdutos[i] << " | "
                        << precosCusto[i] << " | "
                        << quantidadesEstoque[i] << " | ";

                    // IF/ELSE determinando o status
                    if (quantidadesEstoque[i] == 0)
                        cout << "EM FALTA\n";
                    else if (quantidadesEstoque[i] < 10)
                        cout << "ESTOQUE BAIXO\n";
                    else
                        cout << "OK\n";
                }
                break;
            }

            /* ---------------------- OPÇÃO 4 ---------------------- */
            case 4: {
                cout << "\n--- Simulacao de Vendas ---\n";

                double total = 0;

                // FOR repetindo 12 vezes (12 meses)
                for (int mes = 1; mes <= 12; ++mes) {
                    double venda = 500 * mes + (rand() % 1000);
                    total += venda;
                    cout << "Mes " << mes << ": R$ " << venda << "\n";
                }

                cout << "Total anual: R$ " << total << "\n";
                cout << "Media mensal: R$ " << total / 12 << "\n";
                break;
            }

            /* ---------------------- OPÇÃO 5 ---------------------- */
            case 5: {
                cout << "\n--- Area do Gerente ---\n";

                // Chama a função que controla a senha
                bool acesso = realizarLogin(senhaGerente);

                if (acesso)
                    cout << "Acesso liberado!\n";
                else
                    cout << "Acesso bloqueado.\n";

                break;
            }

            /* ---------------------- OPÇÃO 6 ---------------------- */
            case 6: {
                cout << "\n--- Analise de Desempenho ---\n";

                if (nomesProdutos.empty()) {
                    cout << "Nenhum produto cadastrado.\n";
                    break;
                }

                // Soma total de itens
                int total = 0;
                for (int qtd : quantidadesEstoque)
                    total += qtd;

                // Cálculo com raiz quadrada
                cout << "Total de itens: " << total << "\n";
                cout << "Indice (raiz): " << sqrt(total) << "\n";

                // Teste de divisão com resto zero
                int lote;
                cout << "Tamanho do lote: ";
                cin >> lote;

                cout << "Produtos divisiveis por " << lote << ":\n";
                for (int i = 0; i < nomesProdutos.size(); i++) {
                    if (quantidadesEstoque[i] % lote == 0)
                        cout << "- " << nomesProdutos[i] << "\n";
                }

                break;
            }

            case 0:
                cout << "\nSaindo do sistema...\n";
                break;

            default:
                cout << "Opcao invalida. Tente novamente.\n";
        }

        // Pausa antes de retornar ao menu
        if (opcao != 0) {
            cout << "Pressione Enter...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
        }

    } while (opcao != 0);

    return 0;
}


/* ================================================================
    IMPLEMENTAÇÃO DAS FUNÇÕES
   ================================================================ */

/* Controle de login com no máximo 3 tentativas */
bool realizarLogin(string senhaCorreta) {
    string senha;
    int tentativas = 0;

    while (tentativas < 3) {
        cout << "Digite a senha: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, senha);

        if (senha == senhaCorreta)
            return true;

        cout << "Senha incorreta.\n";
        tentativas++;
    }
    return false;
}

/* Cálculo de preço usando potência matemática */
double calcularPrecoVenda(double custo, double margem, double fator) {
    double multiplicador = 1 + margem / 100.0;
    return custo * pow(multiplicador, fator);
}
