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
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int l,r,d;
        scanf("%d %d %d",&l,&r,&d);
        if(d < l or r < d)
            printf("%d\n",d);
        else{
            ll a = 1, b = 1e10;
            while(b - a > 1){
                ll mid = (a + b) >> 1;
                if(mid * d <  l or mid * d > r)
                    b = mid;
                else
                    a = mid;
            }
            printf("%lld\n",b * d);
        }
    }
    return 0;
}
    
