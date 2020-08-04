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
#define sz(s) int(s.size())
#define	cls(a,car) memset(a,car,sizeof (a))
using namespace std;
typedef long long ll;
const int N = 500 + 5;
const int mod = 1e9 + 7;
const ll INF = LONG_LONG_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
ll f(ll x){return x * (x + 1) >> 1;}
int v[N][N];
int main(){
	fast;
	bool flag = 1;
	int d = 3;
	v[1][1] = 2;
	int j = 2;
	int r,c;
	cin >> r >> c;
	if(r > c)
		flag = 0;
	int aux = 0;
	fore(i,1,1001){
		if(flag){
			if(c >= j)
			v[1][j] = d++;	
			flag = 0;
			aux++;

		}else{
			flag = 1;
			if(r >= j)
			v[j][1] = d++;
			aux++;
		}
		if(!(aux & 1))j++;

	}
	fore(i,2,500 + 1){
		fore(j,2,500 + 1)
			v[i][j] = v[1][j] * v[i][1];
	}
	
	if(r == c  && c == 1){
		cout << "0\n";
		return 0;
	}
	
		fore(i,1,r + 1){
			fore(j,1,c + 1)
				cout << v[i][j] << ' ';
			cout << '\n';
		}
	
	

	return 0;
}
