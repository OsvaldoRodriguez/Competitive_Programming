void merge_sort(int l, int r){ // O(n log n)
    if(l == r)
        return;
    int m = (l + r) / 2;
    merge_sort(l, m);
    merge_sort(m + 1, r);
    for(int i = l; i <= r; i++)
        copia[i] = A[i];
    // puntero del hijo izquierdo
    int L = l;
    // puntero del hijo derecho
    int R = m + 1;
    for(int i = l; i <= r; i++){
        // verificar si el hijo izquierdo tiene elementos
        if(L > m){ // ya no tiene elementos el hijo  izquierdo
            A[i] = copia[R++];
        }else if(R > r){ // el hijo derecho ya no tiene elementos
            A[i] = copia[L++];
        }else{ // ambos hijos tienen elementos
            if(copia[L] <= copia[R]){
                A[i] = copia[L++];
            }else{
                A[i] = copia[R++];
            }
        }
    }
}
