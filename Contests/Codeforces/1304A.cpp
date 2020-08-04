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
ll x,y,a,b;
ll f(ll t){
    return x + t * a <= y - t * b;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%lld %lld %lld %lld",&x,&y,&a,&b);
        ll a1 = -1, b1 = 1e9, mid;
        while(b1 - a1 > 1){
            mid = (a1 + b1) >> 1;
            if(f(mid))
                a1 = mid;
            else
                b1 = mid;
        }
        printf("%lld\n",x + a1 * a == y - a1 * b ?a1:-1);
    }
    return 0;
}
    
