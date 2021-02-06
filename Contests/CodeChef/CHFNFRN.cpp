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
int n,m;
int G[1005][1005];
int color[1005];
bool check(int node){
    queue<int> q;
    q.push(node);
    color[node] = 0;
    while(!q.empty()){
        int u = q.front();q.pop();
        fore(i,0,n){
            if(G[u][i] == 0 && color[i] == -1){
                q.push(i);
                color[i] = color[u] ^ 1;
            }
            if(G[u][i] == 0 && u != i && color[u] == color[i])
                return 0;
        }
    }
    return 1;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        cls(G,0);
        cls(color,-1);
        int u,v;
        while(m--){
            scanf("%d %d",&u,&v);
            u--;v--;
            G[u][v] = G[v][u] = 1;
        }
        bool flag = 1;
        fore(i,0,n){
            if(color[i] == -1)
                flag &= check(i);

            if(!flag)
                break;
        }
        printf(flag?"YES\n":"NO\n");
    }
	return 0;
}
