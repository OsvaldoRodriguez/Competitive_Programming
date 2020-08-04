#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ii pair<int,int>
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
const int N = 1e3 + 5;
const int mod = 1e9 + 7;
const ll MAX = INT_MAX;
ii v[N];
vector<ii> ans;
int main(){
	fast;
	int t,n,m,x;
	cin >> t;
	while(t--){
		ans.clear();
		cin >> n >> m;
		for(int i = 0; i < n; i++){
			cin >> x;
			v[i] = ii(x,i);
		}
		if(m < n or n == 2){
			cout << "-1\n";
			continue;
		}
		ll sum = 0;
		sort(v , v + n);
		m--;
		sum += v[0].F + v[n - 1].F;
		ans.pb(ii(v[0].S + 1,v[n - 1].S + 1));
		for(int i = 0; i < n - 1 && m; i++){
			sum += v[i].F + v[i + 1].F;
			ans.pb(ii(v[i].S + 1,v[i + 1].S + 1));
			m--;
		}
		cout << sum << '\n';
		for(auto i : ans)
			cout << i.F << " " << i.S << '\n';
		
	}
	return 0;	
}
