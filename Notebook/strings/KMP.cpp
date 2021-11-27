#include <bits/stdc++.h>
using namespace std;

/*
Complexity:
  Time and Space: O(t + p)
  t: texto
  p: patron
*/
vector<int> get_phi(string &p){// O(p)
    int n = p.size();
    vector<int> phi(n);
    phi[0] = 0;
    for(int i = 1, j = 0; i < n; i++){
        while(j > 0 && p[i] != p[j]) j = phi[j - 1];//buca el prefijo  sufijo maximo en el rango [0, i]
        if(p[i] == p[j])j++;// si machean
        phi[i] = j;
    }
    return phi;
}

vector<int> get_match(string &t, string &p){//O(p + t)
    vector<int> phi = get_phi(p);
    vector<int> mathes;//posiciones de las ocurrencias
    for(int i = 0, j = 0; i < t.size(); i++){
        while(j > 0 && t[i] != p[j])j = phi[j - 1];
        if(t[i] == p[j])j++;//si machean
        if(j == (int)p.size()){//encuentra una ocurrencia de s en t
            mathes.push_back(i - (int)p.size() + 1);//index 0
            j = phi[j - 1];//buscar el prefijo sufijo maximo del [0, sz(p)]
        }
    }
    return mathes;
}

/*
otra manera de encontrar ocurrencias de p en t es
cad = p + "#" + t y lanzar get_phi
si en phi(prefijos y sufijos maximos de [0, i]) existe phi[i] == sz(p), para todo j [sz(p) + 1, sz(phi)]
entonces es una ocurrencia de p en t
string nw = p + "#" + t;
vi phi = get_phi(nw);
vi ans;
for(int i = sz(p) + 1; i < sz(phi); i++)
    if(phi[i] == sz(p))
        ans.pb(i - sz(p) - sz(p) + 1); posicion donde ocurre p en t
*/
void solve(){   
    string t, p;
    cin >> t >> p;
    vector<int> ans = get_match(t, p);
    for(auto i : ans)cout << i << ' ';
    cout << '\n';
    
}
int main(){
    solve();
    return 0;

}
