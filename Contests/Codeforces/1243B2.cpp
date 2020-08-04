#include <bits/stdc++.h>
#define endl '\n' 
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ii pair<int,int>
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
const int N = 35 + 5;
const int mod = 1e9 + 7;
const ll MAX = INT_MAX;
vector<ii> ans;
int v[26];
int main(){
	fast;
	int test,n;
	cin >> test;
	string s,t;
	while(test--){
		ans.clear();
		cin >> n >> s >> t;
		memset(v,0,sizeof v);
		bool flag = 1;
		for(int i = 0; i < n; i++){
			v[s[i] - 'a']++;
			v[t[i] - 'a']++;
		}
		for(int i : v)
			if((i&1))
				flag = 0;
		if(flag){
			for(int i = 0; i < n; i++){
				if(s[i] != t[i]){
					for(int j = i + 1; j < n; j++){
						if(s[i] == s[j]){
							ans.pb(ii(j + 1,i + 1));
							swap(s[j],t[i]);
							break;
						}
						else if(s[i] == t[j]){
							ans.pb(ii(j + 1,j + 1));
							swap(t[j],s[j]);
							ans.pb(ii(j + 1,i + 1));
							swap(s[j],t[i]);
							break;
						}
					}
				}
			}
			cout << "Yes\n";
			cout << ans.size() << "\n";
			for(auto i : ans)
				cout << i.F << " " << i.S << "\n";
		}else cout << "No\n";
	}
	return 0;
	
}
