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
const int N = 1 * 1e6 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
const double E = 1e-9;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
int f(int x){
    if(x & (x - 1))return 0;
    return 1;
}
int v[N];
int main(){
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    fin;
    fore(i, 0, N)
        v[i] = i;
    for(int i = 2; i * i < N; i++)
        if(v[i] == i)
            for(int j = i * i; j < N; j += i)
                v[j] = i;
    int n;
    cin >> n;
    if(n == 1){
        cout << 1 << ' ' << 0 << '\n';
        return 0;
    }
    map<int, int> m;
    while(n != 1){
        m[v[n]]++;
        n /= v[n];
    }
    int mx = 0, mn = 100;
    int ans = 1;
    fori(i, m){
        ans *= i->F;
        mx = max(mx, i->S);
        mn = min(mn, i->S);
    }

    if(mx == mn && f(mx) && f(mn)){
        int j = 0;
        while(mx != 1){
            j++;
            mx >>= 1;
        }
        cout << ans << " " << j <<  '\n';
    }
    else{
        int j = log10(mx) / log10(2.0);
        if((1 << j) < mx)
            j++;
        cout << ans << " " << j + 1 << '\n';
    } 
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}   
