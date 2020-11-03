#include <bits/stdc++.h>
#define ii              pair<int,int>
#define F               first
#define S               second
#define pb              push_back
#define all(x)          (x).begin(),(x).end()
#define rall(x)         (x).rbegin(),(x).rend()
#define fore(i, a, b)   for(int i = a; i < b; i += 1)
#define forr(i, a)      for(int i = a; i >= 0; i--)
#define sz(s)           int(s.size())
#define cls(a,car)      memset(a,car,sizeof (a))
#define db(x)           cerr << #x << " is " << x << '\n'
#define angle(x)        double(x * acos(-1) / 180.0)
using namespace std;
typedef long long   ll;
typedef vector<int> vi;
typedef vector<ii>  vii;
const int N = 1e3 + 5;
const ll mod = 1e9 + 7;
const double E = 1e-7;
const int oo = 1e9;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
char v[N][N];
int n;
void solve(){
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> v[i][j];
    int p = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int cur = 0;
            if(v[i][j] == '.')
                continue;
            for(int k = 0; k < 4; k++){
                int _i = i + dx[k];
                int _j = j + dy[k];
                if(_i >= 0 && _i < n && _j >= 0 && _j < n){
                    if(v[_i][_j] == '*')
                        cur++;
                }
            }
            p += 4 - cur;
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(v[i][j] == '*')
                continue;
            int cur = 0;
            for(int k = 0; k < 4; k++){
                int _i = i + dx[k];
                int _j = j + dy[k];
                if(_i >= 0 && _i < n && _j >= 0 && _j < n){
                    if(v[_i][_j] == '*')
                        cur++;
                }
            }
            if(4 - cur == cur)
                ans++;
        }
    }
    cout << ans << '\n';
}
int main(){
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++)
        solve();

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}
