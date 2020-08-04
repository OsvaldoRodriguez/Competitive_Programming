#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ii pair<long long,long long>
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define fore(i,a,b) for(int i = a;i < b; i+= 1)
#define forr(i,a) for(int i = a; i >= 0; i--)
using namespace std;
typedef long long ll;
const int N = 2 * 1e5 + 5;
const int mod = 1e9 + 7;
const ll MAX = (1LL << 32) - 1;
vector<int> ans;
int main(){
	fast;
	int n,t,x;
	cin >> t;
	while(t--){
		ans.clear();
		cin >> n;
		set<int> s,nm;
		fore(i,1,n + 1)
			nm.insert(i);
		fore(i,0,n){
			cin >> x;
			if(!s.count(x)){
				ans.pb(x);
				s.insert(x);
				nm.erase(x);
			}else{
				if(x >= *nm.begin())
				ans.pb(*nm.begin()),
				nm.erase(*nm.begin());
			}

		}
		if(ans.size() == n){
			for(auto i : ans)
				cout << i << ' ';
			cout << "\n";
		}
		else cout << "-1\n";
	}
	return 0;	
}
