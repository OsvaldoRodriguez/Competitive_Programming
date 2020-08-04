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
int v[101];
int main(){
	int n,x,k;
	cin >> n >> k;
	fore(i,0,n)
		cin >> x,v[x % k]++;
	int ans = (v[0] >> 1) << 1;
	fore(i,1,k / 2 + 1){
		if(i != k - i)
			ans += min(v[i],v[k - i]) * 2;
		else
			ans += (v[i] >> 1) << 1;
	}
	cout << ans << '\n';
	return 0;	
}
