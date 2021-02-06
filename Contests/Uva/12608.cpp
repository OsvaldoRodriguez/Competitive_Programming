#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ii pair<int,int>
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define allr(x) (x).rbegin(),(x).rend()
#define fore(i,a,b) for(int i = a;i < b; i+= 1)
#define forr(i,a) for(int i = a; i >= 0; i--)
#define fori(i,m) for(auto i = m.begin(); i != m.end(); i++) 
#define sz(s) int(s.size())
#define cls(a,car) memset(a,car,sizeof (a))
using namespace std;
typedef long long ll;
typedef pair<ll,ll> llp;
const int N = 2 * 1e5 + 5;
const int mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
vector<llp> v;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        v.clear();
        ll w,n;
        scanf("%lld %lld",&w,&n);
        while(n--){
            ll x,y;
            scanf("%lld %lld",&x,&y);
            v.pb(llp(x,y));
        }
        ll sum = 0;
        ll ans = 0;
        for(int i = 0; i < sz(v); i++){
            if(sum + v[i].S > w){
                sum = 0;
                ans += v[i].F;
            }
            if(sum + v[i].S == w){
                sum = 0;
                ans += v[i].F;
                v[i].F = 0;
            }
            else sum += v[i].S;

        }
        ans += v[sz(v) - 1].F;
        printf("%lld\n",ans * 2LL);
    }
    return 0;
}
