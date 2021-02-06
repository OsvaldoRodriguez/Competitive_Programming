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
int ST[4 * N + 5],ST1[4 * N + 5];
int fun(int x,int y){
	if(x < y)
		return x;
	return y;
}
int fun1(int x,int y){
	if(x > y)
		return x;
	return y;
}
void build(int node,int l,int r){
	if(l == r){
		scanf("%d",&ST[node]);
		ST1[node] = ST[node];
		return ;
	}
	else{
		int m = (l + r) >> 1;
		build(node * 2,l,m);
		build(node * 2 + 1,m + 1,r);
		ST[node] = fun(ST[node * 2],ST[node * 2 + 1]);
		ST1[node] = fun1(ST1[node * 2],ST1[node * 2 + 1]);
	}
}
int querym(int node,int l,int r,int i,int j){
	if(l >= i && r <= j)
		return ST[node];
	int m = (l + r) >> 1;
	if(j <= m)
		return querym(node * 2,l,m,i,j);
	if(i > m)
		return querym(node * 2 + 1,m + 1,r,i,j);
	return fun(querym(node * 2,l,m,i,j),querym(node * 2 + 1,m + 1,r,i,j));
}
int queryM(int node,int l,int r,int i,int j){
	if(l >= i && r <= j)
		return ST1[node];
	int m = (l + r) >> 1;
	if(j <= m)
		return queryM(node * 2,l,m,i,j);
	if(i > m)
		return queryM(node * 2 + 1,m + 1,r,i,j);
	return fun1(queryM(node * 2,l,m,i,j),queryM(node * 2 + 1,m + 1,r,i,j));
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
		int ans = 0;
		fore(i,0,n - q + 1)
			ans = max(ans,queryM(1,0,n - 1,i,i + q - 1) - querym(1,0,n - 1,i,i + q - 1));
			
		printf("Case %d: %d\n",test++,ans);
		}
	return 0;
}
