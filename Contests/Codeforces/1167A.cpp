#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ii pair<int,int>
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define fore(i,a,b) for(int i = a;i < b; i++)
using namespace std;
typedef long long ll;
const int N = 2 * 1e5 + 5;
const int mod = 1e9 + 7;
const ll MAX = INT_MAX;
int v[N];
int main(){
	fast;
	int t,n;
	string s;
	cin >> t;
	while(t--){
		cin >> n >> s;
		if(n >= 11){
			reverse(all(s));
			bool flag = 0;
			for(int i = 10; i < n; i++)
				if(s[i] == '8'){
					flag = 1;
					break;
				}
			if(flag)cout << "YES\n";
			else cout << "NO\n";
		}else cout << "NO\n";
	}
	return 0;	
}
