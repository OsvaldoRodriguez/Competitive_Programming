#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ii pair<long long,int>
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
const int N = 2 * 1e5 + 5;
const int mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        ll a,b,k;
        scanf("%lld %lld %lld",&a,&b,&k);
        while(a % k != 0)
            a++;
        ll d = 0;
        ll sd = 0;
        while(a <= b){
            ll i = 1;
            for(;i * i < a; i++){
                if(a % i == 0){
                    d += 2;
                    sd += i;
                    sd += (a / i);
                }
            }
            if(i * i == a){
                d++;
                sd += i;
            }
            a += k;
        }
        printf("%lld %lld\n",d,sd);
    }
    return 0;
}
