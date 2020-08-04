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
const int N = 35 + 5;
const int mod = 1e9 + 7;
const ll MAX = INT_MAX;
vector<ii> ans;
int v[26];
int main(){
	fast;
	int t;
	int n, m;
	cin >> t;
	while(t--){
		cin >> n >> m;
		if(__gcd(n,m) == 1)
			cout << "Finite\n";
		else cout << "Infinite\n";
	}
	return 0;
	
}
