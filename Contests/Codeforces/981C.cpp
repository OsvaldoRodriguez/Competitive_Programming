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
const int N = 1 * 1e5 + 5;
const ll mod = 998244353;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
vector<int> G[N];
int vis[N];
int idx = -1,idx_1 = -1;
int main(){ 
	int n;
	scanf("%d",&n);
	fore(i,1,n){
		int u,v;
		scanf("%d %d",&u,&v);
		G[u].pb(v);
		G[v].pb(u);
	}
	int cnt = 0;
	fore(i,1,n + 1)
		if(sz(G[i]) > 2){
			idx_1 = i;
			cnt++;
		}else
			idx = i;
	if(cnt > 1)
		printf("No\n");
	else{
		printf("Yes\n");
		cls(vis,-1);
		int id = -1;
		if(cnt == 1)
			id = idx_1;
		else
			id = idx;
		vector<int> aux;
		queue<int> q;
		q.push(id);
		while(sz(q)){
			int u = q.front();
			q.pop();
			vis[u] = 1;
			fore(i,0,sz(G[u])){
				int v = G[u][i];
				if(vis[v] == -1){
					q.push(v);
					vis[v] = 1;
				}
			}
			if(sz(G[u]) == 1 && u != id)
					aux.pb(u);
		}
		printf("%d\n",sz(aux));
		for(auto i : aux)
			printf("%d %d\n",id,i);
	}
	return 0;
}
    
