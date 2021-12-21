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
const int N = 2 * 1e5 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
const double E = 1e-9;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b) 
set<ll> s;
ll v[] = {4, 7};
bool f(ll u){
    if(!u)return 0;
    int a = 0, b = 0;
    while(u){
        a += (u % 10 == 4);
        b += u % 10 == 7;
        u /= 10;
    }
    return a == b;
}
void dfs(ll u){
    if(f(u))
        s.insert(u);
    fore(i, 0, 2){
        ll num = u * 10 + v[i];
        if(num <= 1e12)
            dfs(num);
    }
}
int main(){
    //FL;
    fin;
    dfs(0);
    ll n;
    cin >> n;
    auto it = s.upper_bound(n - 1);
    cout << *it << '\n';
    time;
    return 0;
}   
