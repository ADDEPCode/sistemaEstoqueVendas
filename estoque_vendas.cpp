#include <iostream>  
#include <string>    
#include <vector>    
#include <cmath>     
#include <iomanip>   
#include <limits>    
#include <cstdlib>   

using namespace std;

/* ================================================================
    DECLARAÇÃO DE FUNÇÕES 
   ================================================================ */

/* ===================== PARTE DO ANDERSON ===================== 
    Anderson: Responsável pela documentação, modularização,
    boas práticas e clareza estrutural das funções.
*/
bool realizarLogin(string senhaCorreta);
double calcularPrecoVenda(double custo, double margem, double fator);


/* ================================================================
    FUNÇÃO PRINCIPAL - MENU DO SISTEMA
   ================================================================ */
int main() {

    /* ===================== PARTE DO EMERSON =====================
        Emerson: Responsável pelos vetores que armazenam os produtos.
        Esses vetores são a base de todo o controle de estoque.
    */
    vector<string> nomesProdutos;
    vector<double> precosCusto;
    vector<int> quantidadesEstoque;

    string senhaGerente = "estoque789";
    int opcao;

    cout << fixed << setprecision(2);

    /* ===================== PARTE DO DIEGO =====================
        Diego: Desenvolvimento do menu principal e navegação entre as opções.
    */
    do {
        cout << "\n\n=== SISTEMA DE CONTROLE DE ESTOQUE E VENDAS ===\n";
        cout << "1. Cadastrar Produto\n";
        cout << "2. Calcular Preco de Venda (com Potencia)\n";
        cout << "3. Relatorio de Estoque (IF/ELSE)\n";
        cout << "4. Simular Vendas Mensais (FOR)\n";
        cout << "5. Area do Gerente (WHILE e Senha)\n";
        cout << "6. Analise de Desempenho (Raiz e Divisao)\n";
        cout << "0. Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        /* ===================== PARTE DO ANDERSON =====================
            Anderson: Tratamento de erros, validação de entradas
        */
        if (cin.fail()) {
            cout << "Entrada invalida. Use numeros.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            opcao = -1;
            continue;
        }


        switch (opcao) {

            /* ===================== PARTE DO EMERSON =====================
                Emerson: Cadastro e gerenciamento dos produtos no estoque.
            */
            case 1: {
                cout << "\n--- Cadastro de Produto ---\n";

                string nome;
                double preco;
                int qtd;

                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Nome do produto: ";
                getline(cin, nome);

                cout << "Preco de custo: ";
                cin >> preco;

                cout << "Quantidade: ";
                cin >> qtd;

                nomesProdutos.push_back(nome);
                precosCusto.push_back(preco);
                quantidadesEstoque.push_back(qtd);

                cout << "\nProduto cadastrado com sucesso!\n";
                break;
            }

            /* ===================== PARTE DO EVANDRO =====================
                Evandro: Cálculo matemático usando potência.
                Responsável pela opção 2.
            */
            case 2: {
                cout << "\n--- Calculo de Preco de Venda ---\n";

                if (nomesProdutos.empty()) {
                    cout << "Nenhum produto cadastrado.\n";
                    break;
                }

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

                double precoVenda = calcularPrecoVenda(precosCusto[idx], margem, fator);

                cout << "Preco calculado: R$ " << precoVenda << "\n";
                break;
            }

            /* ===================== PARTE DO EMERSON =====================
                Emerson: Relatório de estoque com lógica IF/ELSE.
            */
            case 3: {
                cout << "\n--- Relatorio de Estoque ---\n";

                if (nomesProdutos.empty()) {
                    cout << "Nenhum produto cadastrado.\n";
                    break;
                }

                for (int i = 0; i < nomesProdutos.size(); ++i) {
                    cout << i << " | "
                        << nomesProdutos[i] << " | "
                        << precosCusto[i] << " | "
                        << quantidadesEstoque[i] << " | ";

                    if (quantidadesEstoque[i] == 0)
                        cout << "EM FALTA\n";
                    else if (quantidadesEstoque[i] < 10)
                        cout << "ESTOQUE BAIXO\n";
                    else
                        cout << "OK\n";
                }
                break;
            }

            /* ===================== PARTE DO PAULO =====================
                Paulo: Simulação de vendas e controle usando FOR.
                Responsável pela parte lógica da repetição.
            */
            case 4: {
                cout << "\n--- Simulacao de Vendas ---\n";

                double total = 0;

                for (int mes = 1; mes <= 12; ++mes) {
                    double venda = 500 * mes + (rand() % 1000);
                    total += venda;
                    cout << "Mes " << mes << ": R$ " << venda << "\n";
                }

                cout << "Total anual: R$ " << total << "\n";
                cout << "Media mensal: R$ " << total / 12 << "\n";
                break;
            }

            /* ===================== PARTE DO DIEGO =====================
                Diego: Área do gerente com controle de senha usando WHILE.
            */
            case 5: {
                cout << "\n--- Area do Gerente ---\n";

                bool acesso = realizarLogin(senhaGerente);

                if (acesso)
                    cout << "Acesso liberado!\n";
                else
                    cout << "Acesso bloqueado.\n";

                break;
            }

            /* ===================== PARTE DO EVANDRO =====================
                Evandro: Raiz quadrada e divisão com resto zero.
            */
            case 6: {
                cout << "\n--- Analise de Desempenho ---\n";

                if (nomesProdutos.empty()) {
                    cout << "Nenhum produto cadastrado.\n";
                    break;
                }

                int total = 0;
                for (int qtd : quantidadesEstoque)
                    total += qtd;

                cout << "Total de itens: " << total << "\n";
                cout << "Indice (raiz): " << sqrt(total) << "\n";

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

/* ===================== PARTE DO DIEGO =====================
    Login com limite de tentativas usando WHILE.
*/
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

/* ===================== PARTE DO EVANDRO =====================
    Função matemática com uso de pow() (potência).
*/
double calcularPrecoVenda(double custo, double margem, double fator) {
    double multiplicador = 1 + margem / 100.0;
    return custo * pow(multiplicador, fator);
}
