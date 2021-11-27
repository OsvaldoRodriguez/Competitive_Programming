#include <bits/stdc++.h>
using namespace std;
typedef long long   ll;
const int N = 3e5 + 50;
ll gcd(ll a, ll b){
    return !b ? a : gcd(b, a % b);
}
ll mulmod(ll a, ll b, ll m){
    ll r = a * b - (ll)((long double)a * b / m + .5) * m;
    return r < 0 ? r + m : r;
}

ll POW(ll a, ll b, ll m){
    ll ans = 1;
    while(b){
        if(b & 1)
            ans = mulmod(ans, a, m);
        b >>= 1;
        a = mulmod(a, a, m);
    }
    return ans;
}
//2 ^ s * d
bool is_prime_prob(ll n, ll a){
    if(n == a) return true;
    ll s = 0, d = n - 1;
    while(!(d & 1))d >>= 1, s++;
    ll x = POW(a, d, n);
    if(x == 1 or (x + 1 == n))return true;
    for(int i = 0; i < s - 1; i++){
        x = mulmod(x, x, n);
        if(x == 1)return false;
        if(x + 1 == n)return true;
    }
    return false;
}

bool rabin(ll n){// true if is prime
    if(n == 1)return false;
    int arr[] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
    for(int i = 0; i < 9; i++)
        if(!is_prime_prob(n, arr[i]))
            return false;
    return true;
}

ll rho(ll n){
    if(!(n & 1))return 2;
    ll x = 2, y = 2, d = 1;
    ll c = rand() % n + 1;
    while(d == 1){
        x = (mulmod(x, x, n) + c) % n;
        y = (mulmod(y, y, n) + c) % n;
        y = (mulmod(y, y, n) + c) % n;
        if(x >= y)
            d = gcd(x - y, n);
        else
            d = gcd(y - x, n);
    }
    return d == n ? rho(n) : d;
}

void fact(ll n, map<ll, int> &f){
    if(n == 1)return;
    if(rabin(n)){
        f[n]++;
        return ;
    }
    ll q = rho(n);
    fact(q, f);
    fact(n / q, f);
}
void solve(){
    ll x;
    cin >> x;
    map<ll, int> f;
    fact(x, f);
    bool flag = 0;
    for(auto i : f){
        for(int j = 0; j < i.second; j++){    
            if(flag)
                cout << " ";
            cout << i.first;
            flag = 1;
        }
    }
    cout << '\n';
}
int main(){
    solve();
    return 0;
}  
