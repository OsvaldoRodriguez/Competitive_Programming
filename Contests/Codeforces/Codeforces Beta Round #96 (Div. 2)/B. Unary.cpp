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
#define what_is(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ii> vii;
const int N = 1 * 1e5 + 5;
const ll mod = 1e6 + 3;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
const double E = 1e-9;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
int pot[505];
int main(){
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    fin;
    pot[0] = 1;
    fore(i, 1, 500)
        pot[i] = (pot[i - 1] % mod * 2 % mod) % mod;
    map<char, string> m;
    m['>'] = "1000";
    m['<'] = "1001";
    m['+'] = "1010";
    m['-'] = "1011";
    m['.'] = "1100";
    m[','] = "1101";
    m['['] = "1110";
    m[']'] = "1111";
    string s;
    cin >> s;
    string aux = "";
    for(auto i : s)
        aux += m[i];
    reverse(all(aux));
    int ans = 0;
    fore(i, 0, sz(aux))
        if(aux[i] == '1')
            ans = (ans % mod + pot[i] % mod) % mod;
    cout << ans << '\n';
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}   
