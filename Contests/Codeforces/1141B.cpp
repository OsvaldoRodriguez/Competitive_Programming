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
const ll mod = 10;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
int v[2 * N + 5];
int main(){
	fast;
	int n;
	cin >> n;
	fore(i,0,n){
		cin >> v[i];
		v[i + n] = v[i];
	}
	n *= 2;
	int ans = 0;
	int tmp = 0;
	fore(i,0,n){
		if(v[i] == 1)
			tmp++;
		else{
			ans = max(ans,tmp);
			tmp = 0;
		}
	}
	cout << ans << '\n';
	return 0;
}
