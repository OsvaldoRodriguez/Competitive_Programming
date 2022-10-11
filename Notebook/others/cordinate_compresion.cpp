#include <bits/stdc++.h>
using namespace std;
vector<int> coordenadas;
// index 0
// obteniendo el nuevo valor para la coordenada en la posicion i
int get_pos(int x){
    return lower_bound(coordenadas.begin(), coordenadas.end(), x) - coordenadas.begin();
}
// obteniendo el valor de la coordenada (antes de comprimir)
int get_value(int pos){
    return coordenadas[pos];
}
int main(){
    // compresion de coordenadas

    int n;
    cin >> n;
    vector<int> v(n);
    for(int  &i : v){
        cin >> i;
        coordenadas.push_back(i);
    }
    sort(coordenadas.begin(), coordenadas.end());
    // elimina los repetidos ([valores unicos], [final])
    coordenadas.erase(unique(coordenadas.begin(), coordenadas.end()), coordenadas.end());
    int val;
    while(cin >> val){
        cout << val << " " << get_pos(val) << " " << get_value(get_pos(val)) << "\n";
    }
    // si se quisiera tener el get_pos() en O(1) usar un unordered_map

}
