#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 1e5 + 5;
int v[N];
vector<ll> w;
map<int,int> m;
int main(){
	ll p = 2;
	while(p <= 3100000000){
		w.push_back(p);
		p <<= 1;
	}
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> v[i];
		m[v[i]]++;
	}
	ll ans = 0;
	for(int i = 0; i < n; i++){
		int k = v[i];
		for(int j = 0;j < w.size(); j++){
			int x = w[j] - k;
			if(m[x]){
				if(x == k)
					ans += (m[x] - 1);
				else
					ans += m[x];
			}
		}
	}
	cout << ans/2 << "\n";
	return 0;
}
