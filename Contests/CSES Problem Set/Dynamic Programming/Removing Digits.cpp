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

int dp[N];
vector<int> go(int cur){
	vector<int> dg(10, 0);
	while(cur){
		dg[cur % 10] |= 1;
		cur /= 10;
	}
	return dg;
}

int f(int n){
	// debug(n);
	if(n == 0)
		return 0;
	int &ans = dp[n];
	if(ans == -1){
		ans = 1e8;
		vector<int> digitos = go(n);
		for(int i = 1; i < 10; i++){
			if(digitos[i]){
				ans = min({ans, f(n - i) + 1});
			}
		}
	}
	return ans;
}

void solve(){
	int n;
	cin >> n;
	cls(dp, -1);
	cout << f(n) << '\n';

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
