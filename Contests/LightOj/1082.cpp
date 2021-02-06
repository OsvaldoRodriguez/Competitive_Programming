#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ii pair<int,int>
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define allr(x) (x).rbegin(),(x).rend()
#define fore(i,a,b) for(int i = a;i < b; i+= 1)
#define forr(i,a) for(int i = a; i >= 0; i--)
#define fori(i,m) for(auto i = m.begin(); i != m.end(); i++) 
#define sz(s) int(s.size())
#define	cls(a,car) memset(a,car,sizeof (a))
using namespace std;
typedef long long ll;
const int N = 1 * 1e5 + 5;
const int mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
int ST[4 * N + 5];
void build(int node,int l,int r){
	if(l == r){
		scanf("%d",&ST[node]);
		return ;
	}
	else{
		int m = (l + r) >> 1;
		build(node * 2,l,m);
		build(node * 2 + 1,m + 1,r);
		ST[node] = min(ST[node * 2],ST[node * 2 + 1]);
	}
}
int query(int node,int l,int r,int i,int j){
	if(l >= i && r <= j)
		return ST[node];
	int m = (l + r) >> 1;
	if(j <= m)
		return query(node * 2,l,m,i,j);
	if(i > m)
		return query(node * 2 + 1,m + 1,r,i,j);
	return min(query(node * 2,l,m,i,j),query(node * 2 + 1,m + 1,r,i,j));
}
int main(){
	int t;
	int test = 1;
	scanf("%d",&t);
	while(t--){
		int  n,q;
		scanf("%d %d",&n,&q);
		build(1,0,n - 1);
		printf("Case %d:\n",test++ );
		while(q--){
			int x,y;
			scanf("%d %d",&x,&y);
			x--;y--;
			printf("%d\n",query(1,0,n - 1,x,y) );
		}
	}
	return 0;
}
