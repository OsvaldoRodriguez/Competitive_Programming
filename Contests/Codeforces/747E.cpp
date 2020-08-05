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
const int N = 1 * 1e6 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
int n, j = 0;
vector<string> G[N],v;
int toInt(string s){
    int ans = 0;
    fore(i,0,sz(s))
        ans = ans * 10 + (s[i] - '0');
    return ans;
}
int mx = 0;
void dfs(int u){
    j += 2;
    G[u].pb(v[j - 2]);
    mx = max(mx,u);
    int sz = toInt(v[j - 1]);
    fore(i,0,sz){
        dfs(u + 1);
    }

}
int main(){/*
    freopen("in","r",stdin);
    freopen("out","w",stdout);*/
    fast;
    string s;
    cin >> s;
    fore(i,0,sz(s)){
        string aux = "";
        while(i < sz(s) && s[i] != ',')
            aux += s[i++];
        v.pb(aux);
    }
    while(j < sz(v))
        dfs(0);
    cout << mx + 1 << '\n';
    fore(i,0,mx + 1){
        fore(j,0,sz(G[i])){
            cout << G[i][j] << ' ';
        }
        cout << '\n';
    } 
    return 0;   
}
