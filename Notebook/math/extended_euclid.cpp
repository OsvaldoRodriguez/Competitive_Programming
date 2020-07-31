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
const int N = 1 * 1e5 + 5;
const ll mod = 1e9 + 7;
const double E = 1e-9;
//int dx[] = {1, 0}, dy[] = {0, 1};
//int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)

// ecuaciones diofanticas
struct dxy{
    ll d, x, y;
    dxy() : d(0), x(0), y(0){}
};
ll GCD(ll a, ll b){return b == 0 ? a : GCD(b, a % b);}
ll LCM(ll a, ll b){return a / GCD(a, b) * b;}
dxy GCD_ext(ll a, ll b){
    dxy r;
    if(b == 0){
        r.d = a;
        r.x = 1;
        r.y = 0;
        return r;
    }
    dxy t = GCD_ext(b, a % b);
    r.d = t.d;
    r.x = t.y;
    r.y = t.x - (a / b) * t.y;
    return r;

}

ll f(ll n, ll a, ll b, ll x, ll y, dxy d){
    return a * (n * x) / d.d + b * (n * y) / d.d;
}
int main(){
    //FL;
    FIN;
    ll a, b, n;
    scanf("%lld %lld %lld", &a, &b, &n);
    dxy D = GCD_ext(a, b);
    if(n % GCD(a, b))
        printf("-1\n");
    else{
        printf("%lld %lld %lld\n",D.x, D.y, D.d);
        //encontrando todas sus soluciones
        for(int k = 0; k < 2000; k++){
            ll x_0 = D.x + b / D.d * k;
            ll y_0 = D.y - a / D.d * k;
            ll x = n * x_0 / D.d;
            ll y = n * y_0 / D.d;
            printf("%lld %lld %lld\n", x, y, a * x + b * y);

        }
    }
    EjecuteTime;
    return 0;
}       