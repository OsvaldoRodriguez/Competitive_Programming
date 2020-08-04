#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ii pair<int,int>
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define fore(i,a,b,inc) for(int i = a;i < b; i+= inc)
#define forr(i,a) for(int i = a; i >= 0; i--)
using namespace std;
typedef long long ll;
const int N = 1e3 + 5;
const int mod = 1e9 + 7;
const ll MAX = (1LL << 32) - 1;
char f1(char x){
	if(x == 'R')
		return 'G';
	if(x == 'B')
		return 'G';
	if(x == 'G')
		return 'R';
}
char f(char x, char diff){
	if(diff == '@')
		return f1(x);
	if(x == 'B' && diff == 'R')
		return 'G';
	if(x == 'B' && diff == 'G')
		return 'R';

	if(x == 'G' && diff == 'R')
		return 'B';
	if(x == 'G' && diff == 'B')
		return 'R';

	if(x == 'R' && diff == 'B')
		return 'G';
	if(x == 'R' && diff == 'G')
		return 'B';
	
}
int main(){
	fast;
	int n;
	string s;
	cin >> n >> s;
	s += '@';
	int ans = 0;
	n++;
	fore(i,0,n,1){
		int j = i;
		int cont = 0;
		bool flag = 0;
		while(j < n && s[j] == s[j + 1])
			j++,cont++,flag = 1;
		if(flag)cont++;
		if((cont & 1) && cont > 1){
			char aux = f1(s[i]);
			fore(k,i + 1,j + 1,2)
				s[k] = aux,ans++;
		}else if(cont > 0){
			char aux = f(s[i],s[j + 1]);
			fore(k,i + 1,j + 1,2)
				s[k] = aux,ans++;
		}
		if(i != j)
			i = j - 1;

	}
		cout << ans << "\n" ;
		fore(i,0,n - 1,1)
		cout << s[i];

	return 0;	
}
