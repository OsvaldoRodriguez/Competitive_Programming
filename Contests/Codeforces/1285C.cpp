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
ll GCD(ll a,ll b){
    if(b==0)return a;
    GCD(b,a%b);
}

ll LCM(ll a,ll b){
    return a*(b/GCD(a,b));
}
int main(){
    ll x;
    scanf("%lld",&x);
    ll i = 1;
    ll a = -1, b = -1;
    ll mn = (1LL << 62);
    for(;i * i < x; i++){
        if(x % i == 0){
            if(x == LCM(i,x / i) && mn > max(i,x / i)){
                a = i;
                b = x / i;
                mn = max(i,x / i);
            }
        }
    }
    if(i * i == x){
        if(x == LCM(i,x / i) && mn > max(i,x / i)){
                a = i;
                b = x / i;
                mn = max(i,x / i);
            }
    }
    if(a > b)
        swap(a,b);
    printf("%lld %lld\n",a,b);
    return 0;
}
