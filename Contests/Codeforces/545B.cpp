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
	string a,b;
	cin >> a >> b;
	int df = 0;
	fore(i,0,sz(a))
		if(a[i] != b[i])
			df++;
	if(df & 1)
		cout << "impossible\n";
	else{
		bool flag = 1;
		string s = "";
		fore(i,0,sz(a)){
			if(a[i] != b[i]){
				if(flag){
					s += a[i];
					flag = 0;
				}else{
					s += b[i];
					flag = 1;
				}
			}else
				s += a[i];
		}
		cout << s << '\n';
	}
	return 0;
}
    
