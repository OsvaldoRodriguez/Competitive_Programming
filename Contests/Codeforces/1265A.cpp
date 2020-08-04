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
const int N = 2 * 1e5 + 50;
const int mod = 1e9 + 7;
const ll MAX = (1 << 30);
bool cmp(const string &s){
	fore(i,1,sz(s))
		if(s[i] == s[i - 1] or s[i] == '?')
			return 0;
	return 1;
}
int main(){
	fast;
	int t;
	string s;
	cin >> t;
	while(t--){
		cin >> s;
		fore(i,0,sz(s)){
			if(s[i] == '?'){
				char l = '@';
				char r = '@';
				if(i != 0)
					l = s[i - 1];
				if(i < sz(s))
					r = s[i + 1];
				for(auto j = 'a'; j <= 'c'; ++j)
					if(r != j && l != j){
						s[i] = j;
						break;
					}  
			}
		}
		if(cmp(s))
			cout << s << "\n";
		else
			cout << "-1\n";
	}
	return 0;	
}
