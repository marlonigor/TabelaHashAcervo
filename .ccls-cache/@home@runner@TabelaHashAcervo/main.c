#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "structures.h"

int main(void) {
  
  setlocale(LC_ALL, "Portuguese");
  Hash tabela;
  int i;
  for(i = 0; i < tam; i++){
    tabela[i] = NULL;
  }

  int opcao;
  int codigo;
  char titulo[100];
  char autor[41];
  char area[7];

  do{
    printf("\nMenu:\n");
    printf("1 - Inserir exemplar\n");
    printf("2 - Remover exemplar\n");
    printf("3 - Buscar exemplar\n");
    printf("4 - Listar exemplar\n");
    printf("0 - Sair\n");
    printf("Escolha uma opção: \n");
    scanf("%d", &opcao);

    switch(opcao){
      case 1:
        printf("Informe o código do exemplar:");
        scanf("%d", &codigo);
      
        printf("Informe o título:");
        fgets(titulo, sizeof(titulo), stdin);
        while(getchar()!='\n');

        printf("Informe o autor:");
        fgets(autor, 41, stdin);
        autor[strcspn(autor, "\n")] = '\0';

        printf("Informe o área:");
        fgets(area, 7, stdin);

        insere_Esp(tabela, codigo, titulo, autor, area);
        
      break;
      case 2:
        printf("Informe o código do exemplar a ser removido: ");
        scanf("%d", &codigo);
        remove_Esp(tabela, codigo);
      break;
      case 3:
        printf("Informe o código do exemplar a ser buscado: ");
        scanf("%d", &codigo);
        Acervo* encontrado = busca_Esp(tabela, codigo);
        if(encontrado != NULL){
          printf("Exemplar encontrado: \n");
        printf("Código: %d, Título: %s, Autor: %s, Área: %s\n", encontrado->codigo, encontrado->titulo, encontrado->autor, encontrado->area);
        }else{
          printf("Exemplar não encontrado!\n");
        }
      break;
      case 4:
        listarExemplares(tabela);
        break;
      case 0:
        break;
      default:
        printf("Opção inválida!\n");
    }
  }while(opcao != 0);
  
  return 0;
}