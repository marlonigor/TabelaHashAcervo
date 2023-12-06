Acervo* insere_Esp(Hash tab, int codigo, char* titulo) {
  int tentativa = 0;
  int h;

  do {
    h = funcao_Esp(codigo, tentativa);

    if (tab[h] == NULL) {
      Acervo* novo = (Acervo*)malloc(sizeof(Acervo));
      novo->codigo = codigo;
      strcpy(novo->titulo, titulo);
      novo->prox = NULL;
      tab[h] = novo;
      return novo;
    }

    tentativa++;
  } while (tentativa < tableSize); 
  return NULL;
}