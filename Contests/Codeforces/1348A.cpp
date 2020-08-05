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
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
ll pot[33];
int main(){
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    fin;
    int t;
    cin >> t;
    pot[1] = 2;
    fore(i, 2, 33)
        pot[i] = pot[i - 1] * 2; 
    w(t){
        int n;
        cin >> n;
        ll l = 0;
        ll r = 0;
        if(n == 2){
            cout << "2\n";
            continue;
        }
        for(int i = 1; i < n; i++){
            if(i < n / 2)
                l += pot[i];
            else r += pot[i];
        }
        l += pot[n];

        cout << abs(r - l) << '\n';

    }
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}   
