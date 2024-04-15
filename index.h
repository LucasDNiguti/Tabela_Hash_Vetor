#ifndef index.h
#define index.h

struct No {
 char *chave;
 int valor;
 struct No *prox;
};

struct Hash {
 struct No *vetor[Tam];
};

#endif
