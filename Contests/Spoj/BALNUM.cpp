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
const int N = 1e4 + 5;
const ll mod = 1e9 + 7;
const double E = 1e-9;
//int dx[] = {0, -1}, dy[] = {-1, 0};
//int _dx[] = {0, 1}, _dy[] = {1, 0};
//int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
//int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
vi v;
ll dp[20][2][2][6 * N];
ll pot[12];
// mask 0 -> si no lleva ese digito
// 1 -> si lleva una  catidad impar ese digito
// 2 -> si lleva una canticda par ese digito 
ll f(int i, bool flag, bool zero, int mask){
    if(i == sz(v)){
        bool ok = 1;
        for(int j = 0; j < 10; j++){
            int times = (mask / pot[j]) % 3;
            if(j & 1){
                if(times == 1)
                    ok = 0;
            }else{
                if(times == 2)
                    ok = 0;
            }
        }
        return ok;
    }
    ll &ans = dp[i][flag][zero][mask];
    if(ans == -1){
        ans = 0;
        for(int j = 0; j < 10; j++){
            if(j <= v[i] or flag){
                int times = (mask / pot[j]) % 3;
                int newmask = mask;
                if(times < 2){
                    if(zero or j > 0){
                        newmask += pot[j];
                    }
                }else if(times == 2){
                    if(zero or j > 0)
                        newmask -= pot[j];
                }
                ans += f(i + 1, flag || j < v[i], zero || j > 0, newmask);
            }
        }
    }
    return ans;
}
ll get(ll x){
    v.clear();
    cls(dp, -1);
    while(x > 0){
        v.pb(x % 10);
        x /= 10;
    }
    reverse(all(v));
    return f(0, 0, 0, 0);
}
int main(){
    FIN;
    int t;
    pot[0] = 1;
    for(int i = 1; i < 12; i++)
        pot[i] = 3 * pot[i - 1];
 
    cin >> t;
    while(t--){
        ll l, r;
        cin >> l >> r;
        cout << get(r) - get(l - 1) << '\n';
    }
    EjecuteTime;
    return 0;
}        
