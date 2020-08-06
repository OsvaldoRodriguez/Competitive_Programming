#include <bits/stdc++.h>
#define fin ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ii pair<int,int>
#define F first
#define S second
#define pb push_back
#define pf push_front
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define fore(i,a,b) for(int i = a;i < b; i+= 1)
#define forr(i,a) for(int i = a; i >= 0; i--)
#define fori(i,m) for(auto i = m.begin(); i != m.end(); i++) 
#define w(t) while(t--)
#define sz(s) int(s.size())
#define cls(a,car) memset(a,car,sizeof (a))
#define ff(x) cerr << #x << " is " << x << '\n'
#define FL freopen("in", "r", stdin),freopen("out", "w", stdout);
#define time cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n"
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ii> vii;
const int N = 1 * 1e5 + 5;
const ll mod = 998244353;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
const double E = 1e-9;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)  
ll count(ll n){
    ll ans = 0;
    while(n){
        ans += (n % 10 == 9);
        n /= 10;
    }
    return ans;
}
int main(){
    
    //FL;
    fin;
    ll ans = 0;
    ll cur = 0;
    ll n, k;
    cin >> n >> k;

    ll aux = n;
    n -= k;
    string a = to_string(n);
    string b = to_string(aux);
    bool flag = 1;
    fore(i, 1, sz(b))
        if(b[i] != '9'){
            flag = 0;
        }
    if(flag){
        cout << b << '\n';
        return 0;
    }
    if(sz(a) < sz(b)){
        int lim = sz(b) - 1;
        int cur = 0;
        fore(i, 0, sz(a))
            if(a[i] == '9' && a[i] <= b[i + 1])
                cur++;
        if(cur == sz(a))
            cout << b[0];
        if(n == 1){
            if(b[0] > '1')
            cout << char(b[0] - 1);
        }
        fore(i, 0, lim)
            cout << '9';
        cout << '\n';
        return 0;
    }
    int i = 0;
    while(i < min(sz(a), sz(b)) && a[i] == b[i])
        i++;
    if(i){
        if(i + 1 == sz(b))
            a[i] = b[i];
        else
        a[i] = char(b[i] - 1);
    }
    i++;
    while(i < sz(b))
        a[i++] = '9';
    cout << a << '\n';
    time;
    return 0;
}   