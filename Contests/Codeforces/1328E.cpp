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
const int N = 2 * 1e5 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
//freopen("","r",stdin);
//freopen("","w",stdout);
const int LOG = 20;
vector<int> G[N];
int P[N][LOG];
int pro[N];
void dfs(int u,int parent, int prof){
    P[u][0] = parent;
    pro[u] = prof;
    fore(i,1,LOG)
        P[u][i] = P[P[u][i - 1]][i - 1];
    fore(i,0,sz(G[u])){
        int v = G[u][i];
        if(v != parent)
            dfs(v,u,prof + 1);
    }
}
int subir(int u,int k){
    fore(i,0,LOG){
        if(k & (1 << i))
            u = P[u][i];
    }
    return u;
}
int main(){
    int n,m,len;
    scanf("%d%d",&n,&m);
    int u,v;
    fore(i,1,n){
        scanf("%d %d",&u,&v);
        u--;v--;
        G[u].pb(v);
        G[v].pb(u);
    }
    dfs(0,0,0);
    
    while(m--){
        scanf("%d",&len);
        vector<ii> path(len);
        fore(i,0,len){
            scanf("%d",&u);
            u--;
            path[i].S = subir(u,1);
            path[i].F = pro[path[i].S];
        }
        bool flag = 1;
        //printf("prof\n");
        sort(all(path));
        reverse(all(path));
        /*for(auto i : path)
            printf("%d %d\n",i.F,i.S);
        printf("\n");
        */fore(i,1,sz(path)){
            int up = path[i - 1].F - path[i].F;
            int node = subir(path[i - 1].S,up);
            //printf("%d %d up node\n",up,node);
            flag &= (node == path[i].S);
        }
        printf(flag?"YES\n":"NO\n");
    }
	return 0;
}
