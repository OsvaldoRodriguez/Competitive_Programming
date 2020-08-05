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
typedef vector<int> vi;
const int N = 1 * 1e5 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
const double E = 1e-9;
vector<int> G[N],tip[105];
int dis[105][N];
void bfs(int k,int j){
    queue<int> q;
    fore(i,0,sz(tip[k])){
        q.push(tip[k][i]);
        dis[j][tip[k][i]] = 0;
    }
    while(sz(q)){
        int u = q.front();q.pop();
        for(auto v : G[u])
            if(dis[j][v] == -1){
                q.push(v);
                dis[j][v] = dis[j][u] + 1;
            }
    }
}
int main(){
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    int n,m,k,s;
    cls(dis,-1);
    scanf("%d %d%d%d",&n,&m,&k,&s);
    fore(i,0,n){
        int x;
        scanf("%d",&x);
        x--;
        tip[x].pb(i);
    }
    while(m--){
        int u,v;
        scanf("%d %d",&u,&v);
        u--;v--;
        G[u].pb(v);
        G[v].pb(u);
    }

    fore(i,0,k)
        bfs(i,i);

    fore(i,0,n){
        vector<int> aux;
        fore(j,0,k)
            aux.pb(dis[j][i]);
        sort(all(aux));
        int ans = 0;
        fore(i,0,s)
            ans += aux[i];
        printf("%d ",ans);
    }
    return 0;
}   
