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
const int N = 1e2 + 5;
const int mod = 1e9 + 7;
const int MAX = INT_MAX;
int cd = 0;
int main(){
	fast;
	int t;
	cin >> t;
	while(t--){
		int n,x;
		cin >> n;
		int v[N];
		memset(v,0,sizeof v);
		for(int i = 0; i < n; i++){
			cin >> x;
			v[x] = 1;
		}
		bool flag = 0;
		int ans = 1,tmp;
		for(int i = 1; i < 100; i++){
			if(v[i] && v[i + 1]){
				flag = 1;
				break;
			}
		}
		if(flag)
			ans++;
		cout << ans << '\n';
	}
    return 0;
}
