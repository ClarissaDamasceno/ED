#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMEROS 100001 // tamanho máximo do array

int main() {
    FILE *file;
    int numeros[MAX_NUMEROS];
    int contador = 0;

    // abrir o arquivo para leitura
    file = fopen("num.1000.1.in", "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    // armazenar os números do arquivo no array
    while (fscanf(file, "%d", &numeros[contador]) == 1) {
        contador++;

	//LEMBRAR DE APAGAR
        if (contador >= MAX_NUMEROS) {
            printf("Excedido o número máximo de números (%d)\n", MAX_NUMEROS);
            break;
        }
    }

    fclose(file);

    // Exibe o conteúdo do arquivo (opcional)
    printf("Números lidos do arquivo:\n");
    for (int i = 0; i < contador; i++) {
        printf("%d\n", numeros[i]);
    }

    // algoritmo de ordenação Selection Sort
    int menor;

    for (int i = 0; i < contador; i++) {
	menor = i;
	for(int j = i+1; j < contador; j++){
        	if (numeros[j] < numeros[menor])
            		menor = j;
        }
	int aux = numeros[i];
	numeros[i] = numeros[menor];
	numeros[menor] = aux;
    }

    // Exibe os números ordenados
    printf("Números ordenados:\n");
    for (int i = 0; i < contador; i++) {
        printf("%d\n", numeros[i]);
    }

    return 0;
}
