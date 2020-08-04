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
const int N = 2 * 1e5 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
ll v[N];
int main(){
    int x,n,k;
    scanf("%d%d",&n,&k);
    int mn = (1 << 30);
    ll b = 0;
    fore(i,0,n){
        scanf("%d",&x);
        v[x]++;
        mn = min(mn,x);
    }
    for(int i = N - 1; i >= 0; i--)
        v[i] += v[i + 1];
    ll ans = 0;
    ll cnt = 0;
    for(int i = N - 1; i > mn; i--){
        cnt += v[i];
        if(cnt > k){
            ans++;
            cnt = v[i];
        }
    }
    if(cnt)
        ans++;
    printf("%lld\n",ans);
    
    return 0;
}
