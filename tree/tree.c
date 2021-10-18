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

int altura_arvore(NoArv *raiz){
    if(raiz == NULL){
        return -1;
    }else{
        int esq = altura_arvore(raiz->esquerda);
        int dir = altura_arvore(raiz->direita);

        if(esq > dir){
            return esq + 1;
        }else{
            return dir + 1;
        }
    }
}

int cont_no(NoArv *raiz){
    if (raiz == NULL){
        return 0;
    }else{
        return 1 + cont_no(raiz->esquerda) + cont_no(raiz->direita);
    }
}

int main(){

    NoArv *raiz = NULL;

    // raiz = inserir_versao_1(raiz, 100);
    // raiz = inserir_versao_1(raiz, 50);
    // raiz = inserir_versao_1(raiz, 25);
    // raiz = inserir_versao_1(raiz, 30);
    raiz = inserir_versao_1(raiz, 12);
    raiz = inserir_versao_1(raiz, 7);
    raiz = inserir_versao_1(raiz, 3);
    raiz = inserir_versao_1(raiz, 10);
    raiz = inserir_versao_1(raiz, 11);
    raiz = inserir_versao_1(raiz, 23);
    raiz = inserir_versao_1(raiz, 17);
    raiz = inserir_versao_1(raiz, 31);
    // raiz = inserir_versao_1(raiz, 1);


    print_arvore(raiz);
    printf("\nImprimindo em ordem\n");
    print_arvore_ordenada(raiz);
    printf("\n");

    printf("\nAltura da árvore: %d\n", altura_arvore(raiz));

    int valor_busca = 10;
    NoArv *raiz_busca = buscar_arvore(raiz, valor_busca);

    if(raiz_busca == NULL){
        printf("Valor %d não encontrado na árvore\n", valor_busca);
    }else{
        printf("Encontrou o valor: %d nesta árvore\n", raiz_busca->valor);
    }

    int quant = cont_no(raiz);

    if(raiz == NULL){
        printf("A árvore não possui nós\n");
    }else{
        printf("Essa árvore possui: %d nós\n", quant);
    }

    return 0;
}