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
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
const int MAX = INT_MAX;
int cd = 0;
int main(){
	fast;
	int a,b,n,s,t;
	cin >> t;
	while(t--){
	cin >> a >> b >> n >> s;
	if(min(s/n,a) * n + b >= s)
		cout << "YES\n";
	else cout << "NO\n";
	}
    return 0;
}
