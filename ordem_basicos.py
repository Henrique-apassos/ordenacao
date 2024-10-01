def trocar(v, i, j):
 temp = v[i]
 v[i] = v[j]
 v[j] = temp
def bubblesort(v, N):
 for i in range(N-1,0,-1):
    for j in range(0,i):
        if v[j] > v[j+1]: trocar(v,j,j+1)

def selectionsort(v, N):
 for i in range(0,N):
    min  = i
    for j in range(i+1,N):
        if v[min] > v[j]: min = j
 trocar(v,i,min)

def insertionsort(v, N):
    for i in range(1,N): # i: local da divisão
        aux = v[i]
        j = i - 1
    while j >= 0 and v[j] > aux:
       v[j+1]= v[j]
       j -= 1
    v[j+1] = aux

def shellsort(v, N):
   h=1
   while h < N//3: h = 3*h +1
   while h >= 1:
      for i in range(h, N):
         j = i
         while j >= h and v[j] < v[j-h]:
            trocar(v,j,j-h)
            j -= h
         h//=3
