#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ii pair<int,int>
#define F first
#define S second
#define pb push_back
#define pf push_front
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define fore(i,a,b) for(int i = a;i < b; i+= 1)
#define forr(i,a) for(int i = a; i >= 0; i--)
#define fori(i,m) for(auto i = m.begin(); i != m.end(); i++) 
#define sz(s) int(s.size())
#define cls(a,car) memset(a,car,sizeof (a))
using namespace std;
typedef long long ll;
const int N = 1 * 1e5 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
ll f(ll a){return a * (a + 1) / 2;}
int main(){
	fast;
	int t;
	ll n,k;
	cin >> t;
	while(t--){
		cin >> n >> k;
		if(k == 1){
			fore(i,0,n - 2)
				cout << 'a';
			cout << "bb\n";
		}else{
			k--;
			ll a = -1,b = 2e9, mid;
			while(b - a > 1){
				mid = (a + b) >> 1;
				if(f(mid) <= k)
					a = mid;
				else
					b = mid;
			}
			int pos_ini = n - 2 - a;
			int pos_end = n - 1 - (k - f(a));
			ll aux = n - 1 - (k - f(a));
 			fore(i,0,n){
 				if(pos_end == i or pos_ini == i)
 					cout << 'b';
 				else
 					cout << 'a';
 			}
 			cout << '\n';
		}
	}
	return 0;
}
    
