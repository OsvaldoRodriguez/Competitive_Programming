#include <bits/stdc++.h>
#define endl '\n' 
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
int B = 33;
int mod = 1e9 + 7; 
ll pot[N];
map<ll,int> m;
ll hashing(const string& s){
	ll ans = 0;
	for(auto i = 0; i < s.size(); i++){
		ans = (ans % mod + ((s[i] - 'a' + 1) % mod * pot[i] ) % mod) %mod;
	}
	return ans;
}
int main(){
	pot[0] = 1;
	for(int i = 1; i < N; i++)
		pot[i] = (pot[i - 1] % mod * B % mod) % mod;
	int n;
	cin >> n;
	string s;
	for(int i = 0; i < n; i++){
		cin >> s;
		ll hash = hashing(s);
		m[hash]++;
		if(m[hash] > 1)
			cout << s << m[hash] - 1 << '\n';
		else
			cout << "OK\n";

	}
	return 0;
}
