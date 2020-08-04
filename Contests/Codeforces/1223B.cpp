#include <bits/stdc++.h>
#define endl '\n' 
using namespace std;
typedef long long ll;
const int N = 104;
int v[26],w[26];
int main(){
	int n;
	string a,b;
	cin >> n;
	while(n--){
		cin >> a >> b;
		memset(v,0,sizeof v);
		memset(w,0,sizeof w);
		for(int i = 0; i < a.size(); i++)
			v[a[i] - 'a'] = 1;
		for(int i = 0; i < b.size(); i++)
			w[b[i] - 'a'] = 1;
		int ans = 0;
		for(int i = 0; i < 26; i++)
			ans |= v[i] & w[i];
		if(ans)
			cout << "YES\n";
		else 
			cout << "NO\n";
	}
	return 0;
}
