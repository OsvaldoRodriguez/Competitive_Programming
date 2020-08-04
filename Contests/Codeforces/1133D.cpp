#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ii pair<int,int>
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define fore(i,a,b) for(int i = a;i < b; i+= 1)
#define forr(i,a) for(int i = a; i >= 0; i--)
using namespace std;
typedef long long ll;
const int N = 2 * 1e5 + 5;
const int mod = 1e9 + 7;
const ll MAX = (1LL << 32) - 1;
int a[N],b[N];
int main(){
	fast;
	int n;
	cin >> n;
	fore(i,0,n)cin >> a[i];
	fore(i,0,n)cin >> b[i];
	int num,den;
	map<ii,int> m;
	int ans = 0;
	fore(i,0,n){
		if(a[i] == b[i] && b[i] == 0)
			ans++;
		if(a[i] != 0){
			int gcd = __gcd(b[i],a[i]);
			m[ii(-b[i] / gcd,a[i] / gcd)]++;
		}
	}
	int mx = 0;
	for(auto i = m.begin(); i != m.end(); i++){
		if(i->S > mx){
			mx = i->S;
			num = (i->F).F;
			den = (i->F).S;
		}
	}
	if(m.size() == 0){
		cout << ans << '\n';
		return 0;
	}
	fore(i,0,n){
		if(a[i] == b[i] && !b[i]){
			continue;
		}
		if(-num * a[i]  == b[i] * den)
			ans++;
	}
	cout << ans << '\n';
	return 0;	
}
