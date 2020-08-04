#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ii pair<int,int>
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define fore(i,a,b) for(int i = a;i < b; i++)
using namespace std;
typedef long long ll;
const int N = 5 * 1e5 + 5;
const int mod = 1e9 + 7;
const ll MAX = (1LL << 32) - 1;
deque<ll> q;
int main(){
	fast;
	int t,l1,r1,l2,r2,a,b;
	cin >> t;
	while(t--){
		cin >> l1 >> r1 >> l2 >> r2;
		if(l1 == r2)
			l1++;
		cout << l1 << " " << r2 << "\n";
		
	}
	return 0;	
}
