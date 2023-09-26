// v[] -> vector que tiene el conjunto
// used[] -> state of element 
void subSets(int pos){
    if(pos == n){
        // array used[] tiene la mascara del subconjunto
        return;
    }
    used[pos] = 1; // tomar
    subSets(pos + 1);
    used[pos] = 0; // no tomar
    subSets(pos + 1);
}
