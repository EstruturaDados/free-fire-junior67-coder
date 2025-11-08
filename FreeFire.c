
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da struct para o Item do Inventário
//----------------------------------------------------------------------------------
typedef struct {
    char nome[50];
    char tipo[50];
    int quantidade;
    int ativo; // Flag para indicar se o slot está sendo usado (1) ou livre (0)
} Item;
//----------------------------------------------------------------------------------

// Constante para o tamanho máximo do inventário
#define MAX_ITENS 10

// Variável global (para simplicidade no Nível Novato) para rastrear o inventário
Item inventario[MAX_ITENS];
int total_itens_ativos = 0;

// --- Funcoes Auxiliares ---

// Limpa o buffer de entrada (necessário apos scanf antes de fgets)
void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

// Funcao para listar todos os itens do inventario
void listar_itens() {
    printf("\n=======================================================\n");
    printf("                  INVENTARIO ATUAL (Max: %d)\n", MAX_ITENS);
    printf("=======================================================\n");
    printf("| %-4s | %-20s | %-15s | %-10s |\n", "ID", "Nome", "Tipo", "Quantidade");
    printf("|------|----------------------|-----------------|------------|\n");
    
    int encontrado = 0;
    for (int i = 0; i < MAX_ITENS; i++) {
        if (inventario[i].ativo) {
            printf("| %-4d | %-20s | %-15s | %-10d |\n", 
                   i, 
                   inventario[i].nome, 
                   inventario[i].tipo, 
                   inventario[i].quantidade);
            encontrado = 1;
        }
    }
    
    if (!encontrado) {
        printf("| Nao ha itens no inventario.                                 |\n");
    }
    printf("=======================================================\n");
}

// Funcao para adicionar itens a mochila
void adicionar_item() {
    if (total_itens_ativos >= MAX_ITENS) {
        printf("\n[ERRO] O inventario esta cheio! Nao e possivel adicionar mais itens.\n");
        return;
    }

    // Encontra o primeiro slot livre (ativo == 0)
    int i;
    for (i = 0; i < MAX_ITENS; i++) {
        if (!inventario[i].ativo) {
            break; 
        }
    }

    limpar_buffer();
    
    printf("\n--- Adicionar Novo Item ---\n");
    
    // Leitura do Nome
    printf("Nome do Item: ");
    if (fgets(inventario[i].nome, sizeof(inventario[i].nome), stdin) == NULL) return; 
    inventario[i].nome[strcspn(inventario[i].nome, "\n")] = 0; 

    // Leitura do Tipo
    printf("Tipo do Item (ex: Comida, Arma, Remedio): ");
    if (fgets(inventario[i].tipo, sizeof(inventario[i].tipo), stdin) == NULL) return;
    inventario[i].tipo[strcspn(inventario[i].tipo, "\n")] = 0;

    // Leitura da Quantidade
    printf("Quantidade: ");
    if (scanf("%d", &inventario[i].quantidade) != 1 || inventario[i].quantidade <= 0) {
         printf("[ERRO] Quantidade invalida. Item nao adicionado.\n");
         // Garante que o slot nao sera ativado
         inventario[i].ativo = 0; 
         return;
    }// Código da Ilha – Edição Free Fire
// Nível: Mestre
// Este programa simula o gerenciamento avançado de uma mochila com componentes coletados durante a fuga de uma ilha.
// Ele introduz ordenação com critérios e busca binária para otimizar a gestão dos recursos.

int main() {
    // Menu principal com opções:
    // 1. Adicionar um item
    // 2. Remover um item
    // 3. Listar todos os itens
    // 4. Ordenar os itens por critério (nome, tipo, prioridade)
    // 5. Realizar busca binária por nome
    // 0. Sair

    // A estrutura switch trata cada opção chamando a função correspondente.
    // A ordenação e busca binária exigem que os dados estejam bem organizados.

    return 0;
}

// Struct Item:
// Representa um componente com nome, tipo, quantidade e prioridade (1 a 5).
// A prioridade indica a importância do item na montagem do plano de fuga.

// Enum CriterioOrdenacao:
// Define os critérios possíveis para a ordenação dos itens (nome, tipo ou prioridade).

// Vetor mochila:
// Armazena até 10 itens coletados.
// Variáveis de controle: numItens (quantidade atual), comparacoes (análise de desempenho), ordenadaPorNome (para controle da busca binária).

// limparTela():
// Simula a limpeza da tela imprimindo várias linhas em branco.

// exibirMenu():
// Apresenta o menu principal ao jogador, com destaque para status da ordenação.

// inserirItem():
// Adiciona um novo componente à mochila se houver espaço.
// Solicita nome, tipo, quantidade e prioridade.
// Após inserir, marca a mochila como "não ordenada por nome".

// removerItem():
// Permite remover um componente da mochila pelo nome.
// Se encontrado, reorganiza o vetor para preencher a lacuna.

// listarItens():
// Exibe uma tabela formatada com todos os componentes presentes na mochila.

// menuDeOrdenacao():
// Permite ao jogador escolher como deseja ordenar os itens.
// Utiliza a função insertionSort() com o critério selecionado.
// Exibe a quantidade de comparações feitas (análise de desempenho).

// insertionSort():
// Implementação do algoritmo de ordenação por inserção.
// Funciona com diferentes critérios de ordenação:
// - Por nome (ordem alfabética)
// - Por tipo (ordem alfabética)
// - Por prioridade (da mais alta para a mais baixa)

// buscaBinariaPorNome():
// Realiza busca binária por nome, desde que a mochila esteja ordenada por nome.
// Se encontrar, exibe os dados do item buscado.
// Caso contrário, informa que não encontrou o item.
