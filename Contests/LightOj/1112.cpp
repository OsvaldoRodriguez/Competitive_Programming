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
int fun(int x,int y){
	return x + y;
}
void build(int node,int l,int r){
	if(l == r){
		scanf("%d",&ST[node]);
		return ;
	}
	else{
		int m = (l + r) >> 1;
		build(node * 2,l,m);
		build(node * 2 + 1,m + 1,r);
		ST[node] = fun(ST[node * 2],ST[node * 2 + 1]);
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
	return fun(query(node * 2,l,m,i,j),query(node * 2 + 1,m + 1,r,i,j));
}
void update(int node,int l,int r,int i,int val,int ope){
	if(l == r){
		if(ope == 1){
			printf("%d\n",ST[node]);
			ST[node] = val;
		}else
			ST[node] += val;
		return;
	}else{
		int m = (l + r) >> 1;
		if(i <= m)
			update(node * 2,l,m,i,val,ope);
		else
			update(node * 2 + 1,m + 1,r,i,val,ope);
		ST[node] = fun(ST[node * 2],ST[node * 2 + 1]);

	}
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
			int x,y,z;
			scanf("%d %d",&x, &y);
			if(x == 1)
				update(1,0,n - 1,y,0,1);
			else{
				scanf("%d",&z);
				if(x == 2)
					update(1,0,n - 1,y,z,0);
				else
					printf("%d\n",query(1,0,n - 1,y,z));
			}
			
		}
	}
	return 0;
}
