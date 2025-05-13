#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selection_sort(int *v, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[min]) {
                min = j;
            }
        }
        int temp = v[i];
        v[i] = v[min];
        v[min] = temp;
    }
}

void gerar_vetor(int *v, int n, unsigned seed) {
    srand(seed);
    for (int i = 0; i < n; i++) {
        v[i] = rand() % 100000;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Uso: ./selection_sort <tamanho> <semente>\n");
        return 1;
    }

    int n = atoi(argv[1]);
    unsigned seed = atoi(argv[2]);

    int *v = malloc(n * sizeof(int));
    if (v == NULL) {
        fprintf(stderr, "Erro ao alocar memória\n");
        return 1;
    }

    gerar_vetor(v, n, seed);

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    selection_sort(v, n);

    clock_gettime(CLOCK_MONOTONIC, &end);

    double tempo = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;

    printf("%d\t%f\n", n, tempo);

    free(v);
    return 0;
}
