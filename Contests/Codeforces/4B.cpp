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
int main(){
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    fin;
    int d, st;
    cin >> d >> st;
    int mn[d + 1], mx[d + 1];
    int l = 0, r = 0;
    fore(i, 0, d){
        cin >> mn[i] >> mx[i];
        l += mn[i];
        r += mx[i];
    }
    if(l > st or r < st)
        cout << "NO\n";
    else{
        vi arr;
        if(l == st){
            cout << "YES\n";
            fore(i, 0, d)
                cout << mn[i] << ' ';
        }
        else
        if(r == st){
            cout << "YES\n";
            fore(i, 0, d)
                cout << mx[i] << ' ';
        }else{
            vi arr;
            int ans = l;
            fore(i, 0, d){
                if(ans == st){
                    arr.pb(mn[i]);
                    continue;
                }
                ans -= mn[i];
                int aux = min(mx[i], abs(st - ans));
                ans += aux;
                if(ans <= st)
                    arr.pb(aux);
                
            }
            cout << "YES\n";
            for(auto i : arr)cout << i << " ";cout << '\n';
        }


    }
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}   
