#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ii pair<int,int>
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define fore(i,a,b) for(int i = a;i < b; i++)
using namespace std;
typedef long long ll;
const int N = 5 * 1e5 + 5;
const int mod = 1e9 + 7;
const ll MAX = INT_MAX;
int p[N],c[N];
int finds(int a){
	if(a == p[a])
		return a;
	return p[a] = finds(p[a]);
}
int main(){
	fast;
	int n,m,x,y,t;
	for(int i = 0; i < N; i++)
		p[i] = i, c[i] = 1;
	cin >> n >> m;
	while(m--){
		cin >> t;
		if(t)
			cin >> x;
		else continue;
		t--;
		while(t--){
			cin >> y;
			int px = finds(x);
			int py = finds(y);
			if(px != py){
				p[px] = py;
				c[py] += c[px];
			}
			x = y;
		}
	}
	for(int i = 1; i <= n; i++){
		cout << c[finds(i)] << ' ';
	}

	return 0;	
}
