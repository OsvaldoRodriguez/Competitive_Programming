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
const int N = 1e6 + 5;
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
//105470163083
//100000000223257 primos
//1000000000318157
struct Dinic{
    struct Edge{
        int to, rev;
        ll cap, flow;
        Edge(int to, int rev, ll cap, ll flow): to(to), rev(rev), cap(cap), flow(flow){}

        void mostrar(){
            cout << "( " << to << ", " << rev << ", " << cap << ", " << flow << "), ";
        }
    };
    vector<vector<Edge>> G;
    vector<int> dis, block;
    int n, s, t;
    Dinic(int n, int s, int t): n(n), dis(n), block(n), s(s), t(t), G(n){}
   
    void addEdge(int u, int v, ll cap){
        G[u].pb((Edge){v, sz(G[v]), cap, 0});
        G[v].pb((Edge){u, sz(G[u]) - 1, 0, 0});
    
    }

    bool bfs(){
        fill(all(dis), -1);
        queue<int> q;
        q.push(s);
        dis[s] = 0;
        while(sz(q)){
            int u = q.front();q.pop();
            for(auto &e : G[u]){
                int v = e.to;
                if(dis[v] == -1 && e.cap > e.flow){
                    dis[v] = dis[u] + 1;
                    q.push(v);
                }
            }
        }
        return dis[t] >= 0;
    }

    ll dfs(int u, ll f){
        if(u == t)return f;
        for(auto &i = block[u]; i < sz(G[u]); i++){
            Edge &e = G[u][i];
            if(e.cap <= e.flow)continue;
            int v = e.to;
            if(dis[u] + 1 == dis[v]){
                ll cur = dfs(v, min(f, e.cap - e.flow));
                if(cur > 0){
                    e.flow += cur;
                    G[v][e.rev].flow -= cur;
                    return cur;
                }
            }
        }
        return 0;
    }
    ll max_flow(){
        ll ans = 0;
        while(bfs()){
            fill(all(block), 0);
            while(ll cur = dfs(s, LLONG_MAX))
                ans += cur;
        }
        return ans;
    }
};

void solve(){
    string str;
    vector<string> cur;
    while(true){
        while(getline(cin, str)){
            if(str == "")break;
            cur.pb(str);
        }
        getline(cin, str);
        Dinic F(38, 0, 37);

        ll _cur = 0;
        for(auto i : cur){
            int node = (i[0] - 'A' + 1);
            int cost = (i[1] - '0');
            _cur += cost;
            F.addEdge(0, node, cost);
            for(int j = 3; j < sz(i) - 1; j++){
                F.addEdge(node, (i[j] - '0') + 27, 100);
            }
        }
        for(int j = 27; j <= 36; j++)
                F.addEdge(j, 37, 1);
        
        ll mx = F.max_flow();
        if(mx == _cur){
            for(int i = 27; i <= 36; i++){
                bool flag = 0;
                for(int j = 0; j < sz(F.G[i]); j++){
                    int v = F.G[i][j].flow;
                    if(v == -1){
                        cout << (char)(F.G[i][j].to + 'A' - 1); 
                        flag = 1;
                        break; 
                    }
                }
                if(!flag)
                    cout << "_";
            }
            cout << '\n';
        }else
            cout << "!\n";
        cur.clear();
        if(str == "")break;
        else cur.pb(str);
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
