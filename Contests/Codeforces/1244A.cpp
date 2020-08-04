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
	int a,b,c,d,k;
	int t;
	cin >> t;
	while(t--){
		cin >> a >> b >> c >> d >> k;
		int a1 = (c + a - 1) / c;
		int b1 = (b + d - 1) / d;
		if(a1 + b1 <= k)
			cout << a1 << " " << b1 << "\n";
		else cout << "-1\n";
	}
	return 0;
	
}
