#include <bits/stdc++.h>
#define endl '\n' 
using namespace std;
typedef long long ll;
const int N =  5;
int v[N];
int main(){
	string s;
	int k,n;
	cin >> n >> k >> s;
	if(n == 1 && k > 0){
		cout << "0\n";
		return 0;
	}
	if(s[0] != '1'){
		int i = 1;
		if(k > 0)
			k--,s[0] = '1';
		while(i < n && s[i] == '0')
			i++;
		while(i < n && k){
			if(s[i] != '0'){
				s[i] = '0';
				k--;
			}
			i++;
		}
	}
	else{
		int i = 1;
		while(i < n && s[i] == '0')
			i++;
		while(i < n && k){
			if(s[i] != '0'){
				s[i] = '0';
				k--;
			}
			i++;
		}
	}
	cout << s << '\n';
	return 0;
}
