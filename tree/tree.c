#include "stdio.h"
#include "stdlib.h"


typedef struct no {
    int valor;
    struct no *direita, *esquerda;
}NoArv;

NoArv* inserir_versao_1(NoArv *raiz, int num){
    if(raiz == NULL){
        NoArv *aux = malloc(sizeof(NoArv));
        aux->valor = num;
        aux->esquerda = NULL;
        aux->direita = NULL;
        return aux;
    }else{
        if(num < raiz->valor){
            raiz->esquerda = inserir_versao_1(raiz->esquerda, num);
        }else{
            raiz->direita = inserir_versao_1(raiz->direita, num);
        }
        return raiz;
    }
}

void print_arvore(NoArv *raiz){
    if(raiz){
        printf("%d ", raiz->valor);
        print_arvore(raiz->esquerda);
        print_arvore(raiz->direita);
    }
}

void print_arvore_ordenada(NoArv *raiz){
    if(raiz){
        print_arvore_ordenada(raiz->esquerda);
        printf("%d ", raiz->valor);
        print_arvore_ordenada(raiz->direita);
    }
}

NoArv* buscar_arvore(NoArv *raiz, int num){
    if(raiz){
        if(num == raiz->valor){
            return raiz;
        }else if(num < raiz->valor){
            return buscar_arvore(raiz->esquerda, num);
        }else{
            return buscar_arvore(raiz->direita, num);
        }
    }
    return NULL;
}

int main(){

    NoArv *raiz = NULL;

    raiz = inserir_versao_1(raiz, 100);
    raiz = inserir_versao_1(raiz, 50);
    raiz = inserir_versao_1(raiz, 25);
    raiz = inserir_versao_1(raiz, 30);

    print_arvore(raiz);
    printf("\nImprimindo em ordem\n");
    print_arvore_ordenada(raiz);

    raiz = buscar_arvore(raiz, 50);

    printf("Buscando valor: %d ", raiz->valor);

    return 0;
}