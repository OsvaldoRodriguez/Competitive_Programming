#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ii pair<int,int>
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
const int N = 2 * 1e5 + 5;
const int mod = 1e9 + 7;
const ll MAX = INT_MAX;
ll v[N];
int main(){
	fast;
	int n,m;
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> v[i];
	sort(v,v + n);
	for(int i = 0; i < n - m + 1; i++){
		v[i + m] += v[i];
	}
	ll ans = 0;
	for(int i = 0; i < n; i++){
		ans += v[i];
		cout << ans << " ";
	}
	return 0;	
}
