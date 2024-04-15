#ifndef index.h
#define index.h

struct No {
 char *chave;
 int valor;
 struct No *prox;
};

struct Hash {
 struct No *vetor[TMP_MAX];
};

int hash (char *chave);
struct No *criarNo(char *chave, int valor);
void adicionar(struct Hash *tabela, char *chave, int valor);
int obter(struct Hash *tabela, char *chave);

#endif
