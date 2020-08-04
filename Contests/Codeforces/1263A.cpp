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
int main(){
	//fast;
	ll n,r,g,b;
	cin >> n;
	while(n--){
		priority_queue<int> q;
		cin >> r >> g >> b;
		ll ans2 = (r + g + b) >> 1;
		q.push(r);
		q.push(g);
		q.push(b);
		ll a1 = q.top();q.pop();
		ll a11 = a1;
		ll a3 = q.top();q.pop();
		ll a33 = a3;
		ll a2 = q.top();q.pop();
		ll a22 = a2;
		ll ans  = 0;
		ll ans3 = a3 + a2;
		ll mid = (a2 + 1) >> 1;
		ll aux = min(a1,mid);
		ans += aux;
		a1 -= aux;
		a2 -= mid;
		aux = min(a3,a2);
		ans += aux;
		a2 -= aux;
		a3 -= aux;
		ans += min(a1,a3);

		ll ans1  = 0;
		aux = min(a11,a22);
		ans1 += aux;
		a11 -= aux;
		a22 -= aux;
		aux = min(a11,a33);
		ans1 += aux;
		cout << min(ans2,max(ans1,max(ans,ans3))) << "\n";

	}
	return 0;	
}
