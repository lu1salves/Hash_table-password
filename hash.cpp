#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cstdlib> 

using namespace std;

/**
 * A variável global foi escolhida por pura convenção de organização do código.
 * No entanto, como ela fica na stack, sua memória fica alocada durante todo a execução do programa
 * Para melhor otimizar esse programa, se você preferir, pode inserir essa variável de texto dentro da função main, antes da funcao showmenu()
 */
string s = R"(
## Documentação da Classe `Tabela_Hash`

### Descrição
A classe `Tabela_Hash` implementa uma tabela hash que permite armazenar e gerenciar pares chave-valor. Ela utiliza uma técnica de resolução de colisões por meio de listas encadeadas. A classe fornece métodos para inserir, buscar, remover e listar elementos na tabela, bem como para avaliar seu desempenho.

### Métodos Públicos

#### `Tabela_Hash(int tamanho)`
- **Descrição**: Construtor da classe `Tabela_Hash`.
- **Parâmetros**:
  - `tamanho` (int): O tamanho desejado da tabela hash.
- **Comportamento**: Inicializa a tabela hash com o tamanho especificado e configura os atributos internos.

#### `void inserir_tabela(double chave, const string &dado)`
- **Descrição**: Insere um elemento na tabela com a chave e o dado especificados.
- **Parâmetros**:
  - `chave` (double): A chave do elemento a ser inserido.
  - `dado` (const string&): O dado a ser armazenado.
- **Comportamento**: Calcula o índice da tabela com base na chave, verifica se a chave já existe na lista correspondente e, se não, insere o novo elemento. Lida com colisões e fornece feedback visual.

#### `void busca_chave(double chave)`
- **Descrição**: Busca um elemento na tabela pelo valor da chave e imprime o resultado.
- **Parâmetros**:
  - `chave` (double): A chave do elemento a ser buscado.
- **Comportamento**: Calcula o índice da tabela com base na chave e busca o elemento correspondente. Exibe os resultados na saída padrão.

#### `void busca_dado(const string &dado)`
- **Descrição**: Busca elementos na tabela pelo valor dos dados e imprime os resultados.
- **Parâmetros**:
  - `dado` (const string&): O dado a ser buscado.
- **Comportamento**: Percorre toda a tabela e suas listas para encontrar elementos com o dado especificado e exibi-los na saída padrão.

#### `void remove_chave(double chave)`
- **Descrição**: Remove um elemento da tabela pelo valor da chave.
- **Parâmetros**:
  - `chave` (double): A chave do elemento a ser removido.
- **Comportamento**: Calcula o índice da tabela com base na chave e remove o elemento correspondente, liberando a memória alocada. Lida com situações em que a chave não é encontrada.

#### `void remove_dado(const string &dado)`
- **Descrição**: Remove elementos da tabela pelo valor dos dados.
- **Parâmetros**:
  - `dado` (const string&): O dado a ser removido.
- **Comportamento**: Percorre toda a tabela e suas listas para encontrar elementos com o dado especificado e remove-os, liberando a memória alocada.

#### `void print_tabela()`
- **Descrição**: Exibe todos os elementos da tabela na saída padrão.
- **Comportamento**: Percorre toda a tabela e suas listas, exibindo as chaves e dados dos elementos.

#### `void mostrar_desempenho()`
- **Descrição**: Exibe informações sobre o desempenho da tabela hash, incluindo o número total de elementos, o número de listas não vazias, o fator de carga e o número de colisões.
- **Comportamento**: Calcula as métricas de desempenho com base no estado atual da tabela e exibe os resultados na saída padrão.

#### `~Tabela_Hash()`
- **Descrição**: Destrutor para liberar a memória alocada.
- **Comportamento**: Libera a memória alocada para os elementos da tabela hash ao destruir a instância da classe.

### Atributos Privados

- `vector<vector<Item *>> tabela`: Vetor de listas de ponteiros para objetos do tipo `Item`, que armazenam os elementos da tabela hash.
- `int tamanho_tabela`: O tamanho da tabela hash.
- `int colisoes`: O contador de colisões.

### Função Privada

- `int hash(int chave)`: Função de hash simples que calcula o índice da tabela com base na chave fornecida.

)";

/**
 * @brief Estrutura para armazenar os itens a serem inseridos na tabela hash
 * @param chave : chave de identificação do item na tabela
 * @param dado : informação guardada pelo item na tabela hash
 */
struct Item{
    int chave;
    string dado;
};

/**
 * @brief Classe que representa a estrutura de dados Tabela hash
 * @param Item
 */
class Tabela_Hash{

    private:
        vector<vector<Item *>> tabela; // Vetor de listas de ponteiros para Item
        int tamanho_tabela;
        int colisoes; // Contador de colisões

        // Função de hash simples
        int hash(int chave){
            return static_cast<int>(chave % tamanho_tabela);
        }

    public:

        /**
         * @brief Construtor da classe Tabela_Hash
         * @param tamanho : tamanho da tabela hash
         */
        Tabela_Hash(int tamanho){
            tamanho_tabela = tamanho;
            tabela.resize(tamanho);
            colisoes = 0; // Inicializa o contador de colisões
        }

        /**
         * @brief Função para inserir um elemento na tabela
         * @param chave : chave do elemento a ser inserido
         * @param dado : dado a ser armazenado
         */
        void inserir_tabela(double chave, const string &dado){
            int index = hash(chave);
            for (Item *entry : tabela[index]){
                if (entry->chave == chave)
                {
                    std::cout << "\033[1;31m";
                    cout << "Chave duplicada. Nao e possivel inserir." << endl;
                    std::cout << "\033[0m";
                    return;
                }
                colisoes++; // Incrementa o contador de colisões
            }
            Item *novoDado = new Item;
            novoDado->chave = chave;
            novoDado->dado = dado;
            tabela[index].push_back(novoDado);
            std::cout << "\033[1;32m";
            cout << "Chave inserida com sucesso" << endl;
            std::cout << "\033[0m";
        }

        /**
         * @brief Função para buscar um elemento na tabela pelo valor da chave
         * @param chave : chave do elemento a ser buscado
         */
        void busca_chave(double chave){
            int index = hash(chave);
            for (Item *entry : tabela[index]){
                if (entry->chave == chave){
                    cout << "Chave: " << entry->chave << ", Dados: " << entry->dado << endl;
                    return;
                }
            }
            std::cout << "\033[1;31m";
            cout << "Chave nao encontrada." << endl;
            std::cout << "\033[0m";
        }

        /**
         * @brief Função para buscar elementos na tabela pelo valor dos dados
         * @param dado : dado a ser buscado
         */
        void busca_dado(const string &dado){
            for (const vector<Item *> &i : tabela){
                for (Item *entry : i){
                    if (entry->dado == dado){
                        cout << "Chave: " << entry->chave << ", Dados: " << entry->dado << endl;
                    }
                }
            }
        }

        /**
         * @brief Função para remover um elemento da tabela pelo valor da chave
         * @param chave : chave do elemento a ser removido
         */
        void remove_chave(double chave){
            int index = hash(chave);
            for (auto it = tabela[index].begin(); it != tabela[index].end(); ++it){
                if ((*it)->chave == chave){
                    delete *it; // Liberar a memória alocada para a entrada
                    tabela[index].erase(it);
                    cout << "Chave removida." << endl;
                    return;
                }
            }
            std::cout << "\033[1;31m";
            cout << "Chave nao encontrada." << endl;
            std::cout << "\033[0m";
        }

        /**
         * @brief Função para remover elementos da tabela pelo valor dos dados
         * @param dado : dado a ser removido
         */
        void remove_dado(const string &dado){
            for (auto &i : tabela){
                for (auto it = i.begin(); it != i.end();){
                    if ((*it)->dado == dado){
                        delete *it; // Liberar a memória alocada para a entrada
                        it = i.erase(it);
                    }
                    else{
                        ++it;
                    }
                }
            }
            cout << "Chaves removidas." << endl;
        }

        /**
         * @brief Função para mostrar todos os elementos da tabela
         */
        void print_tabela(){
            for (int i = 0; i < tamanho_tabela; ++i){
                cout << "Item " << i << ": ";
                for (Item *entry : tabela[i]){
                    cout << "Chave: " << entry->chave << ", Dado: " << entry->dado << " | ";
                }
                cout << endl;
            }
        }

        /**
         * @brief Função para mostrar informações sobre o desempenho da tabela hash
         */
        void mostrar_desempenho(){
            int total_elementos = 0;
            int total_listas_nao_vazias = 0;

            for (const auto &lista : tabela){
                if (!lista.empty()){
                    total_elementos += lista.size();
                    total_listas_nao_vazias++;
                }
            }

            double fator_carga = static_cast<double>(total_elementos) / tamanho_tabela;

            std::cout << "\n=== Informacoes de Desempenho ===" << std::endl;
            std::cout << "Total de Elementos: " << total_elementos << std::endl;
            std::cout << "Numero de Listas Nao Vazias: " << total_listas_nao_vazias << std::endl;
            std::cout << "Fator de Carga: " << fator_carga << std::endl;
            std::cout << "Numero de Colisoes: " << colisoes << std::endl;
        }

        /**
         * @brief Destrutor para liberar a memória alocada
         * Em orientação a objetos, o destrutor funciona como um free da linguagem C
         */
        ~Tabela_Hash(){
            for (int i = 0; i < tamanho_tabela; ++i){
                for (Item *entry : tabela[i]){
                    delete entry;
                }
            }
        }
};

/**
 * @brief Função para exibir o menu de opções
 */
void showMenu(){
    std::cout << "\033[1;35m";
    cout << "Menu:" << endl;
    
    cout << "1. Funções da tabela hash" << endl; //criar tabela hash para poder colocar um N pre-setado

    cout << "2. Informacoes de desempenho (para desenvolvedores malucos)" << endl; // Nova opção
    
    cout<< "3 .help (documentação)" <<endl;
    
    cout << "4. Sair" << endl;

    cout << "Escolha uma opcao: ";
    
    std::cout << "\033[0m";

}

/**
 * @brief Função para limpar a tela do console
 * Se o sistema for windows, executa cls no terminal
 * Caso seja linux, executa clear no terminal
 */
void clearScreen(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int main(){

    Tabela_Hash tabela(10); // Tamanho da tabela: 10

    int opcao;
    double chave;
    string dado;

    do{
        std::cout << "\033[1;34m";
        clearScreen();
        showMenu();
        cin >> opcao;

        switch (opcao){

            case 1:
                cout << "A tabela hash tem as seguintes operações: " << endl;
                cout << "1. Inserir elemento" << endl;
                cout << "2. Buscar elemento por chave" << endl;
                cout << "3. Buscar elementos por dado" << endl;
                cout << "4. Remover elemento por chave" << endl;
                cout << "5. Remover elementos por dado" << endl;
                cout << "6. Mostrar tabela" << endl;
                cout << "7. voltar para a tela anterior" << endl;
                
                int escolha;
                cout<<"Digite a operação que você gostaria de realizar: ";
                cin>>escolha;

                switch (escolha){

                    case 1:
                        cout << "Digite a chave: ";
                        cin >> chave;
                        cout << "Digite o dado: ";
                        cin >> dado;
                        tabela.inserir_tabela(chave, dado);
                        break;

                    case 2:
                        cout << "Digite a chave: ";
                        cin >> chave;
                        tabela.busca_chave(chave);
                        break;

                    case 3:
                        cout << "Digite o dado: ";
                        cin >> dado;
                        tabela.busca_dado(dado);
                        break;

                    case 4:
                        cout << "Digite a chave: ";
                        cin >> chave;
                        tabela.remove_chave(chave);
                        break;

                    case 5:
                        cout << "Digite o dado: ";
                        cin >> dado;
                        tabela.remove_dado(dado);
                        break;

                    case 6:
                        tabela.print_tabela();
                        break;

                    case 7:

                    default:
                        cout << "Opção inválida. Tente novamente." << endl;
                        break;

                }

            case 2:
                tabela.mostrar_desempenho();
                break; // Adicionado caso para mostrar informações de desempenho
            
            case 3:
                
                std::cout << s << std::endl;

            case 4:
                cout << "Saindo..." << endl;
                break;

            default:
                cout << "Opção inválida. Tente novamente." << endl;
                break;
        }
 
        std::cout << "\033[0m";
        
        if (opcao != 4){
            std::cout << "\033[1;33m";
            cout << "Pressione qualquer tecla para continuar...";
            cin.ignore();
            cin.get();
        }

    } while (opcao != 4);

    return 0;
}