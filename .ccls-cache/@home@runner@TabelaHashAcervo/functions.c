#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "structures.h"

int funcao_Esp(int codigo, int tentativa) {
  return (codigo + tentativa) % tam;
}

Acervo* insere_Esp(Hash tab, int codigo, char* titulo, char* autor, char* area) {
  int tentativa = 0;
  int h;

  do {
    h = funcao_Esp(codigo, tentativa);

    if (tab[h] == NULL) {
      Acervo* novo = (Acervo*)malloc(sizeof(Acervo));
      novo->codigo = codigo;
      strcpy(novo->titulo, titulo);
      strcpy(novo->autor, autor);
      strcpy(novo->area, area);
      novo->prox = NULL;
      tab[h] = novo;
      return novo;
    }

    tentativa++;
  } while (tentativa < tam); 
  return NULL;
}

void remove_Esp(Hash tab, int codigo) {
  int tentativa = 0;
  int h;

  do {
    h = funcao_Esp(codigo, tentativa);

    if (tab[h] != NULL && tab[h]->codigo == codigo) {
      free(tab[h]);
      tab[h] = NULL;
      return;
    }

    tentativa++;
  } while (tentativa < tam);
}

Acervo* busca_Esp(Hash tab, int codigo) {
  int tentativa = 0;
  int h;

  // Procurar o elemento usando o espalhamento aberto
  do {
    h = funcao_Esp(codigo, tentativa);

    if (tab[h] != NULL && tab[h]->codigo == codigo) {
      return tab[h];
    }

    tentativa++;
  } while (tentativa < tam);

  return NULL;
}

void listarExemplares(Hash tab){
  printf("\nExemplares no acervo:\n");
  for(int i = 0; i < tam; i++){
    Acervo* atual = tab[i];

    while(atual != NULL){
      printf("Codigo: %d \nTitulo: %s \nAutor: %s \nArea: %s", atual->codigo, atual->titulo, atual->autor, atual->area);
      atual = atual->prox;
    }
  }
  printf("\n");
}

