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
const int N = 2e4 + 5;
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
vi G[N];
int dp[N][10];
int f(int u, int col, int par = -1){
    int &ans = dp[u][col];
    if(ans == -1){
        ans = col;
        for(int v : G[u]){
            if(v == par)continue;
            int mn = 1e9;
            for(int j = 1; j < 10; j++)
                if(j != col)
                    mn = min(mn, f(v, j, u));
            ans += mn; 
        }
    }
    return ans;
}

void solve(){   
    int n, u, v, nodes;
    string str;
    while(cin >> n && n){
        fore(i, 0, n){
            G[i].clear();
        }
        //db("test");
        cin.ignore();
        nodes = 0;
        while(getline(cin, str) && str != ""){
            int i = 0;
            string aux = "";
            while(str[i] != ':')aux += str[i++];
            u = atoi(aux.data());
            i += 2;
            for(; i < sz(str); i++){
                aux = "";
                while(i < sz(str) && str[i] != ' ')
                    aux += str[i++];
                v = atoi(aux.data());
                G[u].pb(v);
                G[v].pb(u);
            }
            nodes++;
        }
        cls(dp, -1);
        int ans = 1e9;
        int j = -1;
        fore(i, 1, 10){
            ans = min(ans, f(0, i));
        }
        cout << ans << '\n';
        
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
