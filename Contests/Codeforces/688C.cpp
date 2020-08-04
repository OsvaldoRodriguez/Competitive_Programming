#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ii pair<int,int>
#define F first
#define S second
#define pb push_back
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
vector<int> G[N];
int vis[N],p[N];
bool flag = 1,sw = 0;
void bfs(int nodo){
  queue<int> q;
  vis[nodo] = 0;//puede estar en 0 o en 1 da lo mismo
  q.push(nodo);
  while(!q.empty()){
    int u=q.front();q.pop();
    for(int i=0;i<G[u].size();i++){
      int v=G[u][i];
      if(vis[v]==-1){
        q.push(v);
        vis[v]=vis[u]^1;
      }
      else if(vis[u]==vis[v])
        flag=0;
    }
  }
}
int main(){   
    int n,m;
    scanf("%d %d",&n,&m);
    fore(i,0,m){
        int u,v;
        scanf("%d%d" ,&u,&v);
        G[u].pb(v);
        G[v].pb(u);
    }

    
        cls(vis,-1);
        fore(i,1,n + 1){
            if(vis[i] == -1)
                bfs(i);
        }
        if(flag){
            vector<int> a,b;
            fore(i,1,n + 1)
                if(vis[i] == 1)
                    a.pb(i);
                else
                    b.pb(i);
            printf("%d\n",a.size());
            for(auto i : a)
                printf("%d ",i);
            printf("\n");
            printf("%d\n",sz(b) );
            for(auto i : b)
                printf("%d ",i);
            printf("\n");    
        }else
        printf("-1\n");
        
    
    return 0;
}
    
