#ifndef structures_h
#define structures_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define tam 250

struct exemplares {
  int codigo;
  char titulo[100];
  char autor[41];
  char area[7];
  struct exemplares* prox;
};

typedef struct exemplares Acervo;
typedef Acervo* Hash[tam];

int funcao_Esp(int codigo, int tentativa);
Acervo* insere_Esp(Hash tab, int codigo, char* titulo, char* autor, char* area);
void remove_Esp(Hash tab, int codigo);
Acervo* busca_Esp(Hash tab, int codigo);
void listarExemplares(Hash tab);

#endif