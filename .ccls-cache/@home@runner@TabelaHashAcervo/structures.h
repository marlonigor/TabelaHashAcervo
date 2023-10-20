#ifdef structures_h
#define structures_h

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

#endif