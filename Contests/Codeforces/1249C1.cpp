#include <bits/stdc++.h>
#define endl '\n' 
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ii pair<int,int>
#define F first
#define S second
#define inf (1<<30)
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
const int N = 35 + 5;
const int mod = 1e9 + 7;
const ll MAX = 1350851717672992089;
ll v[N];
int occ[N];
vector<ll> ans;
int main(){
	//fast;
	v[0] = 1;
	for(int i = 1; i < N; i++)
		v[i] = 3LL * v[i - 1];
	int t;
	ll n;
	cin >> t;
	while(t--){
		memset(occ,0,sizeof occ);
		int i = 39;
		cin >> n;
		ll m = n;
		while(i >= 0){
			if(n >= v[i]){
				n -= v[i];
				occ[i] = 1;
			}
			i--;
		}
		if(!n)cout << m << "\n";
		else{
			int j = 0;
			for(int i = 0; i < N; i++)
				if(!occ[i]){
					j = i;
					break;
				}
			int i = 0;
			n = m - n;
			ll ant  = 0;
			while(1){
				if(n < m){
					n += v[j];
					occ[j] = 1;
					j++;
					while(occ[j])
						j++;
				}else{
					ant = n;
					n -= v[i];
					if(n < m){
						n = ant;
						break;
					}
					occ[i] = 0;
					i++;
				}
			}
			cout << n << '\n';
		}
	}
	return 0;
}
