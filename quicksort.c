#include <stdio.h>
#include <stdlib.h>

void troca(int *vetor, int i, int j){
    int temp;
    temp = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = temp;
}

int particao(int *vetor, int esq, int dir){
    int para = 0;
    int pivo = vetor[esq];
    int i = esq;
    int j = dir + 1;
    while(para == 0){
        i++;
        while(vetor[i] < pivo){
            if(i >= dir) para = 1;
            i++;
        }
        j--;
        while(para == 0 && vetor[j] > pivo){
            if(j <= esq) para = 1;
            j--;
        }
        if(i >= j) para = 1;
        else troca(vetor, i, j);
    }
    troca(vetor, esq, j);
    return j;
}

void qs(int *vetor, int esq, int dir){
    if(esq >= dir) return;
    int p = particao(vetor, esq, dir);
    qs(vetor, esq, p-1);
    qs(vetor, p+1, dir);
}

void quicksort(int *vetor, int tam){
    qs(vetor, 0, tam-1);
}

int main(){
    int tam;
    int *vetor = NULL;
    printf("Insira o tamanho do vetor: ");
    scanf("%d", &tam);
    vetor = (int*)malloc(tam*sizeof(int));
    if(vetor == NULL){
        printf("Erro de alocacao\n");
        exit(1);
    }
    printf("Insira os elementos: \n");
    for(int i=0; i<tam; i++){
        scanf("%d", &vetor[i]);
    }

    quicksort(vetor, tam);

    printf("vetor ordenado: \n");
    for(int i=0; i<tam; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
    
    free(vetor);
}