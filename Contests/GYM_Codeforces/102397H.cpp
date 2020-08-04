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
const int N = 1 * 1e5 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
int arr[N];
ll pow1(ll a,ll b,ll m){
    ll ans = 1;
    while(b){
        if(b&1)
            ans = (ans % m * a % m) % m;
        b >>= 1;
        a = (a % m * a % m) % m;
    }
    return ans;
}
int main(){
    int n;
    scanf("%d",&n);
    fore(i,0,n){
        int x;
        scanf("%d",&x);
        arr[x]++;
    }
    ll ans = 0;
    fore(i,1,N)
        if(arr[i])
        ans = (ans % mod + pow1(2LL,(ll)arr[i],mod) - 1LL + mod ) % mod;
    printf("%lld\n",ans);
	return 0;
}
    
