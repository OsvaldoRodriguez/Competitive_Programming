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
int v[N];
map<int,int> m,pos;
set<int> s;
int main(){
	fast;
	int t,n;
	cin >> t;
	while(t--){
		m.clear();
		cin >> n;
		pos.clear();
		for(int i = 0; i < n; i++){
			cin >> v[i];
		}
		if(n == 1){
			cout << "-1\n";
			continue;
		}
		int i = 0, j = 0,ans = MAX;
		while(i <= j && j < n){
			m[v[j]]++;
			if(m[v[j]] > 1){
				m[v[j]]--;
				ans = min(ans,j - pos[v[j]] + 1);
				i++;
				pos[v[j]] = j;
			}else
				pos[v[j]] = j;
			j++;
			
		}
		if(ans == MAX)
			cout << "-1\n";
		else
		cout << ans << '\n';
	}
	return 0;	
}
