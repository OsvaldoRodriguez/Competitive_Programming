#include <bits/stdc++.h>
#define ii              pair<int,int>
#define F               first
#define S               second
#define pb              push_back
#define all(x)          (x).begin(),(x).end()
#define rall(x)         (x).rbegin(),(x).rend()
#define sz(s)           int(s.size())
#define cls(a, car)     memset(a,car,sizeof (a))
#define db(x)           cout << #x << " is " << x << '\n'
#define angle(x)        double(x * acos(-1) / 180.0)
using namespace std;
void debug(){cout << endl;}
template<typename T, typename... Args>
void debug(T a, Args... args){cout << a << " "; debug(args...);}
typedef long long   ll;
typedef vector<int> vi;
typedef vector<ii>  vii;
const int N = 1e6 + 15;
const ll mod = 1e9 + 7;
const double E = 1e-7;

int num[105];
ll dp[N];
int n;

void solve(){
	int x;
	cin >> n >> x;
	for(int i = 0; i < n; i++)
		cin >> num[i];

	dp[0] = 1;
	for(int i = 0; i < n; i++){
		for(int j = num[i]; j <= x ; j++){
			dp[j] += dp[j - num[i]];
			dp[j] %= mod;
		}
	}
	cout << dp[x] << '\n';
}
int main(){
    #ifdef FURY
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #endif
    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++){ 
        solve();
    }

    #ifdef FURY
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}
