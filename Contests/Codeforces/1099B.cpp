#include <bits/stdc++.h>
#define fin ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
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
typedef vector<ii> vii;
const int N = 2 * 1e5 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
const double E = 1e-9;
int main(){
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    ll n;
    ll ans = 1e9;
    cin >> n;
    if(n == 1)
        ans = 2;
    else if(n == 2)
        ans = 3;
    else{
        int sq = (int)sqrt(n);
        if(sq * sq == n)
            ans = sq + sq;
        else if(sq * sq < n && n <= (sq + 1) * sq)
            ans = sq + sq + 1;
        else
            ans = sq + sq + 2;
    }
    cout << ans << '\n';
    return 0;
}   
