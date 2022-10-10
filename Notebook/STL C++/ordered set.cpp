#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#define fastio      ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll          long long
#define all(_)      (_).begin(), (_).end()
#define sz(_)       int(_.size())
#define pii         pair<int, int>
#define pll         pair<ll, ll>
using namespace std;
using namespace __gnu_pbds; // ordered_set
const int N = 2e5 + 2;
const ll mod = 1e9 + 7;
const double eps = 1e-9;

// less<type>  prioridad menor
// greater<type>  prioridad mayor
// add equal<type>  less_equal or greater_equal // multiset
// 
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
int di[] = {1, 0, 0, -1}, dj[] = {0, -1, 1, 0};
string dir = "DLRU";
//**********************************************************************
// Tarde o temprano la disciplina vence el talento


void solve(){
    ordered_set s;
    s.insert(-10);
    s.insert(3);
    s.insert(4);
    s.insert(4);
    s.insert(10);

    for(auto i : s)
        cout << i << endl;

    // find_by_order(k) // retorna el elemento en la posicion k en el set (index 0)
    auto cur = s.find_by_order(10);
    // si cur == end(s) no existe la posicion en el set (otra forma es verificar el tamaño antes de buscar)
    cout << (end(s) == cur ? "NO EXISTE ESA POSICION" : "SI HAY") << endl;

    // order_of_key(val) retorna la cantidad de numeros que son estrictamente menores a val

    int aux = s.order_of_key(-100);
    cout << "cantidad " << aux << "\n";


    // para buscar (funciona en set y multiset)
    int value = 4;
    // encontramos la posicion donde deberia estar  el elemento value
    int idx = s.order_of_key(value);
    cout << idx << " pos\n";
    // verificamos si en esa posicion esta el elemento value
    cout << (*s.find_by_order(idx) == value ? "SI ESTA" : "NO ESTA") << endl;

    // para eliminar
    // funciona en set y multiset
    value = 3;
    idx = s.order_of_key(value);
    cout << idx << " pos delete\n";

    if(*s.find_by_order(idx) == value){ // esta el elemeneto
        s.erase(s.find_by_order(idx));
    }else{
        cout << "no existe\n";
    }
    
    cout << "set despues de eliminar\n";
     for(auto i : s)
        cout << i << endl;



}   
 
int main(){
    fastio;
    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++){
        solve();
    }
    return 0;
}
// solo recorre en los bits encendidos
// O(bits_encendidos en mask)
// for(int x = mask; x; x &= (x - 1)){
//     int v = __builtin_ctz(x); // da la posicion donde esta 
// }
