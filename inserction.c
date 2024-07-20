#include <stdio.h>
#include <time.h>

void ordena(int arr[], int n) {
    int i, j, menor;
    

    for (i = 0; i < n - 1; i++) {
        menor = arr[i];
        j = i - 1;
        
        while(j>= 0 && arr[j] > menor){
                arr[j+1] = arr[j];
                j--;
        }
        arr[j+1]  = menor;
    }
}


void imprimeArray(int arr[], int tamanho) {
    int i;
    for (i = 0; i < tamanho; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


int main() {
    
    struct timespec inicio, fim;
    double tempo_decorrido;
    FILE *arqv;
    int arr[1000], numero;
    int i = 0;
    int n = sizeof(arr)/sizeof(arr[0]);
    

    if (clock_gettime(CLOCK_MONOTONIC, &inicio) == -1) {
        perror("clock_gettime");
        return 1;
    }
    
    arqv = fopen ("num.1000.1.in", "r");
    
    if(arqv == NULL){
        printf("O arquivo nao pode ser aberto com sucesso!\n");
        return 1;
    }else{
        while(fscanf(arqv, "%d", &arr[i]) != EOF){
                i++;
        }
    }
    
      printf("Array original: \n");
    imprimeArray(arr, n);
    ordena(arr, n);
    printf("Array ordenado: \n");
    imprimeArray(arr, n);

    if (clock_gettime(CLOCK_MONOTONIC, &fim) == -1) {
        perror("clock_gettime");
        return 1;
    }

    // Calcula o tempo decorrido em segundos
    tempo_decorrido = (fim.tv_sec - inicio.tv_sec) + (fim.tv_nsec - inicio.tv_nsec) / 1E9;


    
    printf("O tempo de execucao foi: %lf", tempo_decorrido);
    return 0;
}
