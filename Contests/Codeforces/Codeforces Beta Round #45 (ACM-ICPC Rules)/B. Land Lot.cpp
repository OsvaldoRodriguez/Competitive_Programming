#include <bits/stdc++.h>
#define FIN         ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ii          pair<int,int>
#define F           first
#define S           second
#define pb          push_back
#define all(x)      (x).begin(),(x).end()
#define rall(x)     (x).rbegin(),(x).rend()
#define fore(i,a,b) for(int i = a;i < b; i+= 1)
#define forr(i,a)   for(int i = a; i >= 0; i--)
#define fori(i,m)   for(auto i = m.begin(); i != m.end(); i++) 
#define w(t)        while(t--)
#define sz(s)       int(s.size())
#define cls(a,car)  memset(a,car,sizeof (a))
#define db(x)       cerr << #x << " is " << x << '\n'
#define FL          freopen("input.txt", "r", stdin),freopen("output.txt", "w", stdout);
#define EjecuteTime cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n"
#define angle(x)    double(x * acos(-1) / 180.0)
using namespace std;
typedef long long   ll;
typedef vector<int> vi;
typedef vector<ii>  vii;
const int N = 3 * 1e5 + 5;
const ll mod = 1e9 + 7;
const double E = 1e-9;
//int dx[] = {1, 0}, dy[] = {0, 1};
//int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
ll POW(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b & 1)
            ans = (ans * a) % 9;
        b >>= 1;
        a *= a;
        a %= 9;
    }
    return ans;
}
int v[55][55];
int main(){
    //FL;
    //FIN;    
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> v[i][j];
    int a, b;
    cin >> a >> b;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            v[i][j] += v[i - 1][j] + v[i][j - 1] - v[i - 1][j - 1];

    int ans = 1e9;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            for(int k = i; k <= n; k++){
                for(int l = j; l <= m; l++){
                    if((k - i == a - 1 && l - j == b - 1) or (k - i == b - 1 && l - j == a - 1)){
                        //cout << i << " " << j << " " << k << " " << l << endl;
                        int cur = v[k][l] - v[k][j - 1] - v[i - 1][l] + v[i - 1][j - 1];
                        ans = min(ans, cur);
                    }
                }
            }
        }
    }
    cout << ans << '\n';
    EjecuteTime;
    return 0;
}       
