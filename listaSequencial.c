#include <stdlib.h>
#include <stdio.h>

typedef struct{
    int vetor[10];
    int tamanho;

}lista;

lista* criaLista(){
    lista* l = (lista*)malloc(sizeof(lista));

    if(l){
        printf("A LISTA FOI CRIADA COM SUCESSO!\n");
        l->tamanho = 0;
    }else{
        perror("Erro na criação da lista!");
        exit(1);
    }
    return l;
}

int ehvazia(lista *l){
    if(l->tamanho == 0){
        printf("A lista está vazia!");
        return 1;
    }else{
        return 0;
    }
}

int ehcheia(lista *l){
    if(l->tamanho == 10){
        printf("A lista está cheia!");
        return 1;
    }
    return 0;
}

int getTam(lista *l){
    int tam = 0;
    for(int i = 0; i<l->tamanho; i++){
        while(l->vetor[i] != NULL)
            tam++;
    }
    printf("%d espaços estão sendo ocupados", tam);
    return tam;
}

lista * inserir(lista *l, int pos, int numero){
    if(ehcheia(l) || pos<0 || pos>l->tamanho){
        printf("Nao é possivel inserir\n");
        return l;
    }else{
        for(int i = l->tamanho; i>pos; i--){
            l->vetor[i] = l->vetor[i-1];
        }
        l->vetor[pos] = numero;
        l->tamanho = l->tamanho + 1;
    }

    return l;
}
lista * remover(lista *l, int pos){

    if(pos<0 || pos>l->tamanho){
        printf("indice inválido!\n");
    }else{
        for(int i = pos; i< l->tamanho; i++)
            l->vetor[i] = l->vetor[i+1];
        l->tamanho = l->tamanho - 1;  
    }

    return l; 
}
lista * modifica(lista *l, int pos, int numero){
    if(pos<0 || pos>l->tamanho){
        printf("Posição inválida\n");
    }else{
        l->vetor[pos];
    }
    return l;
};

int menu(){
    int op;
    printf("[1] - VERIFICAR SE A LISTA ESTÁ VAZIA\n");
    printf("[2] - VERIFICAR SE A LISTA ESTÁ CHEIA\n");
    printf("[3] - VERIFICAR O TAMANHO DA LISTA\n");
    printf("[4] - INSERIR ELEMENTO\n");
    printf("[5] - REMOVER ELEMENTO\n");
    printf("[6] - MODIFICAR ELEMENTO\n");
    printf("[7] - SAIR\n");
    scanf("%d", &op);
    return op;
}

int main()
{
    lista *l = criaLista();
    int pos, numero;

    switch(menu()){
        case 1:
            ehvazia(l);
            break;
        case 2:
            ehcheia(l);
            break;
        case 3: 
            getTam(l);
            break;
        case 4:
            scanf("%d", &pos);
            scanf("%d", &numero);
            inserir(l, pos, numero);
            break;
        case 5:
            scanf("%d", &pos);
            scanf("%d", &numero);
            remover(l, pos);
            break;
        case 6:
            scanf("%d", &pos);
            scanf("%d", &numero);
            modifica(l, pos, numero);
        case 7:
            exit(1);
        default:
            printf("Opção inválida!\n");
    }

    return 0;
}