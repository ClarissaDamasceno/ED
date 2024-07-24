## Resumo
<p align="justify"> O código lê números de um arquivo de teste selecionado pelo usuário 
  e armazena esses números em dois arrays (numeros_selection e numeros_insertion). 
  Ordena os números usando um algoritmo diferente para cada array (Selection Sort e 
  Insertion Sort). Mede e imprime o tempo de execução para cada algoritmo. Por fim, 
  grava os números ordenados em arquivos de saída. </p>

## Explicação do código
```c
int main() {
	FILE *file;
	int numeros_selection[MAX_NUMEROS];
	int numeros_insertion[MAX_NUMEROS];
	int contador = 0;
	int select_test = 0;
	char* test_file[] = {"num.1000.1.in", "num.1000.2.in", "num.1000.3.in", "num.1000.4.in",
		    "num.10000.1.in", "num.10000.2.in", "num.10000.3.in", "num.10000.4.in",
		    "num.100000.1.in", "num.100000.2.in", "num.100000.3.in", "num.100000.4.in"};
```
> **numeros_selection e numeros_insertion**: armazenam os números lidos do arquivo de teste\
**contador**: conta o número de elementos lidos\
**select_test**: armazena a opção de teste escolhida pelo usuário\
**test_file**: array de strings que contém os nomes dos arquivos de teste


```c
	printf("Selecione um arquivo de teste:\n 1 - [1000.1]\n 2 - [1000.2]\n 3 - [1000.3]\n 4 - [1000.4]\n"
					  " 5 - [10000.1]\n 6 - [10000.2]\n 7 - [10000.3]\n 8 - [10000.4]\n"
					  " 9 - [100000.1]\n10 - [100000.2]\n11 - [100000.3]\n12 - [100000.4]\n");
	scanf("%d", &select_test);

	file = fopen(test_file[select_test-1], "r");
	if (file == NULL) {
		perror("Erro ao abrir o arquivo para leitura");
		return 1;
	}
```
> Solicita ao usuário a seleção de um arquivo de teste e lê a escolha. Em seguida, abre o arquivo selecionado para leitura


```c
	while (fscanf(file, "%d", &numeros_selection[contador]) == 1) {
		numeros_insertion[contador] = numeros_selection[contador];
		contador++;
	}

	fclose(file);
```
> Lê os números do arquivo e os armazena em ambos os arrays numeros_selection e numeros_insertion

## Algoritmo Selection Sort
```c
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
```
> Ordena o array numeros_selection usando o algoritmo Selection Sort e mede seu tempo de execução

## Algoritmo Insertion Sort
```c
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
```
> Ordena o array numeros_insertion usando o algoritmo Insertion Sort e mede seu tempo de execução

```c
	printf("\n[Selection Sort] Tempo de execução: %f seconds\n", time_spent1);
	printf("[Insertion Sort] Tempo de execução: %f seconds\n", time_spent2);
```
> Exibe o tempo de execução dos dois algoritmos para comparação de desempenho

```c
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
```
> Por fim, os números ordenados são escritos em arquivos txt

## Comparação entre os algoritmos: Selection Sort X Insertion Sort
<p align="justify"> Os dois algoritmos ordenaram os números de maneira correta e o 
  algoritmo Insertion Sort demonstrou ter um tempo de execução mais rápido que o 
  Selection Sort em todos os casos de teste. </p>
