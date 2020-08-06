#include <bits/stdc++.h>
#define fin         ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
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
#define FL          freopen("in", "r", stdin),freopen("out", "w", stdout);
#define EjecuteTime cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n"
#define angle(x)    double(x * acos(-1) / 180.0)
using namespace std;
typedef long long   ll;
typedef vector<int> vi;
typedef vector<ii>  vii;
const int N = 2 * 1e5 + 5;
const ll mod = 1e9 + 7;
const double E = 1e-9;
//int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
ll POW(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b & 1)
            ans *= a;
        a *= a;
        b >>= 1;
    }
    return ans;
}
ll f(ll x){
    return 9 * POW(10, x - 1) * x;
}
ll A[15];
ll B[15];
int main(){
    //FL;
    fin;
    ll a;
    A[1] = 9;
    B[1] = 9;
    for(ll i = 2; i <= 14; i++){
        A[i] = A[i - 1] + f(i);
        B[i] = B[i - 1] * 10 + 9;
    }
    while(cin >> a){
        ll i = 1;
        if(a <= 9){
            cout << a << '\n';
            continue;
        }
        while(A[i] < a)
            i++;
        ll aux = a - A[i - 1];
        
        ll number = aux / i;
        if(aux % i){
            number++;
            number += B[i - 1];
            string nn = to_string(number);
            cout << nn[aux % i - 1LL] << "\n";
        }
        else{
            number += B[i - 1];
            cout << number % 10 << "\n";
        }
        
    }

    //EjecuteTime;
    return 0;
}       

