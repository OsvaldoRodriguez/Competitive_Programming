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
const int N = 2 * 1e5 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
int dis[N];
vector<int> G[N];
int v[N];
int main(){
    int n;
    scanf("%d",&n);
    fore(i,0,n)
        scanf("%d",v + i);
    queue<int> q;
    fore(i,0,n){
        dis[i] = 1e9;
        if(i - v[i] >= 0)
            G[i - v[i]].pb(i);
        if(i + v[i] < n)
            G[i + v[i]].pb(i);
        if((i - v[i] >= 0 && v[i] % 2 != v[i - v[i]] % 2) or (i + v[i] < n && v[i + v[i]] % 2 != v[i] % 2))
            dis[i] = 1,q.push(i);
    }
    while(sz(q)){
        int a = q.front();q.pop();
        fore(i,0,G[a].size()){
            int v = G[a][i];
            if(dis[a] + 1 < dis[v]){
                dis[v] =  dis[a] + 1;
                q.push(v);
            }
        }
    }
    fore(i,0,n)
        if(dis[i] == 1e9)
            printf("-1 ");
        else
            printf("%d ",dis[i]);
    return 0;
}
    
