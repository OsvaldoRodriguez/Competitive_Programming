#include <bits/stdc++.h>
#define endl '\n' 
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
int v[N];
map<int,int> m;
int main(){
	fast;
	int t,n,k,d;
	cin >> t;
	while(t--){
		m.clear();
		cin >> n >> k >> d;
		for(int i = 0; i < n; i++)
			cin >> v[i];
		for(int i = 0; i < d; i++)
			m[v[i]]++;
		int j = 0;
		int ans = m.size();
		for(int i = d; i < n; i++){
			if(m[v[j]] == 1)
				m.erase(v[j]);
			else
				m[v[j]]--;
			m[v[i]]++;
			ans = min(ans,int(m.size()));
			j++;
		}
		cout << ans << '\n';
	}
	return 0;
	
}
