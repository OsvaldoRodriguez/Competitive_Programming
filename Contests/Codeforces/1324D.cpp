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
const int N = 2 * 1e5 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
//freopen("","r",stdin);
//freopen("","w",stdout);
int main(){
    int n;
    scanf("%d",&n);
    vector<int> a(n),b(n),c(n);
    for(auto &i:a)cin >> i;
    for(auto &i:b)cin >> i;
    int pos = -1;
    fore(i,0,n)
        c[i] = a[i] - b[i];
    sort(all(c));
    ll ans = 0;
    fore(i,0,n){
        if(c[i] <= 0)continue;
        ll pos = lower_bound(c.begin(),c.end(),-c[i] + 1) - c.begin();
        ans += (ll)i - pos;
    }
    printf("%lld\n",ans);
    return 0;
}
