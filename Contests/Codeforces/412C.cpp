#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
int v[26][N];
int main(){
	int n;
	cin >> n;
	string s;
	for(int i = 0; i < n; ++i){
		cin >> s;
		for(int j = 0; j < s.size(); j++)
			if(s[j] != '?')
				v[s[j] - 'a'][j]++;
	}
	/*for(int i = 0; i < 26; i++){
			for(int j = 0; j < s.size(); j++)
				cout << v[i][j] << " ";
			cout << endl;
	}*/
	string ans = "";
	int pos = 0;
	for(int i  = 0; i < s.size(); ++i){
		int may = 0;
		for(int j = 0; j < 26; j++){
			if(may < v[j][i]){
				may = v[j][i];
				pos = j;
			}
		}
		int a1 = 0;
		bool flag = 0;
		char x = '*';
		for(int j = 0;j < 26; j++){
			if(may == v[j][i] or (v[j][i] != may && v[j][i]))
				a1++,flag = 1;
			if(flag && !v[j][i]){
				if(a1 <= 1)
					x = j;
				flag = 0;
			}
		}
		if(a1 == 1)
			ans += char(pos) + 'a';
		else{
			if(may != 0)
				ans += '?';
			else
				ans += char(x) + 'a';
		} 
	}
	cout << ans << '\n';	
	return 0;
}
