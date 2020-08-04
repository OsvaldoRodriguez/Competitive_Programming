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
const ll MAX = 1e0 + 5;
int v[26],w[26];
int main(){
	fast;
	int test,n;
	string s,t;
	cin >> test;
	while(test--){
		memset(v,0,sizeof v);
		memset(w,0,sizeof w);
		cin >> n >> s >> t;
		int tmp = 0;
		for(int i = 0; i < n; i++){
			if(s[i] != t[i]){
				v[s[i] - 'a']++;
				w[t[i] - 'a']++;
				tmp++;
			}
		}
		if(tmp == 0)
			cout << "Yes\n";
		else if(tmp > 2)
			cout << "No\n";
		else{
			bool flag = 0,flag1 = 0;
			for(int i = 0; i < 26; i++){
				if(v[i] && !(v[i] & 1))
					flag = 1;
				if(w[i] && !(w[i] & 1))
					flag1 = 1;
			}
			flag &= flag1;
			if(flag)
				cout << "Yes\n";
			else
				cout << "No\n";
		}

	}
	return 0;
}
