#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct no{
  int dado;
  struct no *prox;
}No;

No *topo = NULL;

void push(int n){
  No *novo = malloc(sizeof(No));
  if(novo){
    novo->dado = n;
    novo->prox = topo;
    topo = novo;
  }else{
    printf("Erro ao alocar memória\n");
  }
}

void pop(){
  if(topo == NULL){
    printf("\nA pilha está vazia\n");
  }else{
    No *aux = topo;
    topo = topo->prox;
    printf("Desempilhado: %d\n", aux->dado);
    free(aux);
  }
}

void print(){
  No *aux = topo;
  if(aux == NULL){
    printf("\nA pilha está vazia\n");
  }else{
    printf("\n---PILHA---\n");
    while(aux != NULL){
      printf("%d\n", aux->dado);
      aux = aux->prox;
    }
  }
}

int main(void) {
  int opcao, empilhar;
  do{
    printf("\n0 - sair\n1 - empilhar\n2 - desempilhar\n3 - imprimir\n");
    scanf("%d", &opcao);
    getchar();

    switch(opcao){
      case 1:
        printf("Digite um valor:");
        scanf("%d", &empilhar);
        push(empilhar);
        break;
      case 2:
        pop();
        break;
      case 3:
          print();
        break;
      default:
        if(opcao != 0)
          printf("\nOpcao invalida!\n");
    }
  }while(opcao != 0);

  return 0;
}