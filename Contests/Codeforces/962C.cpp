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
const ll mod = 10;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
int main(){
	fast;
	string s;
	unordered_set<string> st;
	int mn = 1 << 30;
	for(ll i = 1; i < 50000; i++)
		st.insert(to_string(i * i));
	
	cin >> s;
	for(int i = 0; i < (1 << sz(s)); i++){
		string aux = "";
		for(int j = 0; j < sz(s); j++){
			if(i & (1 << j))
				aux += s[j];
		}
		int k = 0;
		while(aux[k] == '0')
			k++;
		string aaa = "";
		for(; k <sz(aux); k++)
			aaa += aux[k];
		int aux_1 = sz(s) - sz(aaa);
		if(aux_1 < mn && st.count(aaa) && aux != "")
			mn = aux_1;
	}
	if(mn == 1 << 30)
		cout << -1 << '\n';
	else
		cout << mn << '\n';
	return 0;
}
    
