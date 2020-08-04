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
const int N = 1 * 1e5 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
ll v[N];
ll f(ll x){
    return x * (x - 1) / 2;
}
int main(){
    v[1] = 0;
    v[2] = 1;
    fore(i,3,N)
        v[i] = v[i - 1] + i - 2;
    ll n,m;
    scanf("%lld %lld",&n,&m);
    if(n == 1){
        printf("1 1\n");
        return 0;
    }
    if(m >= v[n])
        printf("0 0\n");
    else{
        ll a = -1, b = 100000000, mid;
        while(b - a > 1){
            mid = (a + b) / 2;
            if(f(mid) >= m)
                b = mid;
            else
                a = mid;
        }
        ll mx =  n - b;
        // min
        ll aux = (n + 1)/ 2;
        if(m >= aux)
            printf("0 ");
        else
            printf("%lld ",n - m * 2LL);
        
            printf("%lld\n",mx);
    }
    return 0;
}
