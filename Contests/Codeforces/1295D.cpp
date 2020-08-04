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
ll euler(ll n){
    ll res = n;
    if(!(n & 1)){
        res -= (res >> 1);
        while(n % 2 == 0)
            n >>= 1;
    }
    for(ll i = 3; i * i <= n; i += 2){
        if(n % i == 0){
            res -= res / i;
            while(n % i == 0)
                n /= i;
        }
    }
    if(n > 1)
        res -= res / n;
    return res;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        ll a,m;
        scanf("%lld %lld",&a,&m);
        ll gcd = __gcd(a,m);
        m /= gcd;
        printf("%lld\n",euler(m));
    }
    return 0;
}
