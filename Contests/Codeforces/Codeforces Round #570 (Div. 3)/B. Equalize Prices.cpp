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
const int N = 2e2 + 15;
const ll mod = INT_MAX;
const double E = 1e-7;

bool f(vector<int> &v, int x, int k){
    bool flag = 1;
    if(x < 0)
        return false;
    
    for(int i = 0; i < v.size(); i++){
        flag &= (abs(v[i] - x) <= k);
    }
    return flag;
}
void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> v(n, 0);
    for(int &i : v)
        cin >> i;

    sort(all(v));
    int cur = v[n - 1] + k;
    int ans = -1;
    if(f(v, cur, k))
        ans = max(ans, cur);
  
    cur = v[n - 1] - k;
    if(f(v, cur, k))
        ans = max(ans, cur);
    cur = v[0] + k;
    if(f(v, cur, k))
        ans = max(ans, cur);
    cur = v[0] - k;
    if(f(v, cur, k))
        ans = max(ans, cur);
 

    cout << ans << '\n';




}
int main(){
    #ifdef FURY
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #endif
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++){ 
        solve();
    }

    #ifdef FURY
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}
