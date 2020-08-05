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
int main(){
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    fin;
    int n;
    cin >> n;
    vector<ll> s(n / 2), f(n / 2);
    fore(i, 0, n / 2)
        cin >> s[i];

    fore(i, 1, n / 2){
        ll aux = s[i];
        s[i] = min(s[i - 1], s[i] - f[i - 1]);
        f[i] = aux - s[i];
    }
    for(auto i : f)
        cout << i << ' ';
    reverse(all(s));
    for(auto i : s)
        cout << i << ' ';
    return 0;
}   
