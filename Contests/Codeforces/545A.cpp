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
int arr[105];
int main(){
	fast;
	int n;
	cin >> n;
	int x;
	fore(i,1,n + 1){
		fore(j,1,n + 1){
			cin >> x;
			if(x == -1)
				continue;
			if(x == 1)
				arr[i] = 1;
			else if(x == 2)
				arr[j] = 1;
			else if(x == 3)
				arr[i] = arr[j] = 1;
		}
	}
	int ans = 0;
	fore(i,1,n + 1)
		if(!arr[i])
			ans++;
	cout << ans << '\n';
	fore(i,1,n + 1)
		if(!arr[i])
			cout << i << ' ';
	return 0;
}
    
