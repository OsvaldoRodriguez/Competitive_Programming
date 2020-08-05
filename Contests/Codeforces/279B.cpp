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
    int n, t;
    cin >> n >> t;
    int v[n + 1];
    fore(i, 0, n)cin >> v[i];
    int s = v[0];
    int i = 0, j = 0;
    int mx = 0;
    while(i <= j && j < n){
        if(s <= t)
            mx = max(mx, j - i + 1);
        if(s < t){
            j++;
            if(j < n)
            s += v[j];
        }else{
            if(i == j){
                j++;
                if(j < n)
                    s += v[j];
            }
            else{
                if(i < n)
                    s -= v[i++];
            }
        } 
        //cout << i << " " << j << " " << s << '\n'; 
    }
    cout << mx << '\n';
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}   
