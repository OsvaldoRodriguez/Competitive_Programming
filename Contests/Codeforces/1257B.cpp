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
int main(){
	fast;
	int t;
	ll a,b;
	cin >> t;
	while(t--){
		cin >> a >> b;
		bool flag = 0;
		set<ll> s;
		s.insert(a);
		if(a == b or a > b){
			cout << "YES\n";continue;
		}
		while(a != b){
			if(!(a & 1))
				a = (3 * a) >> 1;
			else if(a > 1)
				a--;

			if(a == b or a > b){
				flag = 1;
				break;
			}
			if(s.count(a))
				break;
			else s.insert(a);
			//cout << a << endl;
		}
		if(flag)
			cout << "YES\n";
		else cout << "NO\n";

	}
	return 0;	
}
