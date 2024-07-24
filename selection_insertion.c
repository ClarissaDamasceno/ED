#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMEROS 100001 // tamanho máximo do array
#define BILLION  1000000000.0 //converter o tempo em segundos

int main() {
	FILE *file;
	int numeros_selection[MAX_NUMEROS];
	int numeros_insertion[MAX_NUMEROS];
	int contador = 0;
	int select_test = 0;
	char* test_file[] = {"num.1000.1.in", "num.1000.2.in", "num.1000.3.in", "num.1000.4.in",
		    "num.10000.1.in", "num.10000.2.in", "num.10000.3.in", "num.10000.4.in",
		    "num.100000.1.in", "num.100000.2.in", "num.100000.3.in", "num.100000.4.in"};

	printf("Selecione um arquivo de teste:\n 1 - [1000.1]\n 2 - [1000.2]\n 3 - [1000.3]\n 4 - [1000.4]\n"
					  " 5 - [10000.1]\n 6 - [10000.2]\n 7 - [10000.3]\n 8 - [10000.4]\n"
					  " 9 - [100000.1]\n10 - [100000.2]\n11 - [100000.3]\n12 - [100000.4]\n");
	// escolher um arquivo de teste
	scanf("%d", &select_test);

	// abrir o arquivo para leitura
	file = fopen(test_file[select_test-1], "r");
	if (file == NULL) {
		perror("Erro ao abrir o arquivo para leitura");
		return 1;
	}

	// armazenar o conteúdo do arquivo em dois arrays distintos
	while (fscanf(file, "%d", &numeros_selection[contador]) == 1) {
		numeros_insertion[contador] = numeros_selection[contador];
		contador++;
	}

	fclose(file);

	//----------algoritmo de ordenação Selection Sort----------
	printf("\nExecutando algoritmo Selection Sort, aguarde...\n");
	struct timespec start1, end1; //calcula o tempo de execução do algoritmo
	clock_gettime(CLOCK_REALTIME, &start1);

	int menor;
	for (int i = 0; i < contador; i++) {
		menor = i;
		for(int j = i+1; j < contador; j++){
			if (numeros_selection[j] < numeros_selection[menor])
	    			menor = j;
		}
		int aux = numeros_selection[i];
		numeros_selection[i] = numeros_selection[menor];
		numeros_selection[menor] = aux;
	}

	clock_gettime(CLOCK_REALTIME, &end1);
	double time_spent1 = (end1.tv_sec - start1.tv_sec) + (end1.tv_nsec - start1.tv_nsec) / BILLION;

	//----------algoritmo de ordenação Insertion Sort----------
	printf("Executando algoritmo Insertion Sort, aguarde...\n");
	struct timespec start2, end2; //calcula o tempo de execução do algoritmo
	clock_gettime(CLOCK_REALTIME, &start2);

	for(int i = 1; i < contador; i++){
		int aux, j = i;
		aux = numeros_insertion[j];
		while(j>0 && aux > numeros_insertion[j-1]){
			numeros_insertion[j] = numeros_insertion[j-1];
			j--;
		}
		numeros_insertion[j] = aux;
	}

	clock_gettime(CLOCK_REALTIME, &end2);
	double time_spent2 = (end2.tv_sec - start2.tv_sec) + (end2.tv_nsec - start2.tv_nsec) / BILLION;


	printf("\n[Selection Sort] Tempo de execução: %f seconds\n", time_spent1);
	printf("[Insertion Sort] Tempo de execução: %f seconds\n", time_spent2);


	// escreve os numeros ordenados em um arquivo txt [OPCIONAL]
	file = fopen("numeros_ordenados_selection.txt", "w");
	if (file == NULL) {
		perror("Erro ao abrir o arquivo para escrita");
		return 1;
	}

	for (int i = 0; i < contador; i++) {
		fprintf(file, "%d\n", numeros_selection[i]);
	}

	file = fopen("numeros_ordenados_insertion.txt", "w");
	if (file == NULL) {
		perror("Erro ao abrir o arquivo para escrita");
		return 1;
	}

	for (int i = 0; i < contador; i++) {
		fprintf(file, "%d\n", numeros_selection[i]);
	}

    return 0;
}
