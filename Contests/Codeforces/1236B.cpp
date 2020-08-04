#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll m = 1e9 + 7;
ll POW(ll a, ll b, ll m){
    ll ans = 1;
    while(b){
        if (b & 1)
            ans = (ans % m  *  a % m) % m;
        b >>= 1;
        a = (a % m  *  a % m) % m;
    }
    return ans;
}
int main() {
    ll a,b;
    scanf("%lld%lld",&a,&b);
    printf("%lld",POW(POW(2,b,m)-1,a,m));
	return 0;
}
