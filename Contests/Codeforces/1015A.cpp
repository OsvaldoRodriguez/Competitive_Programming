#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ii pair<int,int>
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define fore(i,a,b,inc) for(int i = a;i < b; i+= inc)
#define forr(i,a) for(int i = a; i >= 0; i--)
using namespace std;
typedef long long ll;
const int N = 1e3 + 5;
const int mod = 1e9 + 7;
const ll MAX = (1LL << 32) - 1;
int main(){
	fast;
	int n,m,x,y;
	cin >> n >> m;
	int v[m + 1];
	memset(v,0,sizeof v);
	fore(i,0,n,1){
		cin >> x >> y;
		fore(j,x,y + 1,1)
			v[j] = 1;
	}
	int ans = 0;
	vector<int> x1;
	fore(i,1,m + 1,1){
		if(v[i] == 0)
			x1.pb(i);
	}
	cout << x1.size() << "\n";
	for(auto i : x1)
		cout << i << " ";
	return 0;	
}
