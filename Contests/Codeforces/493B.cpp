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
    ll first = 0, second = 0;
    int last = 1;
    cin >> n;
    vi f,s;
    w(n){
        ll x;
        cin >> x;
        if(x > 0){
            last = 1;
            first += x;
            f.pb(x);
        }else{
            last = 2;
            second -= x;
            s.pb(-x);
        }
    }
    if(first > second)
        cout << "first\n";
    else if(second > first)
        cout << "second\n";
    else{
        int len = min(sz(f), sz(s));
        int i = 0;
        while(f[i] == s[i])
            i++;
        if(i == len)
            cout << (last == 1? "first" : "second") << '\n';
        else
            cout << (f[i] > s[i] ? "first" : "second") << '\n';

    }
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}   
