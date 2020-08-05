#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
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
#define sz(s) int(s.size())
#define cls(a,car) memset(a,car,sizeof (a))
using namespace std;
typedef long long ll;
typedef vector<int> vi;
const int N = 3 * 1e5 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
const double E = 1e-9;
int occ[N];
int main(){
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    fast;
    int n, m;
    cin >> n >> m;
    vector<ii> v(m);
    fore(i, 0, m)
        cin >> v[i].F >> v[i].S;
    int aux = v[0].F;
    int tot = 0;
    fore(i, 0, m){
        if(v[i].F == aux or v[i].S == aux)
            tot++;
        else{ 
            occ[v[i].F]++;
            occ[v[i].S]++;
        }
    }
    int mx = 0;
    fore(i, 0, N)
        mx = max(mx,occ[i]);
    if(tot + mx == m)
        cout << "YES\n";
    else{
        cls(occ,0);
        aux = v[0].S;
        tot = 0;
        fore(i, 0, m){
            if(v[i].F == aux or v[i].S == aux)
                tot++;
            else{ 
                occ[v[i].F]++;
                occ[v[i].S]++;
            }
        }
        mx = 0;

        fore(i, 0, N)
            mx = max(mx,occ[i]);

        if(mx + tot == m)
            cout << "YES\n";
        else
            cout << "NO\n";
        
    }

    return 0;
}   
