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
#define FL          freopen("in", "r", stdin),freopen("out", "w", stdout);
#define EjecuteTime cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n"
#define angle(x)    double(x * acos(-1) / 180.0)
using namespace std;
typedef long long   ll;
typedef vector<int> vi;
typedef vector<ii>  vii;
const int N = 1 * 1e6 + 5;
const ll mod = 1e9 + 7;
const double E = 1e-9;
//int dx[] = {1, 0}, dy[] = {0, 1};
//int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
int v[N],dis[N];
vector<int> pr,G[N];
void bfs(int node){
    dis[node] = 0;
    queue<int> q;
    q.push(node);
    while(!q.empty()){
        int u = q.front();q.pop();
        fore(i,0,G[u].size()){
            int v = G[u][i];
            if(dis[v] == -1){
                q.push(v);
                dis[v] = dis[u] + 1;
            }
        }
    }
}
int main(){
    //FL;
    //FIN;
    v[0] = v[1] = 1;
    for(int i = 2; i < N; i++)
        if(!v[i]){
            if(i > 999 && i < 10000)
            pr.pb(i);
            for(int j = i + i; j < N; j += i)
                v[j] = 1;
        }
 
    fore(i,0,pr.size()){
        string aux = to_string(pr[i]);
        fore(j,0,4){
            string tmp = aux;
            int k = 0;
            if(j == 0)
                k = 1;
            for(; k < 10; k++){
                tmp[j] = char(k + '0');
                int u = pr[i];
                int v1 = atoi(tmp.data());
                if(!v1[v] && tmp != aux ){
                    G[u].pb(v1);
                    G[v1].pb(u);
                }
            }
        }
    }
     
    int n,x,y;
    scanf("%d",&n);
    while(n--){
        scanf("%d %d",&x, &y);
        fore(i, 1000, 10000)
            dis[i] = -1;
        bfs(x);
        if(dis[y] == -1)
            printf("Impossible\n");
        else
        printf("%d\n", dis[y]);
    }
    return 0;
}       
