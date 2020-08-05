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
const int N = 1 * 1e5 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
const double E = 1e-9;
int main(){
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    fast;
    int n;
    ll d;
    cin >> n >> d;
    vector<pair<int,ll> > v(n);
    fore(i,0,n)cin >> v[i].F >> v[i].S;
    sort(all(v));
    fore(i,1,n)
        v[i].S += v[i - 1].S;
    int i = 0,j = 0;
    ll ans = 0;
    while(i < n && j < n){
        if(v[j].F - v[i].F < d){
            if(!i)
                ans = max(ans, v[j].S);
            else
                ans = max(ans, v[j].S - v[i - 1].S);
        }
        if(v[j].F - v[i].F < d)
            j++;
        else
            i++;
    }  
    cout << ans << '\n';
    return 0;
}   
