#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_TABELA 100

// Definição da estrutura de um nó da lista encadeada
struct No {
    char *chave;
    int valor;
    struct No *prox;
};

// Definição da estrutura da tabela hash
struct TabelaHash {
    struct No *vetor[TAMANHO_TABELA];
};

// Função de hash simples
int hash(char *chave) {
    int hash = 0;
    for (int i = 0; chave[i] != '\0'; i++) {
        hash += chave[i];
    }
    return hash % TAMANHO_TABELA;
}

// Função para criar um novo nó
struct No *criarNo(char *chave, int valor) {
    struct No *novoNo = malloc(sizeof(struct No));
    if (novoNo != NULL) {
        novoNo->chave = strdup(chave);
        novoNo->valor = valor;
        novoNo->prox = NULL;
    }
    return novoNo;
}

// Função para adicionar um par chave-valor na tabela hash
void adicionar(struct TabelaHash *tabela, char *chave, int valor) {
    int indice = hash(chave);
    struct No *novoNo = criarNo(chave, valor);
    if (novoNo != NULL) {
        novoNo->prox = tabela->vetor[indice];
        tabela->vetor[indice] = novoNo;
    }
}

// Função para obter o valor associado a uma chave
int obter(struct TabelaHash *tabela, char *chave) {
    int indice = hash(chave);
    struct No *atual = tabela->vetor[indice];
    while (atual != NULL) {
        if (strcmp(atual->chave, chave) == 0) {
            return atual->valor;
        }
        atual = atual->prox;
    }
    return -1; // Chave não encontrada
}

// Função para liberar a memória alocada para a tabela hash
void liberarTabela(struct TabelaHash *tabela) {
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        struct No *atual = tabela->vetor[i];
        while (atual != NULL) {
            struct No *temp = atual;
            atual = atual->prox;
            free(temp->chave);
            free(temp);
        }
    }
}

// Função principal
int main() {
    struct TabelaHash tabela;
    // Inicializa todas as entradas da tabela como NULL
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        tabela.vetor[i] = NULL;
    }

    // Exemplo de uso da tabela hash
    adicionar(&tabela, "chave1", 10);
    adicionar(&tabela, "chave2", 20);
    adicionar(&tabela, "chave3", 30);

    printf("Valor associado à chave1: %d\n", obter(&tabela, "chave1"));
    printf("Valor associado à chave2: %d\n", obter(&tabela, "chave2"));
    printf("Valor associado à chave3: %d\n", obter(&tabela, "chave3"));

    liberarTabela(&tabela);

    return 0;
}
