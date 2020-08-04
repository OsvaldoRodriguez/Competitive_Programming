#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ii pair<int,int>
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define fore(i,a,b) for(int i = a;i < b; i+= 1)
#define forr(i,a) for(int i = a; i >= 0; i--)
#define fori(i,m) for(auto i = m.begin(); i != m.end(); i++)
using namespace std;
typedef long long ll;
const int N = 2 * 1e5 + 5;
const int mod = 1e9 + 7;
const ll MAX = (1LL << 32) - 1;
int main(){
	fast;
	int n,x;
	cin >> n;
	vector<int> ans;
	set<int> s;
	fore(i,0,n){
		cin >> x;
		ans.pb(x);
	} 
	if(ans.size() <= 2){
		cout << "0\n";
		return 0;
	}
	sort(all(ans));

	n = ans.size(); 
	cout << min(ans[n - 2] - ans[0], ans[n - 1] - ans[1]);
	return 0;	
}
