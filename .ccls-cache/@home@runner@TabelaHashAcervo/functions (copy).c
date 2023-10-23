#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "structures.h"

int tam = 100; // Tamanho inicial da tabela hash

typedef struct Acervo {
  int codigo;
  char titulo[100];
  char autor[100];
  char area[100];
  struct Acervo* prox; // Próximo elemento em caso de colisão
} Acervo;

Acervo* tabela[tam]; // Tabela hash

int funcao_Esp(int codigo, int tentativa) {
  return (codigo + tentativa) % tam;
}

Acervo* insere_Esp(int codigo, char* titulo, char* autor, char* area) {
  int tentativa = 0;
  int h;
  
  do {
    h = funcao_Esp(codigo, tentativa);

    if (tabela[h] == NULL) {
      Acervo* novo = (Acervo*)malloc(sizeof(Acervo));
      novo->codigo = codigo;
      strcpy(novo->titulo, titulo);
      strcpy(novo->autor, autor);
      strcpy(novo->area, area);
      novo->prox = NULL;
      tabela[h] = novo;
      return novo;
    }

    tentativa++;
  } while (tentativa < tam); // Evitar loops infinitos em caso de tabela cheia

  // Se a tabela estiver cheia, você pode considerar redimensioná-la
  // ou implementar uma estratégia de tratamento de colisões diferente
  return NULL;
}

Acervo* busca_Esp(int codigo) {
  int tentativa = 0;
  int h;

  // Procurar o elemento usando o espalhamento aberto
  do {
    h = funcao_Esp(codigo, tentativa);

    if (tabela[h] != NULL && tabela[h]->codigo == codigo) {
      return tabela[h];
    }

    tentativa++;
  } while (tentativa < tam);

  return NULL;
}

void remove_Esp(int codigo) {
  int tentativa = 0;
  int h;

  // Procurar e remover o elemento usando o espalhamento aberto
  do {
    h = funcao_Esp(codigo, tentativa);

    if (tabela[h] != NULL && tabela[h]->codigo == codigo) {
      free(tabela[h]);
      tabela[h] = NULL;
      return;
    }

    tentativa++;
  } while (tentativa < tam);
}

// Restante do código...
