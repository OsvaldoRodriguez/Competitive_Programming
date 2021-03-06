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
const int N = 1e5 + 5;
const ll mod = 1e9 + 7;
const double E = 1e-7;
const int INF = 1e2;
//int dx[] = {0, -1}, dy[] = {-1, 0};
//int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
//int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
map<string, int> in, vis;
vector<string> letras, ans;
int test = 1;
int cnt = 0;
void dfs(map<string,vector<string>> &G){
    if(sz(ans) == sz(letras)){
        cnt++;
        if(test > 1 && cnt == 1)cout << '\n';
        for(auto i : ans)cout << i;cout << '\n';
    }
    for(auto i : letras){
        if(!vis[i] && in[i] == 0){
            ans.pb(i);
            vis[i] = 1;
            for(auto v : G[i])
                in[v]--;
            dfs(G);
            vis[i] = 0;
            ans.pop_back();
            for(auto v : G[i])
                in[v]++;
        }
    }
}
void solve(){
    string A, B;
    while(getline(cin, A)){
        cnt = 0;
        in.clear();
        vis.clear();
        getline(cin, B);
        int node = 1;
        map<string, int> mp;
        letras.clear();
        fore(i, 0, sz(A)){
            string aux = "";
            while(i < sz(A) && A[i] != ' ')aux += A[i++];
            letras.pb(aux);
        }
        map<string, vector<string>> G;
        vector<string> cur;
        fore(i, 0, sz(B)){
            string aux = "";
            while(i < sz(B) && B[i] != ' ')aux += B[i++];
            cur.pb(aux);
            if(sz(cur) & 1)continue;
            G[cur[0]].pb(cur[1]);
            in[cur[1]]++;
            cur.clear();
        }
        sort(all(letras));
        dfs(G);
        test++;
    }  
} 

int main(){
    FIN;
    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++){
        solve();
    }
    //EjecuteTime;
    return 0;
}  
