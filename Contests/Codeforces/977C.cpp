#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ii pair<long long,long long>
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define fore(i,a,b,inc) for(int i = a;i < b; i+= inc)
#define forr(i,a) for(int i = a; i >= 0; i--)
using namespace std;
typedef long long ll;
const int N = 2 * 1e5 + 5;
const int mod = 1e9 + 7;
const ll MAX = (1LL << 32) - 1;
int v[N];
int main(){
	fast;
	int n,k;
	cin >> n >> k;
	fore(i,0,n,1)
		cin >> v[i];
	sort(v,v + n);
	int ans;
	if(k == 0){
		ans = v[0] - 1;
		if(ans == 0)
			cout << "-1\n";
		else
			cout << ans << '\n';
		return 0;
	}
	ans = v[k - 1];
	if((k != n) && ans == v[k])
		ans = - 1;
	cout << ans << '\n';	
	return 0;	
}
