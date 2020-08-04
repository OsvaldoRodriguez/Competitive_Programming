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
const int N = 1 * 1e5 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
int main(){
	fast;
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int cnt = 0;
		fore(i,0,sz(s)){
			if(s[i] == 'R')
				cnt++;
		}
		if(cnt == sz(s))
			cout << "1\n";
		else if(cnt == 0)
			cout << sz(s) + 1 << '\n';
		else{
			vector<int> aux;
			fore(i,0,sz(s)){
				if(s[i] == 'R')
					aux.pb(i + 1);
			}
			
			int ans = aux[0];
			for(int i = 1; i < sz(aux); i++)
				ans = max(aux[i] - aux[i - 1],ans);
			ans = max(ans,sz(s) - aux[sz(aux) - 1] + 1);

			if(ans == 0)
				ans = max(aux[0],sz(s) - aux[0] + 1);
			cout << ans << '\n';

		}
	}
	return 0;
}
    
