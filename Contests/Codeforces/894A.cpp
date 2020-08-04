#include <bits/stdc++.h>
#define endl '\n' 
using namespace std;
typedef long long ll;
const int N =  1e5 + 5;
int v[N];
int v1[N];
int main(){
	string s;
	while(cin >> s){
		auto t = s.size();
		int ans = 0;
		v[0] = (s[0] == 'Q');
		for(int i = 1; i < t; i++)
			v[i] = v[i - 1] + (s[i] == 'Q');
		
		v1[t - 1] = (s[t - 1] == 'Q');
		for(int i = t - 2; i >=  0; i--)
			v1[i] = v1[i + 1] + (s[i] == 'Q');
		
		for(int i = 0; i < t - 1; i++){
			if(i != 0 && s[i] == 'A')
				ans += v[i] * v1[i];
		}
		cout << ans << '\n';
	}
	return 0;
}
