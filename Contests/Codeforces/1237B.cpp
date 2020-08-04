#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ii pair<int,int>
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
const ll MAX = INT_MAX;
int v[N],w[N];
int main(){
	fast;
	int n,x;
	cin >> n;
	for(int i = n - 1; i >= 0; i--){
		cin >> x;
		v[x] = i;
	}
	for(int i = n - 1; i >= 0; i--){
		cin >> x;
		w[i] = v[x];
	}
	int ans = 0;
	int tmp = w[0];
	for(int i = 1; i < n; i++){
		if(tmp > w[i])
			ans++;
		tmp = max(tmp,w[i]);
	}
	cout << ans << "\n";
	return 0;	
}
