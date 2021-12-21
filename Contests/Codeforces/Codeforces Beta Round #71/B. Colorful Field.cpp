#include <bits/stdc++.h>
#define ii              pair<int,int>
#define F               first
#define S               second
#define pb              push_back
#define all(x)          (x).begin(),(x).end()
#define rall(x)         (x).rbegin(),(x).rend()
#define fore(i, a, b)   for(int i = a; i < b; i += 1)
#define forr(i, a)      for(int i = a; i >= 0; i--)
#define sz(s)           int(s.size())
#define cls(a, car)     memset(a,car,sizeof (a))
#define db(x)           cout << #x << " is " << x << '\n'
#define angle(x)        double(x * acos(-1) / 180.0)
using namespace std;
void debug(){cout << endl;}
template<typename T, typename... Args>
void debug(T a, Args... args){cout << a << " "; debug(args...);}
typedef long long   ll;
typedef vector<int> vi;
typedef vector<ii>  vii;
const int N = 4e4 + 15;
const ll mod = INT_MAX;
const double E = 1e-7;
vector<int> G[N];
int len[N];
int acc[N];
void solve(){
    
    int n, m, k, t;
    int a, b;
    cin >> n >> m >> k >> t;
    vector<string> ans = {"Carrots", "Kiwis", "Grapes"};
    while(k--){
        cin >> a >> b;
        G[a].pb(b);
        len[a]++;
    }   

    acc[0] = len[0];
    for(int i = 1; i < n; i++)
        acc[i] = acc[i - 1] + len[i];
    for(int i = 0; i <= n; i++){
        vector<int> aux = G[i];
        sort(all(aux));
        G[i] = aux;
    }

    
    while(t--){
        cin >> a >> b;
        int aux = (a - 1) * m + b;
        // db(aux);
        int i = 0;
        bool flag = 1;


        while(i < G[a].size() and G[a][i] <= b){
            if(b == G[a][i])
                flag = 0;
            i++;
        }
        aux -= acc[a - 1];
        // db(aux);
        aux -= i;
        aux--;
        // db(aux);
        aux = (aux + 3) % 3;
        if(flag == 0)
            cout << "Waste\n";
        else
            cout << ans[aux] << '\n';

    }

}
int main(){
    #ifdef FURY
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #endif
    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++){ 
        solve();
    }

    #ifdef FURY
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}
