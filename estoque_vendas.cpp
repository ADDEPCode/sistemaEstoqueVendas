#include <iostream>   // entrada/saída padrão
#include <string>     // manipulação de strings
#include <vector>     // uso de vetores dinâmicos
#include <cmath>      // funções matemáticas (pow, sqrt)
#include <iomanip>    // formatação de saída (setprecision, fixed)
#include <limits>     // limites de tipos e tratamento de entrada
#include <cstdlib>    // funções de utilidade (rand)

using namespace std; // uso do namespace std

/* ================================================================
    DECLARAÇÃO DE FUNÇÕES 
   ================================================================ */

/* ===================== PARTE DO ANDERSON ===================== 
    Anderson: Responsável pela documentação, modularização,
    boas práticas e clareza estrutural das funções.
*/
bool realizarLogin(string senhaCorreta); // protótipo: função de login
double calcularPrecoVenda(double custo, double margem, double fator); // protótipo: calcula preço

/* ================================================================
    FUNÇÃO PRINCIPAL - MENU DO SISTEMA
   ================================================================ */
int main() { // início da função principal

    /* ===================== PARTE DO EMERSON =====================
        Emerson: Responsável pelos vetores que armazenam os produtos.
        Esses vetores são a base de todo o controle de estoque.
    */
    vector<string> nomesProdutos; // vetor de nomes de produtos
    vector<double> precosCusto; // vetor de preços de custo
    vector<int> quantidadesEstoque; // vetor de quantidades em estoque

    string senhaGerente = "estoque789"; // senha fixa do gerente
    int opcao; // opção do menu

    cout << fixed << setprecision(2); // configura saída com 2 casas decimais

    /* ===================== PARTE DO DIEGO =====================
        Diego: Desenvolvimento do menu principal e navegação entre as opções.
    */
    do { // laço do menu principal
        cout << "\n\n=== SISTEMA DE CONTROLE DE ESTOQUE E VENDAS ===\n"; // cabeçalho
        cout << "1. Cadastrar Produto\n"; // opção 1
        cout << "2. Calcular Preco de Venda (com Potencia)\n"; // opção 2
        cout << "3. Relatorio de Estoque (IF/ELSE)\n"; // opção 3
        cout << "4. Simular Vendas Mensais (FOR)\n"; // opção 4
        cout << "5. Area do Gerente (WHILE e Senha)\n"; // opção 5
        cout << "6. Analise de Desempenho (Raiz e Divisao)\n"; // opção 6
        cout << "0. Sair\n"; // opção sair
        cout << "Escolha uma opcao: "; // solicita opção
        cin >> opcao; // lê opção

        /* ===================== PARTE DO ANDERSON =====================
            Anderson: Tratamento de erros, validação de entradas
        */
        if (cin.fail()) { // se leitura falhar
            cout << "Entrada invalida. Use numeros.\n"; // mensagem de erro
            cin.clear(); // limpa estado de erro
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // descarta entrada inválida
            opcao = -1; // força repetição do menu
            continue; // volta ao início do loop
        }


        switch (opcao) { // switch das opções do menu

            /* ===================== PARTE DO EMERSON =====================
                Emerson: Cadastro e gerenciamento dos produtos no estoque.
            */
            case 1: { // cadastrar produto
                cout << "\n--- Cadastro de Produto ---\n"; // título cadastro

                string nome; // nome temporário
                double preco; // preço temporário
                int qtd; // quantidade temporária

                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpa buffer antes do getline

                cout << "Nome do produto: "; // pede nome
                getline(cin, nome); // lê linha inteira com o nome

                cout << "Preco de custo: "; // pede preço
                cin >> preco; // lê preço

                cout << "Quantidade: "; // pede quantidade
                cin >> qtd; // lê quantidade

                nomesProdutos.push_back(nome); // adiciona nome ao vetor
                precosCusto.push_back(preco); // adiciona preço ao vetor
                quantidadesEstoque.push_back(qtd); // adiciona quantidade ao vetor

                cout << "\nProduto cadastrado com sucesso!\n"; // confirma cadastro
                break; // sai do case
            }

            /* ===================== PARTE DO EVANDRO =====================
                Evandro: Cálculo matemático usando potência.
                Responsável pela opção 2.
            */
            case 2: { // calcular preço de venda
                cout << "\n--- Calculo de Preco de Venda ---\n"; // título cálculo

                if (nomesProdutos.empty()) { // verifica se há produtos
                    cout << "Nenhum produto cadastrado.\n"; // avisa vazio
                    break; // volta ao menu
                }

                for (int i = 0; i < nomesProdutos.size(); ++i) // lista índices e nomes
                    cout << i << ": " << nomesProdutos[i] << "\n"; // imprime índice: nome

                int idx; // índice escolhido
                cout << "Escolha o indice: "; // pede índice
                cin >> idx; // lê índice

                if (idx < 0 || idx >= nomesProdutos.size()) { // valida índice
                    cout << "Indice invalido.\n"; // avisa inválido
                    break; // volta ao menu
                }

                double margem, fator; // recebe margem e fator
                cout << "Margem (%): "; // pede margem
                cin >> margem; // lê margem

                cout << "Fator de potencia: "; // pede fator
                cin >> fator; // lê fator

                double precoVenda = calcularPrecoVenda(precosCusto[idx], margem, fator); // calcula preço

                cout << "Preco calculado: R$ " << precoVenda << "\n"; // mostra resultado
                break; // sai do case
            }

            /* ===================== PARTE DO EMERSON =====================
                Emerson: Relatório de estoque com lógica IF/ELSE.
            */
            case 3: { // relatório de estoque
                cout << "\n--- Relatorio de Estoque ---\n"; // título relatório

                if (nomesProdutos.empty()) { // se sem produtos
                    cout << "Nenhum produto cadastrado.\n"; // avisa
                    break; // volta ao menu
                }

                for (int i = 0; i < nomesProdutos.size(); ++i) { // percorre produtos
                    cout << i << " | " // imprime índice
                        << nomesProdutos[i] << " | " // imprime nome
                        << precosCusto[i] << " | " // imprime preço de custo
                        << quantidadesEstoque[i] << " | "; // imprime quantidade

                    if (quantidadesEstoque[i] == 0) // se zero
                        cout << "EM FALTA\n"; // marca em falta
                    else if (quantidadesEstoque[i] < 10) // estoque baixo
                        cout << "ESTOQUE BAIXO\n"; // marca baixo
                    else
                        cout << "OK\n"; // marca ok
                }
                break; // sai do case
            }

            /* ===================== PARTE DO PAULO =====================
                Paulo: Simulação de vendas e controle usando FOR.
                Responsável pela parte lógica da repetição.
            */
            case 4: { // simulação de vendas mensais
                cout << "\n--- Simulacao de Vendas ---\n"; // título simulação

                double total = 0; // acumulador total anual

                for (int mes = 1; mes <= 12; ++mes) { // para cada mês
                    double venda = 500 * mes + (rand() % 1000); // calcula venda aleatória
                    total += venda; // acumula total
                    cout << "Mes " << mes << ": R$ " << venda << "\n"; // imprime mês e venda
                }

                cout << "Total anual: R$ " << total << "\n"; // imprime total anual
                cout << "Media mensal: R$ " << total / 12 << "\n"; // imprime média mensal
                break; // sai do case
            }

            /* ===================== PARTE DO DIEGO =====================
                Diego: Área do gerente com controle de senha usando WHILE.
            */
            case 5: { // área do gerente
                cout << "\n--- Area do Gerente ---\n"; // título área gerente

                bool acesso = realizarLogin(senhaGerente); // tenta login

                if (acesso)
                    cout << "Acesso liberado!\n"; // sucesso
                else
                    cout << "Acesso bloqueado.\n"; // falha

                break; // sai do case
            }

            /* ===================== PARTE DO EVANDRO =====================
                Evandro: Raiz quadrada e divisão com resto zero.
            */
            case 6: { // análise de desempenho
                cout << "\n--- Analise de Desempenho ---\n"; // título análise

                if (nomesProdutos.empty()) { // sem produtos
                    cout << "Nenhum produto cadastrado.\n"; // avisa
                    break; // volta ao menu
                }

                int total = 0; // soma de todos os itens
                for (int qtd : quantidadesEstoque) // soma quantidades
                    total += qtd; // acumula

                cout << "Total de itens: " << total << "\n"; // imprime total
                cout << "Indice (raiz): " << sqrt(total) << "\n"; // imprime raiz quadrada

                int lote; // tamanho do lote
                cout << "Tamanho do lote: "; // pede lote
                cin >> lote; // lê lote

                cout << "Produtos divisiveis por " << lote << ":\n"; // título divisíveis
                for (int i = 0; i < nomesProdutos.size(); i++) { // percorre produtos
                    if (quantidadesEstoque[i] % lote == 0) // se divisível
                        cout << "- " << nomesProdutos[i] << "\n"; // imprime nome
                }

                break; // sai do case
            }

            case 0: // opção sair
                cout << "\nSaindo do sistema...\n"; // mensagem de saída
                break; // sai do switch

            default: // opção inválida
                cout << "Opcao invalida. Tente novamente.\n"; // mensagem inválida
        }

        if (opcao != 0) { // se não está saindo
            cout << "Pressione Enter..."; // pede enter para continuar
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpa buffer
            cin.get(); // espera Enter
        }

    } while (opcao != 0); // repete até escolher 0

    return 0; // encerra programa
}

/* ================================================================
    IMPLEMENTAÇÃO DAS FUNÇÕES
   ================================================================ */

/* ===================== PARTE DO DIEGO =====================
    Login com limite de tentativas usando WHILE.
*/
bool realizarLogin(string senhaCorreta) { // implementação do login
    string senha; // senha digitada
    int tentativas = 0; // contador de tentativas

    while (tentativas < 3) { // até 3 tentativas
        cout << "Digite a senha: "; // solicita senha
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpa buffer antes de getline
        getline(cin, senha); // lê senha completa

        if (senha == senhaCorreta) // compara senhas
            return true; // retorna sucesso

        cout << "Senha incorreta.\n"; // avisa incorreto
        tentativas++; // incrementa tentativas
    }
    return false; // retorna falha após tentativas
}

/* ===================== PARTE DO EVANDRO =====================
    Função matemática com uso de pow() (potência).
*/
double calcularPrecoVenda(double custo, double margem, double fator) { // calcula preço venda
    double multiplicador = 1 + margem / 100.0; // converte % para multiplicador
    return custo * pow(multiplicador, fator); // aplica potência e retorna
}
