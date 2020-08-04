#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ii pair<int,int>
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define allr(x) (x).rbegin(),(x).rend()
#define fore(i,a,b) for(int i = a;i < b; i+= 1)
#define forr(i,a) for(int i = a; i >= 0; i--)
#define fori(i,m) for(auto i = m.begin(); i != m.end(); i++) 
#define cls(s) s.clear()
#define sz(s) int(s.size())
#define	mst(a,car) memset(a,car,sizeof (a))
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
const ll INF = LONG_LONG_MAX;
ll f(ll x){return x * (x + 1) >> 1;}
bool v[26];
int main(){
	//fast;
	int t;
	string s;
	cin >> t;
	while(t--){
		int l,r,u,d;
		l = r = u = d = 0;
		cin >> s;
		fore(i,0,sz(s)){
			if(s[i] == 'U')
				u++;
			if(s[i] == 'D')
				d++;
			if(s[i] == 'L')
				l++;
			if(s[i] == 'R')
				r++;
		}
		int tmp = 0;
		int aux = min(l,r);
		l = r = aux;
		aux = min(u,d);
		u = d = aux;
		tmp = l + r + u + d;
		if(l == 0  && u > 0){
			cout << "2\nUD\n";
			continue;
		}else if(u == 0 && l > 0){
			cout << "2\nLR\n";
			continue;
		}
		if(tmp == 0)
			cout << "0\n\n";
		else{
			cout << tmp << '\n';
			fore(i,0,l)
				cout << 'L';
			fore(i,0,u)
				cout << 'U';
			fore(i,0,r)
				cout << 'R';
			fore(i,0,d)
				cout << 'D';
			cout << "\n";
		}
	}
	return 0;	
}
