#include <bits/stdc++.h>
#define endl '\n' 
using namespace std;
typedef long long ll;
const int N = 104;
int main(){
	int t;
	cin >> t;
	ll n,m;
	while(t--){
		cin >> n >> m;
		if(n - 1 == m)
			cout << "NO\n";
		else 
			cout << "YES\n";
	}
	return 0;
}
