#include "structures.h"

int funcao_Esp(int codigo){
  return (codigo % tam);
}

Acervo* insere_Esp(Hash tab, int codigo, char* titulo, char* autor, char* area){
  int h = funcao_Esp(codigo);
  
  Acervo* novo =(Acervo*)malloc(sizeof(Acervo));
  novo->codigo = codigo;
  strcpy(novo->titulo, titulo);
  strcpy(novo->autor, autor);
  strcpy(novo->area, area);
  novo->prox = NULL;

  if(tab[h] == NULL){
    tab[h] = novo;
  } else {
    Acervo* atual = tab[h];
    while(atual->prox != NULL){
      atual = atual->prox;  
    }
    atual->prox = novo;
  }
  return novo;
  
}

void remove_Esp(Hash tab, int codigo){
  int h = funcao_Esp(codigo);

  Acervo* atual = tab[h];
  Acervo* anterior = NULL;

  while(atual != NULL && atual->codigo != codigo){
    anterior = atual;
    atual = atual->prox;
  }

  if(atual != NULL){
    if (anterior == NULL){
      tab[h] = atual->prox; 
    }
  }
}