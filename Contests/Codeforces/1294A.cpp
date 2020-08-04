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
const int mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
bool f(int x){
    if(x == 2)
        return 1;
    if(!(x & 1) or x < 2)
        return 0;
    for(int i = 3; i * i <= x; i += 2)
        if(x % i == 0)
            return 0;
    return 1;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        ll a,b,c,n;
        scanf("%lld%lld %lld%lld",&a,&b,&c,&n);
        ll mx = max(a,max(b,c));
        n -= (mx - a);
        n -= (mx - b);
        n -= (mx - c);
        if(n < 0){
            printf("NO\n");
            continue;
        } 
        if(n % 3 == 0)  
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
