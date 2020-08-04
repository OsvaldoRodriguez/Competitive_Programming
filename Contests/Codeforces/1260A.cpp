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
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
const ll MAX = (1 << 30);
int main(){
	//fast;
	int n;
	ll a,b;
	cin >> n;
	while(n--){
		cin >> a >> b;
		if(b % a == 0)
			cout << (b / a) * (b / a) * a << '\n';
		else{
			ll ans = 0;
			ll tmp = a - (b % a);
			ans += tmp * (b / a) * (b / a);
			tmp = abs(tmp - a);
			ans += tmp * (b / a + 1) * (b / a + 1);
			cout << ans << '\n';
		}		
	}
	return 0;	
}
