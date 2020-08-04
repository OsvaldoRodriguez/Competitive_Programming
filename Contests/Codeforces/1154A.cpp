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
int main(){
	fast;
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	int ans = max(a,max(b,max(c,d)));
	if(ans != a)
		cout << ans - a << ' ';
	if(ans != b)
		cout << ans - b << ' ';
	if(ans != c)
		cout << ans - c << ' ';
	if(ans != d)
		cout << ans - d << ' ';
	return 0;
	
} 
