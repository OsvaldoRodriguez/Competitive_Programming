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
	string a,b,s;
	cin >> t;
	int n;
	while(t--){
		cin >> n >> s;
		a = b = "1";
		bool flag = 1;
		fore(i,1,n){
			if(s[i] == '1'){
				if(flag){
					a += '1';
					b += '0';
					flag = 0;
				}else
					a += '0',b += '1';
			}
			else if(s[i] == '0')
				a += '0', b += '0';
			else if(s[i] == '2'){
				if(!flag)
					b += '2',a += '0';
				else
				a += '1', b += '1';
			}
		}
		cout << a << '\n' << b << '\n';
	}
	return 0;
}
    
