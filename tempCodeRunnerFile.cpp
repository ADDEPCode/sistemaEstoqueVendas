            cout << "\n--- Simulacao de Vendas Baseada no Estoque ---\n";

                if (nomesProdutos.empty()) {
                    cout << "Nenhum produto cadastrado.\n";
                    break;
                }

                double totalAnual = 0.0;

                for (int mes = 1; mes <= 12; ++mes) {
                    cout << "\nMes " << mes << ":\n";

                    double totalMes = 0.0;

                    for (int i = 0; i < nomesProdutos.size(); i++) {

                        if (quantidadesEstoque[i] == 0) {
                            cout << " - " << nomesProdutos[i]
                                << ": vendeu 0 unidades → R$ 0,00\n";
                            continue;
                        }

                        int maxVendas = quantidadesEstoque[i];
                        int vendidos = rand() % (maxVendas + 1);

                        double faturamento = vendidos * precosCusto[i];

                        quantidadesEstoque[i] -= vendidos;

                        totalMes += faturamento;

                        cout << " - " << nomesProdutos[i]
                            << ": vendeu " << vendidos
                            << " unidades → R$ "
                            << fixed << setprecision(2)
                            << faturamento << "\n";
                    }

                    cout << "Total do mes: R$ "
                        << fixed << setprecision(2) 
                        << totalMes << "\n";

                    totalAnual += totalMes;
                }

                cout << "\n=== RESUMO ANUAL ===\n";
                cout << "Total anual: R$ " 
                    << fixed << setprecision(2) 
                    << totalAnual << "\n";
                cout << "Media mensal: R$ " 
                    << fixed << setprecision(2) 
                    << totalAnual / 12.0 << "\n";

                break;
            }