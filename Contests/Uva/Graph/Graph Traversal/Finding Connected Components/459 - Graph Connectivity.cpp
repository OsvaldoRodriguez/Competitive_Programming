#include<bits/stdc++.h>
using namespace std;
const int N = 30;
int P[N + 5];
int NroConjuntos;
 
void init(int n){
    for(int i = 0; i <= n; i++)
        P[i] = i;
}
int _find(int u){
    if(u == P[u])
        return u;
    return P[u] = _find(P[u]); // compresion de caminos
}
 
void _unir(int u, int v){
    u = _find(u);
    v = _find(v);
    if(u != v){
        //P[v] = u;
        P[u] = v;  
        NroConjuntos--;
    }
}
int main(){
    int t;
    cin >> t;
    string str;
    getline(cin, str);
    getline(cin, str);
     
    for(int i = 0; i < t; i++){
        string nodo;
        getline(cin, nodo);
        init(nodo[0] - 'A' + 1);
        NroConjuntos = nodo[0] - 'A' + 1;
        while(getline(cin, str)){
            if(str == "")
                break;
            _unir(str[0] - 'A', str[1] - 'A');
             
        }
        if(i > 0)
            cout << '\n';
        cout << NroConjuntos << '\n';
    }
 
 
    return 0;
}
