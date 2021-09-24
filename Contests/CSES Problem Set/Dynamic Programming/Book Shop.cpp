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
const int N = 1e3 + 15;
const ll mod = 1e9 + 7;
const double E = 1e-7;
int n;
int H[N], S[N], dp[N][100005];
void solve(){	
	int x;
	cin >> n >> x;
	for(int i = 0; i < n; i++){
		cin >> H[i];	
	}
	for(int i = 0; i < n; i++){
		cin >> S[i];	
	}

	// dp[n][0] = 1;
	
	for(int i = n; i >= 0; i--){
		for(int value = 0; value <= x; value++){
			int &ans = dp[i][value];
			if(value == 0){
				ans = 0;
				continue;
			}
			ans = -1e7;
			ans = max(ans, dp[i + 1][value]);
			if(value >= H[i])
				ans = max(ans, dp[i + 1][value - H[i]] + S[i]);
		}
	}

	cout << dp[0][x] << '\n';

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
