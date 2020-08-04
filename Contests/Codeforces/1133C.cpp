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
int v[N];
int main(){
	fast;
	int n;
	cin >> n;
	fore(i,0,n)
		cin >> v[i];
	sort(v,v + n);
	int i = 0, j = 0;
	int ans = 0;
	while(j < n && i <= j){
		if(v[j] - v[i] <= 5)
			j++;
		else
			i++;
		ans = max(ans, j - i);
	}
	cout << ans << '\n';
	return 0;	
}
