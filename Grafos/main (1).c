#include <stdio.h>
#include <stdlib.h>

int main() {
    // Nome do arquivo (na mesma pasta do programa)
 const char* nome_arquivo = "C:\\Users\\Camilly Perfeita\\Desktop\\estrutura-de-dados-1\\Grafos\\pcv4.txt";

    
    // Abrir o arquivo para leitura
    FILE* arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", nome_arquivo);
        return 1;
    }

    int num;
    // Ler e imprimir os números do arquivo
    while (fscanf(arquivo, "%d", &num) != EOF) {
        printf("%d ", num);
    }

    // Fechar o arquivo
    fclose(arquivo);

    return 0;
}