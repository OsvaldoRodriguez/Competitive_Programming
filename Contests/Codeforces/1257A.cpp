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
	int t,n,x,a,b;
	cin >> t;
	while(t--){
		cin >> n >> x >> a >> b;
		if(a > b)
			swap(a,b);
		int aux1 = max(a - x,1);
		int diff = 0;
		if(aux1 == a)
			diff = x;
		else
			diff = abs(x - abs(aux1 - a));
		int aux2 = min(n,b + diff);
		int ans = abs(aux1 - aux2);
		cout << ans << '\n';
	}
	return 0;	
}
