#include <bits/stdc++.h>
#define FIN         ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ii          pair<int,int>
#define F           first
#define S           second
#define pb          push_back
#define all(x)      (x).begin(),(x).end()
#define rall(x)     (x).rbegin(),(x).rend()
#define fore(i,a,b) for(int i = a;i < b; i+= 1)
#define forr(i,a)   for(int i = a; i >= 0; i--)
#define fori(i,m)   for(auto i = m.begin(); i != m.end(); i++) 
#define w(t)        while(t--)
#define sz(s)       int(s.size())
#define cls(a,car)  memset(a,car,sizeof (a))
#define db(x)       cerr << #x << " is " << x << '\n'
#define FI          freopen("input.txt", "r", stdin)
#define FO          freopen("output.txt", "w", stdout)
#define EjecuteTime cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n"
#define angle(x)    double(x * acos(-1) / 180.0)
using namespace std;
typedef long long   ll;
typedef vector<int> vi;
typedef vector<ii>  vii;
const int N = 2e2 + 5;
const ll mod = 1e9 + 7;
const double E = 1e-7;
const int INF = 1e2;

/*
Complexity:
  Time and Space: O(t + p)
  t: texto
  p: patron
*/
vector<int> get_phi(string &p){// O(p)
    int n = sz(p);
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
    for(int i = 0, j = 0; i < sz(t); i++){
        while(j > 0 && t[i] != p[j])j = phi[j - 1];
        if(t[i] == p[j])j++;//si machean
        if(j == sz(p)){//encuentra una ocurrencia de s en t
            mathes.pb(i - sz(p) + 1);//index 0
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
    FIN;
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++){
        solve();
    }
    EjecuteTime;
    return 0;

}
