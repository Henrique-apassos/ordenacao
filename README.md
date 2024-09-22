# Ordenação de Vetores
Implementei alguns algoritmos de ordenação eficientes em C e C++

### Heapsort
Usa a estrutura de dados **heap** para ordenar um vetor.

Esse tipo de ordenação tem a complexidade de **O(nlogn)**

// A função printa() é usada para imprimir o vetor ordenado

### Mergesort
Usa a tecnica de **dividir para conquistar** para ordenar um vetor.
Ele quebra o vetor em vgetores menores até que seja possível comparar elementos de 2 a 2.
Depois ele executa o merge que insere ordenado os elementos no vetor.

Esse algoritmo também tem complexidade de **O(nlogn)**. Porém, ele utiliza um vetor auxiliar para
separar os elementos. Isso tem um custo de espaço que pode ser relevante para entradas grandes.

### Quicksort
Também é um algoritmo **dividir para conquistar**. Porém, diferente do mergesort, não utiliza
espaço adicional para ordenar.

O vetor é particionado em dois subvetores conforme um elemento qualquer chamado de **pivô**
- Esquerda contém os elementos menores que o pivô
- Direita contém os elementos maiores que o pivô
  
O algoritmo é aplicado a cada um dos subvetores e, ao terminar, o vetor encontra-se ordenado

Na maioria dos casos, quando o vetor não está muito ordenado, tem a complexidade **O(nlogn)**.
Entretanto, quando o vetor está muito ordenado, com poucos elementos para serem substituidos,
o algoritmo apresenta uma complexidade de **O(n²)**, não sendo tão eficiente.

// Cada um possui uma main(). Então se for utilizar com um header é necessário apagar.
