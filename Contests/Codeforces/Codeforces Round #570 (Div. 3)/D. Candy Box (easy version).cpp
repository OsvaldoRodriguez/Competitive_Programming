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
const int N = 2e5 + 15;
const ll mod = INT_MAX;
const double E = 1e-7;
int v[N];
ii A[N];
void solve(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        v[i] = 0;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v[x]++;
    }
    for(int i = 0; i < n; i++){
        A[i].F = v[i + 1];
        A[i].S = i + 1;
    }
    sort(A, A + n);
    reverse(A, A + n);
    int ans = 0;

    int cur = A[0].F;

    for(int i = 0; i < n and cur > 0; i++){
        if(A[i].F >= cur){
            ans += cur;
            cur--;
        }else{
            cur = A[i].F;
            ans += cur;
            cur--;
        }
    }

   
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
