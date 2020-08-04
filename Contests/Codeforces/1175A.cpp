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
	int t;
	ll n,k;
	cin >> t;
	while(t--){
		ll ans = 0;
		cin >> n >> k;
		
			while(n){
				if(n % k == 0)
					n /= k,ans++;
				else{
					ans += n % k;
					n -= n % k;
				}
			}
			cout << ans << '\n';
		
	}
	return 0;	
}
