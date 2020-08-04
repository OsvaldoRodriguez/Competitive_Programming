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
const int N = 1e3 + 5;
const int mod = 1e9 + 7;
const ll MAX = (1LL << 32) - 1;
vector<ii> v;
bool cmp(ii a,ii b){
	return (a.F - a.S) > (b.F - b.S);
}
int main(){
	fast;
	int n,m;
	cin >> n >> m;
	ll x,y,sum = 0;
	while(n--){
		cin >> x >> y;
		v.pb(ii(x,y));
		sum += x;
	}
	sort(all(v),cmp);
	int ans = 0;
	int i = 0;
	while(sum > m && i < v.size()){
		ll aux = v[i].F - v[i].S;
		sum -= aux;
		ans++;
		i++;
	}
	if(sum > m)
		cout << "-1\n";
	else
	cout << ans << '\n';
	return 0;	
}
