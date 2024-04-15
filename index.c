#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "index.h"

#define TAM 10;

int hash (char *chave) { //função de hash simples
    int hash = 0;
    for(int i = 0; chave[i] != '\0'; i++) {
        hash += chave[i];
    }
    return hash % TAM;
}

struct No *criarNo(char *chave, int valor) {
    struct No *novo = malloc(sizeof(No));

    if(novo != NULL) {
        novo->chave = strdup(chave);
        novo->valor = valor;
        novo->prox = NULL;
    }
    return novo;
}

void adicionar(struct Hash *tabela, char *chave, int valor) {
    int indice = hash(chave);
    struct No *novo = criarNo(chave, valor);

    if(novo != NULL) {
        novo->prox = tabela->vetor[indice];
        tabela->vetor[indice] = novo;
    }
}

int obter(struct Hash *tabela, char *chave) {
    int indice = hash(chave);
    struct No *atual = tabela->vetor[indice];

    while(atual != NULL) {
        if(strcmp(atual->chave, chave) == 0) {
            return atual->valor;
        }
        atual = atual->prox;
    }
    return -1;
}

void liberar(struct Hash *tabela) {
    for (int i = 0; i < TAM; i++) {
        struct No *atual = tabela->vetor[i];

        while (atual != NULL) {
            atual = atual->prox;
            free(temp->chave);
            free(temp);
        }
    }
}

int main () {
    struct Hash tabela {
        for(int i = 0; i < TAM; i++){
            tabela.vetor[i] = NULL;
        }
    }

    adicionar(&tabela, "chave-1", 10);
    adicionar(&tabela, "chave-2", 20);
    adicionar(&tabela, "chave-3", 30);

    printf("Valor associado à chave-1: %d\n", obter(&tabela, "chave-1"));
    printf("Valor associado à chave-2: %d\n", obter(&tabela, "chave-2"));
    printf("Valor associado à chave-3: %d\n", obter(&tabela, "chave-3"));

    liberar(&tabela);

    return 0;
}


