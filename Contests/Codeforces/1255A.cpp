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
map<int,int> m;
int A[] = {-5,-2,-1};
int B[] = {5,2,1};

int main(){
	fast;
	int t;
	cin >> t;
	int a,b;
	while(t--){
		int ans = 0;
		cin >> a >> b;
		a = abs(a - b);
		ans = a / 5;
		a %= 5;
		if(a == 4 or a == 3)
			ans += 2;
		if(a == 2 or a == 1)
			ans++;

		cout << ans << '\n';
	}
	return 0;	
}
