#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ii pair<int,int>
#define F first
#define S second
#define pb push_back
#define pf push_front
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define fore(i,a,b) for(int i = a;i < b; i+= 1)
#define forr(i,a) for(int i = a; i >= 0; i--)
#define fori(i,m) for(auto i = m.begin(); i != m.end(); i++) 
#define sz(s) int(s.size())
#define cls(a,car) memset(a,car,sizeof (a))
using namespace std;
typedef long long ll;
const int N = 2 * 1e5 + 5;
const ll mod = 998244353;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
int main(){ 
	string s;
	cin >> s;
	bool flag = 1;
	fore(i,0,sz(s)){
		if(s[i] != s[sz(s) - i - 1]){
			flag = 0;
			break;
		}
	}
	if(flag){
		char car = s[0];
		int cnt = 1;
		fore(i,1,sz(s))
			if(car == s[i])
				cnt++;
		if(cnt == sz(s))
			cout << "0\n";
		else
			cout << sz(s) - 1 << '\n';
	}else
		cout << sz(s) << '\n';
	return 0;
}
    
