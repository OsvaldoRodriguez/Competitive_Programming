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
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ii> vii;
const int N = 2 * 1e5 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
const double E = 1e-9;
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
ll v[N], m;
int n;
bool f(int x){
    ll dias = 0;
    fore(i, 0, n)
        dias += max(v[i] - (i / x), 0LL);
    return dias >= m;
}
int main(){
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    fin;
    cin >> n >> m;
    fore(i, 0, n)
        cin >> v[i];

    sort(v, v + n);
    reverse(v, v + n);/*
    fore(i, 0, n)
        cout << v[i] << ' ';cout << endl;*/
    int a = 0, b = n + 5, mid;
    while(b - a > 1){
        mid = (a + b) >> 1;
        if(f(mid))
            b = mid;
        else
            a = mid; 
    }
    if(b > n)
        b = -1;
    cout << b << '\n';
    return 0;
}   
