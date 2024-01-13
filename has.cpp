#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

// Estrutura para armazenar os itens a serem inseridos na tabela

/**
 * @brief Estrutura para armazenar os itens a serem inseridos na tabela hash
 * @param chave : chave de identifcação do item na tabela
 * @param dado : informação guardada pelo item na tabela hash
 */
struct Item {
    int chave;
    string dado;
};

//A tabela pode ser representada por meio de um struct
//No entanto, 

/**
 * @brief Classe que representa a estrutura de dados Tabela hash
 * @param Item
 */
class Tabela_Hash {
    
    private:
        
        vector<vector<Item*>> tabela; // Vetor de listas de ponteiros para Item
        int tamanho_tabela;

        // Função de hash simples
        int hash(int chave) {
            return static_cast<int>(chave % tamanho_tabela);
        }

    public:
        
        Tabela_Hash(int tamanho) {
            tamanho_tabela = tamanho;
            tabela.resize(tamanho);
        }

        // Função para inserir um elemento na tabela
        void inserir_tabela(double chave, const string& dado) {
            int index = hash(chave);
            for (Item* entry : tabela[index]) {
                if (entry->chave == chave) {
                    cout << "Chave duplicada. Não é possível inserir." << endl;
                    return;
                }
            }
            Item* novoDado = new Item;
            novoDado->chave = chave;
            novoDado->dado = dado;
            tabela[index].push_back(novoDado);
        }

        // Função para buscar um elemento na tabela pelo valor da chave
        void busca_chave(double chave) {
            int index = hash(chave);
            for (Item* entry : tabela[index]) {
                if (entry->chave == chave) {
                    cout << "Chave: " << entry->chave << ", Dados: " << entry->dado << endl;
                    return;
                }
            }
            cout << "Chave não encontrada." << endl;
        }

        // Função para buscar elementos na tabela pelo valor dos dados
        void busca_dado(const string& dado) {
            for (const vector<Item*>& i : tabela) {
                for (Item* entry : i) {
                    if (entry->dado == dado) {
                        cout << "Chave: " << entry->chave << ", Dados: " << entry->dado << endl;
                    }
                }
            }
        }

        // Função para remover um elemento da tabela pelo valor da chave
        void remove_chave(double chave) {
            int index = hash(chave);
            for (auto it = tabela[index].begin(); it != tabela[index].end(); ++it) {
                if ((*it)->chave == chave) {
                    delete *it; // Liberar a memória alocada para a entrada
                    tabela[index].erase(it);
                    cout << "Chave removida." << endl;
                    return;
                }
            }
            cout << "Chave não encontrada." << endl;
        }

        // Função para remover elementos da tabela pelo valor dos dados
        void remove_dado(const string& dado) {
            for (auto& i : tabela) {
                for (auto it = i.begin(); it != i.end(); ) {
                    if ((*it)->dado == dado) {
                        delete *it; // Liberar a memória alocada para a entrada
                        it = i.erase(it);
                    } else {
                        ++it;
                    }
                }
            }
            cout << "Chaves removidas." << endl;
        }

        // Função para mostrar todos os elementos da tabela
        void print_tabela() {
            for (int i = 0; i < tamanho_tabela; ++i) {
                cout << "Item " << i << ": ";
                for (Item* entry : tabela[i]) {
                    cout << "Chave: " << entry->chave << ", Dado: " << entry->dado << " | ";
                }
                cout << endl;
            }
        }

        // Destrutor para liberar a memória alocada
        ~Tabela_Hash() {
            for (int i = 0; i < tamanho_tabela; ++i) {
                for (Item* entry : tabela[i]) {
                    delete entry;
                }
            }
        }
};

int main() {
    Tabela_Hash tabela(10); // Tamanho da tabela: 100000

    tabela.inserir_tabela(1, "password");
    tabela.inserir_tabela(2, "senha1234");
    tabela.inserir_tabela(3, "naotemsenha");

 
    tabela.print_tabela();

    return 0;
}
