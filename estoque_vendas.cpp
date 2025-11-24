#include <iostream>  // Para entrada e saída (cout, cin)
#include <string>    // Para usar o tipo 'string'
#include <vector>    // Para usar 'vector' (armazenamento dinâmico)
#include <cmath>     // Para funções matemáticas (pow, sqrt)
#include <iomanip>   // Para formatar a saída (setprecision, fixed)
#include <limits>    // Para limpar o buffer de entrada (numeric_limits)
#include <cstdlib>   // Para system("cls") ou system("clear")

using namespace std;

// --- Declaração das Funções (Implementação no final) ---

/**
 * @brief Solicita uma senha ao usuário e valida contra a senha correta.
 * Limita o número de tentativas (Requisito 4).
 * @param senhaCorreta A senha que deve ser digitada.
 * @return true se o login for bem-sucedido, false caso contrário.
 */
bool realizarLogin(string senhaCorreta);

/**
 * @brief Calcula o preço de venda com base no custo, margem e um fator.
 * Utiliza potência (Requisito 2).
 * @param custo O preço de custo do produto.
 * @param margem A margem de lucro desejada (em %).
 * @param fator O expoente 'n' para o cálculo (ex: 1 para margem simples).
 * @return O preço de venda calculado.
 */
double calcularPrecoVenda(double custo, double margem, double fator);

// --- Função Principal ---

int main() {
    // Vetores para armazenar os dados dos produtos (Requisito 8)
    vector<string> nomesProdutos;
    vector<double> precosCusto;
    vector<int> quantidadesEstoque;

    string senhaGerente = "estoque789"; // Senha para área do gerente
    int opcao;

    // Configura a saída de dados para mostrar 2 casas decimais para dinheiro
    cout << fixed << setprecision(2);

    // Loop DO-WHILE para o menu principal (Requisito 6)
    do {
        // Limpa a tela (opcional, mas melhora a usabilidade)
        // system("cls"); // Para Windows
        // system("clear"); // Para Linux/Mac
        cout << "\n\n=== SISTEMA DE CONTROLE DE ESTOQUE E VENDAS ===\n";
        cout << "================================================\n";
        cout << "1. Cadastrar Produto\n";
        cout << "2. Calcular Preco de Venda (com Potencia)\n";
        cout << "3. Relatorio de Estoque (com IF/ELSE)\n";
        cout << "4. Simular Vendas Mensais (com FOR simples)\n";
        cout << "5. Area do Gerente (com WHILE e Senha)\n";
        cout << "6. Analise de Desempenho (com Raiz e Divisao)\n";
        cout << "0. Sair\n";
        cout << "================================================\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        // Validação básica de entrada
        if (cin.fail()) {
            cout << "Entrada invalida. Por favor, digite um numero.\n";
            cin.clear(); // Limpa o estado de erro
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta a entrada ruim
            opcao = -1; // Força o loop a continuar
            continue;
        }

        // Menu principal com SWITCH CASE (Requisito 1)
        switch (opcao) {
            case 1: {
                // --- Cadastro de Produtos ---
                cout << "\n--- 1. Cadastro de Produto ---\n";
                string nome;
                double preco;
                int qtd;

                // Limpa o buffer antes de ler o nome (que pode ter espaços)
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

                cout << "Nome do produto: ";
                getline(cin, nome); // Permite nomes com espaço

                cout << "Preco de custo (R$): ";
                cin >> preco;

                cout << "Quantidade em estoque: ";
                cin >> qtd;

                // Adiciona aos vetores
                nomesProdutos.push_back(nome);
                precosCusto.push_back(preco);
                quantidadesEstoque.push_back(qtd);

                cout << "\nProduto '" << nome << "' cadastrado com sucesso!\n";
                break;
            }
            case 2: {
                // --- Cálculo de Preço de Venda (POTÊNCIA) ---
                cout << "\n--- 2. Calculo de Preco de Venda ---\n";
                if (nomesProdutos.empty()) {
                    cout << "Nenhum produto cadastrado para calcular o preco.\n";
                    break;
                }

                cout << "Selecione o produto pelo indice:\n";
                for (int i = 0; i < nomesProdutos.size(); ++i) {
                    cout << i << ": " << nomesProdutos[i] << "\n";
                }
                cout << "Indice: ";
                int idx;
                cin >> idx;

                if (idx < 0 || idx >= nomesProdutos.size()) {
                    cout << "Indice invalido.\n";
                    break;
                }

                double margem;
                double fator;
                cout << "Digite a margem de lucro (ex: 30 para 30%): ";
                cin >> margem;
                cout << "Digite o fator 'n' (ex: 1 para simples): ";
                cin >> fator;

                // Chama a função (Requisito 9)
                double precoVenda = calcularPrecoVenda(precosCusto[idx], margem, fator);

                cout << "\nPreco de Custo: R$ " << precosCusto[idx] << "\n";
                cout << "Margem: " << margem << "%, Fator: " << fator << "\n";
                cout << "Preco de Venda Calculado: R$ " << precoVenda << "\n";
                break;
            }
            case 3: {
                // --- Relatório de Estoque (IF/ELSE) ---
                cout << "\n--- 3. Relatorio de Estoque ---\n";
                if (nomesProdutos.empty()) {
                    cout << "Estoque vazio. Cadastre produtos primeiro.\n";
                    break;
                }

                cout << "----------------------------------------------------------\n";
                cout << "Indice | Produto            | Custo (R$) | Qtd. | Status\n";
                cout << "----------------------------------------------------------\n";

                // Laço FOR para iterar sobre o vetor (item 8)
                for (int i = 0; i < nomesProdutos.size(); ++i) {
                    cout << left; // Alinha texto à esquerda
                    cout << setw(7) << i << " | "
                        << setw(18) << nomesProdutos[i].substr(0, 18) << " | "
                        << setw(10) << precosCusto[i] << " | "
                        << setw(4) << quantidadesEstoque[i] << " | ";

                    // Uso de IF, ELSE IF, ELSE (Requisito 5)
                    if (quantidadesEstoque[i] == 0) {
                        cout << "EM FALTA";
                    } else if (quantidadesEstoque[i] < 10) {
                        cout << "ESTOQUE BAIXO";
                    } else {
                        cout << "OK";
                    }
                    cout << "\n";
                }
                cout << "----------------------------------------------------------\n";
                break;
            }
            case 4: {
                // --- Simulação de Vendas (FOR simples) ---
                cout << "\n--- 4. Simulacao de Vendas (12 meses) ---\n";
                double totalVendas = 0;
                double vendaMensal;

                // Laço FOR simples (sem iterar vetor) (Requisito 7)
                for (int mes = 1; mes <= 12; ++mes) {
                    // Simulação simples: venda aumenta a cada mês
                    vendaMensal = 500.0 * mes + (rand() % 1000); // Valor base + aleatório
                    totalVendas += vendaMensal;
                    cout << "Mes " << setw(2) << mes << ": R$ " << vendaMensal << "\n";
                }

                double mediaMensal = totalVendas / 12.0;
                cout << "-----------------------------------\n";
                cout << "Total de Vendas no Ano: R$ " << totalVendas << "\n";
                cout << "Media Mensal de Vendas: R$ " << mediaMensal << "\n";
                break;
            }
            case 5: {
                // --- Área do Gerente (SENHA com WHILE) ---
                cout << "\n--- 5. Area do Gerente ---\n";
                
                // Chama a função (Requisito 9)
                bool acessoConcedido = realizarLogin(senhaGerente);

                if (acessoConcedido) {
                    cout << "\n*** ACESSO CONCEDIDO ***\n";
                    cout << "Area restrita para acoes administrativas.\n";
                    // (Aqui poderiam entrar opções exclusivas do gerente)
                } else {
                    cout << "\n*** ACESSO BLOQUEADO ***\n";
                    cout << "Numero maximo de tentativas atingido.\n";
                }
                break;
            }
            case 6: {
                // --- Análise de Desempenho (RAIZ e DIVISÃO) ---
                cout << "\n--- 6. Analise de Desempenho ---\n";
                if (nomesProdutos.empty()) {
                    cout << "Nenhum produto cadastrado para analisar.\n";
                    break;
                }

                // --- Cálculo com RAIZ (Requisito 2) ---
                int totalItensEstoque = 0;
                for (int qtd : quantidadesEstoque) {
                    totalItensEstoque += qtd;
                }
                
                // Cálculo de exemplo: Raiz quadrada do total de itens
                if (totalItensEstoque > 0) {
                    double indiceDesempenho = sqrt(static_cast<double>(totalItensEstoque));
                    cout << "Total de itens no estoque: " << totalItensEstoque << "\n";
                    cout << "Indice de Desempenho (Raiz do Total): " << indiceDesempenho << "\n";
                } else {
                    cout << "Estoque zerado, indice de desempenho: 0\n";
                }


                // --- Verificação de DIVISÃO com resto zero (Requisito 3) ---
                cout << "\n--- Verificacao de Lotes ---\n";
                int tamanhoLote;
                cout << "Digite o tamanho do lote economico para verificacao: ";
                cin >> tamanhoLote;

                if (tamanhoLote <= 0) {
                    cout << "Tamanho do lote deve ser positivo.\n";
                    break;
                }

                cout << "Produtos com estoque perfeitamente divisivel por " << tamanhoLote << ":\n";
                bool encontrou = false;
                for (int i = 0; i < nomesProdutos.size(); ++i) {
                    // Verificação de divisão com resto zero
                    if (quantidadesEstoque[i] > 0 && (quantidadesEstoque[i] % tamanhoLote == 0)) {
                        cout << "- " << nomesProdutos[i] << " (Estoque: " << quantidadesEstoque[i] << ")\n";
                        encontrou = true;
                    }
                }

                if (!encontrou) {
                    cout << "Nenhum produto encontrado com estoque divisivel por " << tamanhoLote << ".\n";
                }
                break;
            }
            case 0:
                cout << "\nSaindo do sistema. Ate logo!\n";
                break;
            default:
                cout << "\nOpcao invalida. Tente novamente.\n";
                break;
        }

        // Pausa rápida para o usuário ler a saída antes do menu recarregar
        if (opcao != 0) {
            cout << "\nPressione Enter para continuar...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpa buffer caso haja algo
            cin.get(); // Espera o Enter
        }

    } while (opcao != 0); // Fim do DO-WHILE

    return 0; // Fim do programa
}

// --- Implementação das Funções (Requisito 9) ---

/**
 * Requisito 4: Controle de SENHA com WHILE (máximo 3 tentativas)
 */
bool realizarLogin(string senhaCorreta) {
    string senhaDigitada;
    int tentativas = 0;
    const int MAX_TENTATIVAS = 3;

    // Loop WHILE para controlar as tentativas
    while (tentativas < MAX_TENTATIVAS) {
        cout << "Digite a senha do gerente (Tentativa " << (tentativas + 1) << " de " << MAX_TENTATIVAS << "): ";
        
        // Limpa o buffer antes de ler a senha
        if(tentativas > 0 || cin.peek() == '\n') {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        getline(cin, senhaDigitada);

        if (senhaDigitada == senhaCorreta) {
            return true; // Sucesso
        } else {
            cout << "Senha incorreta.\n";
            tentativas++; // Incrementa a tentativa
        }
    }

    // Se saiu do loop, atingiu o máximo de tentativas
    return false; // Falha
}

/**
 * Requisito 2: Cálculos usando POTÊNCIA
 */
double calcularPrecoVenda(double custo, double margem, double fator) {
    if (custo < 0) custo = 0;
    
    // Calcula o multiplicador da margem (ex: 30% -> 1.30)
    double multiplicador = 1.0 + (margem / 100.0);

    // Usa pow() para aplicar o fator
    // precoVenda = custo * (1 + margem/100)^fator
    double precoVenda = custo * pow(multiplicador, fator);

    return precoVenda;
}