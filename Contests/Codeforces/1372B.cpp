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
ll LCM(ll a, ll b){
    return a * b / __gcd(a, b);
}
ll a11, b11;
void solv1(ll n){
    int lcm = 1e9;
    for(int i = 1; i <= n; i++){
        //cout << i << " " << n - i << " " << LCM(i, n - i) << '\n';
        if(lcm > LCM(i, n - i) && i > 0 && n - i > 0){
            lcm = LCM(i, n - i);
            a11 = i;
            b11 = n - i;
        }
    }
}
int main(){
    //FL;
    FIN;
    int t;
    cin >> t;
    w(t){
        ll n;
        a11 = -1, b11 = -1;
        cin >> n;
        //solv1(n);
        ///cout << '\n';
        //cout << a11 << " " << b11 << " " <<  LCM(a11, b11) << '\n';
        if(n % 2 == 0)
            cout << n / 2 << " " << n / 2 << '\n';
        else{
            ll lcm = 1e9;
            ll auxa = -1, auxb = -1;
            for(ll i = 1; i * i <= n; i++){
                if(n % i == 0){
                  //cout << i << " div " << n / i << '\n';
                    if(lcm > LCM(i, n - i) && i > 0 && n - i > 0){
                        lcm = LCM(i, n - i);
                        auxb = n - i;
                        auxa = i;
                    }
                    ll auxi = LCM(i, n - i);
                    ll cmp = n - auxi;
                    if(cmp + auxi == n && cmp > 0 && auxi > 0){
                        if(lcm > LCM(auxi, cmp)){
                            lcm = LCM(auxi, cmp);
                            auxa = auxi;
                            auxb = cmp;
                        }
                    }
                    if(lcm > LCM(n / i, n - n / i) && (n / i) > 0 && (n - n / i) > 0){
                        auxa = n / i;
                        auxb = n - n / i;
                    }
                    auxi = LCM(n / i, n - n / i);
                    cmp = n - auxi;
                    if(cmp + auxi == n && cmp > 0 && auxi > 0){
                        if(lcm > LCM(auxi, cmp)){
                            lcm = LCM(auxi, cmp);
                            auxa = auxi;
                            auxb = cmp;
                        }
                    }
                }   
            }
            cout << auxa << " " << auxb << '\n';
        }
    }
    EjecuteTime;
    return 0;
}       
