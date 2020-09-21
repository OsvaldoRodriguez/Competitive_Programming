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
#define FI          freopen("input.txt", "r", stdin)
#define FO          freopen("output.txt", "w", stdout)
#define EjecuteTime cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n"
#define angle(x)    double(x * acos(-1) / 180.0)
using namespace std;
typedef long long   ll;
typedef vector<int> vi;
typedef vector<ii>  vii;
const int N = 1e6 + 5;
const ll mod = 1e9 + 7;
const double E = 1e-7;
//int dx[] = {0, -1}, dy[] = {-1, 0};
//int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
//int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
vi v;
ll dp[51][2][36][36][2];
ll f(int i, bool flag, int six, int nine, bool is){
    if(six < 0 or six > 35 or nine < 0 or nine > 35)
        return 0;
    if(i == sz(v))
        return (six == 18 && nine == 18 && is);
    ll &ans = dp[i][flag][six][nine][is];
    if(ans == -1){
        ans = 0;
        for(int j = 0; j < 10; j++){
            if(flag or j <= v[i]){
                if(j == 3)
                    ans = (ans + f(i + 1, flag or (j < v[i]), six - 1, nine - 1, 1)) % mod;
                else
                    ans = (ans + f(i + 1, flag or (j < v[i]), six + (j == 6), nine + (j == 9), is or j == 6 or j == 9)) % mod;
                
            }
        }
    }
    return ans;
}
ll get(string &s){
    v.clear();
    for(auto i : s)
        v.pb(i - '0');
    for(int i = 0; i < sz(v); i++)
        for(int j = 0; j < 2; j++)
            for(int k = 0; k < 36; k++)
                for(int l = 0; l < 36; l++)
                    for(int m = 0; m < 2; m++)
                        dp[i][j][k][l][m] = -1;
    return f(0, 0, 18, 18, 0);
}
void solve(){
    string a, b;
    cin >> a >> b;
    for(int i = sz(a) - 1; i >= 0; i--){
        if(a[i] == '0')
            a[i] = '9';
        else{
            a[i]--;
            break;
        }
    }
    cout << (get(b) - get(a) + mod) % mod << '\n';
}  
int main(){
    FIN;
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++){
        solve(); 
    }
    //EjecuteTime;
    return 0;
}  
