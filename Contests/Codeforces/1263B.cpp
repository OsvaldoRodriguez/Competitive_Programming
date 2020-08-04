#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ii pair<int,int>
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define fore(i,a,b) for(int i = a;i < b; i+= 1)
#define forr(i,a) for(int i = a; i >= 0; i--)
#define fori(i,m) for(auto i = m.begin(); i != m.end(); i++) 
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
const ll MAX = (1 << 30);
vector<string> v;
set<string> s;
map<string,int> m;
int main(){
	fast;
	int n,t;
	string st;
	cin >> t;
	while(t--){
		cin >> n;
		s.clear();
		m.clear();
		v.clear();
		fore(i,0,n){
			cin >> st;
			v.pb(st);
			s.insert(st);
			m[st]++;
		}
		int ans = n - s.size();
		vector<string> aux;
		int mx = 0;
		if(ans > 0)
		fori(i,m)
			if(i->S > 1)
				aux.pb(i->F);
		
		fore(i,0,aux.size()){
			int val = m[aux[i]];
			val--;
			char q = aux[i][0];
			fore(j,0,v.size()){
				if(v[j] == aux[i]){
					while(1){
						v[j][0] = q;
						if(q == '9')
							q = '0';
						else
							q++;
						if(!s.count(v[j])){
							s.insert(v[j]);
							val--;
							break;
						}

					}
				}
				if(!val)
					break;
			}
		}
		cout << ans << "\n";
		for(auto i : v)
			cout << i << "\n";
	}

	return 0;	
}
