#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ii pair<int,int>
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define fore(i,a,b) for(int i = a;i < b; i+= 1)
#define forr(i,a) for(int i = a; i >= 0; i--)
#define fori(i,m) for(auto i = m.begin(); i != m.end(); i++) 
#define sz(s) int(s.size())
#define cls(a,car) memset(a,car,sizeof (a))
using namespace std;
typedef long long ll;
const int N = 2 * 1e5 + 50;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1; 
int main(){
    ll a,b,c;
    scanf("%lld %lld %lld",&a,&b,&c);
    ll ans = 2LL * c;
    ll aux = min(a,b);
    ans += min(a,b) * 2LL;
    a -= aux;
    b -= aux;
    if(a > 0)
        ans++;
    if(b > 0)
        ans++;
    printf("%lld\n",ans);
    return 0;
}
