#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ii pair<long long,long long>
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define fore(i,a,b,inc) for(int i = a;i < b; i+= inc)
#define forr(i,a) for(int i = a; i >= 0; i--)
using namespace std;
typedef long long ll;
const int N = 2 * 1e5 + 5;
const int mod = 1e9 + 7;
const ll MAX = (1LL << 32) - 1;
int main(){
	fast;
	int n,x,y,mx,mn,t;
	cin >> t;
	while(t--){
		cin >> n >> x >> y;
		mx = x;
		mn = y;
		n--;
		while(n--){
			cin >> x >> y;
			mx = max(mx,x);
			mn = min(mn,y);
		}
		if(mx >= mn)
			cout << mx - mn << '\n';
		else
			cout << "0\n";
	}
	return 0;	
}
