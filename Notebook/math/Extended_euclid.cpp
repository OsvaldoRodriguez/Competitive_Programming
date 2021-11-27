#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// ecuaciones diofanticas
struct dxy{
    ll d, x, y;
    dxy() : d(0), x(0), y(0){}
};
ll GCD(ll a, ll b){return b == 0 ? a : GCD(b, a % b);}
ll LCM(ll a, ll b){return a / GCD(a, b) * b;}
dxy GCD_ext(ll a, ll b){
    dxy r;
    if(b == 0){
        r.d = a;
        r.x = 1;
        r.y = 0;
        return r;
    }
    dxy t = GCD_ext(b, a % b);
    r.d = t.d;
    r.x = t.y;
    r.y = t.x - (a / b) * t.y;
    return r;

}

ll f(ll n, ll a, ll b, ll x, ll y, dxy d){
    return a * (n * x) / d.d + b * (n * y) / d.d;
}
int main(){
    ll a, b, n;
    scanf("%lld %lld %lld", &a, &b, &n);
    dxy D = GCD_ext(a, b);
    
    printf("%lld %lld %lld\n",D.x, D.y, D.d);
    //encontrando todas sus soluciones
    for(int k = 0; k < 2000; k++){
        ll x_0 = D.x + b / D.d * k;
        ll y_0 = D.y - a / D.d * k;
        ll x = n * x_0 / D.d;
        ll y = n * y_0 / D.d;
        printf("%lld %lld %lld\n", x, y, a * x + b * y);

    }
    
    return 0;
}       
