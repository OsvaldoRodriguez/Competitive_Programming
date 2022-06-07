#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 100;
typedef  long long ll;
int v[N];
void sieve(){
	for(int i = 1; i < N; i++)
		v[i] = i;

	for(int i = 2; i * i <  N; i++)
		if(v[i] == i)
			for(int j = i * i; j < N; j += i)
				v[j] = i;

}
void solve(){
	int n;
	cin >> n;
	sieve();
	while(n--){
		int x;
		cin >> x;
		map<int, int> m;
		while(v[x] != 1){
			m[v[x]]++;
			x /= v[x];
		}
		ll ans = 1;
		for(auto i : m)
			ans *= (i.second + 1);

		cout << ans << '\n';
	}	
}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    for(int i = 0; i < t; i++)
        solve();
    return 0;
}
