#include <stdio.h>
#include <stdlib.h>

void merge(int *vetor, int esq, int meio, int dir){
    int i = esq;
    int j = meio + 1;
    int tam = dir - esq + 1;
    int *aux = (int*)malloc(tam * sizeof(int));
    
    if(aux == NULL){
        printf("Erro de alocacao \n");
        exit(1);
    }

    for(int k = esq; k <= dir; k++) {
        aux[k - esq] = vetor[k];
    }

    for(int k = esq; k <= dir; k++){
        if(i > meio){
            vetor[k] = aux[j - esq];
            j++;
        }
        else if(j > dir){
            vetor[k] = aux[i - esq];
            i++;
        }
        else if(aux[i - esq] > aux[j - esq]){
            vetor[k] = aux[j - esq];
            j++;
        }
        else{
            vetor[k] = aux[i - esq];
            i++;
        }
    }

    free(aux);
}

void mergesort(int *vetor, int esq, int dir){
    if(esq >= dir) return;
    int meio = (esq + dir) / 2;
    mergesort(vetor, esq, meio);
    mergesort(vetor, meio + 1, dir);
    merge(vetor, esq, meio, dir);
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
    
    mergesort(vetor, 0, tam - 1);

    printf("vetor ordenado: \n");
    for(int i=0; i<tam; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
    
    free(vetor);

    return 0;
}