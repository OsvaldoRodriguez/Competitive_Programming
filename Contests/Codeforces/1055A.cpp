#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ii pair<int,int>
#define F first
#define S second
#define pb push_back
#define pf push_front
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define fore(i,a,b) for(int i = a;i < b; i+= 1)
#define forr(i,a) for(int i = a; i >= 0; i--)
#define fori(i,m) for(auto i = m.begin(); i != m.end(); i++) 
#define sz(s) int(s.size())
#define cls(a,car) memset(a,car,sizeof (a))
using namespace std;
typedef long long ll;
const int N = 1 * 1e5 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
vector<int> G[1005];
int vis[1005];
void dfs(int u){
    //cout << u << " dfs\n"; 
    vis[u] = 1;
    fore(i,0,sz(G[u]))
        if(vis[G[u][i]] == -1)
            dfs(G[u][i]);
}
int main(){/*
    freopen("in","r",stdin);
    freopen("out","w",stdout);*/
    int n,p;
    cin >> n >> p;
    int a[n + 1],b[n + 1];
    fore(i,0,n)cin >> a[i];
    fore(i,0,n)cin >> b[i];
    int aux = -1;
    fore(i,0,n){
        if(a[i]){
            if(aux == -1)
                aux = i + 1;
            else{
                //cout << aux << " " << i + 1 << endl;
                G[aux].pb(i + 1);
                aux = i + 1;
            }
        }
    }
    aux = -1;
    for(int i = n - 1; i >= 0; i--){
        if(b[i]){
            if(aux == -1)
                aux = i + 1;
            else{

                //cout << aux << " " << i + 1 << endl;
                G[aux].pb(i + 1);
                aux = i + 1;
            }
        }
    }
    fore(i,0,n){
        if(a[i]){
            for(int j = i - 1; j >= 0; j--){
                if(b[j] && b[i] == '1')
                    G[i + 1].pb(j + 1);
            }
        }
    }
    cls(vis,-1);
    dfs(1);
    if(vis[p] == 1)
        cout << "YES" << '\n';
    else
        cout << "NO\n";
    return 0;
}
