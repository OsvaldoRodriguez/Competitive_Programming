#include <bits/stdc++.h>
#define FIN         ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ii          pair<int,int>
#define F           first
#define S           second
#define pb          push_back
#define all(x)      (x).begin(),(x).end()
#define rall(x)     (x).rbegin(),(x).rend()
#define fore(i,a,b) for(int i = a;i < b; i+= 1)
#define forr(i,a)   for(int i = a; i >= 0; i--)
#define fori(i,m)   for(auto i = m.begin(); i != m.end(); i++) 
#define w(t)        while(t--)
#define sz(s)       int(s.size())
#define cls(a,car)  memset(a,car,sizeof (a))
#define db(x)       cerr << #x << " is " << x << '\n'
#define FL          freopen("input.txt", "r", stdin),freopen("output.txt", "w", stdout);
#define EjecuteTime cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n"
#define angle(x)    double(x * acos(-1) / 180.0)
using namespace std;
typedef long long   ll;
typedef vector<int> vi;
typedef vector<ii>  vii;
const int N = 1e5 + 50;
const ll mod = 1e9 + 7;
const double E = 1e-9;

// counts numbers of integers between [1, n] which are coprime with to n
int phi[N];
int euler(int x){
    int ans = x;
    if(x % 2 == 0){
        ans -= ans / 2;
        while(x % 2 == 0)
            x /= 2;
    }
    for(int i = 3; i * i <= x; i += 2){
        if(x % i == 0){
            ans -= ans / i;
            while(x % i == 0)
                x /= i;
        }
    }
    if(x > 1)
        ans -= ans / x;
    return ans;
}
// euler [1, N] in O(n log log n)
// same idea of sieve of eratosthenes
int _euler(){
    phi[0] = 0;
    phi[1] = 1;
    for(int i = 2; i < N; i++)
        phi[i] = i;
    for(int i = 2; i < N; i++)
        if(phi[i] == i)
            for(int j = i; j < N; j += i)
                phi[j] -= phi[j] / i;
}

// divisor property
// sum euler(d) = n
// the sum is over all positive divisors d of n
// ej n = 10 -> d = 1, 2, 5, 10, then
// euler(1) + euler(2) + euler(5) + euler(10) == 1 + 1 + 4 + 4 = 10 
int main(){
    //FL;
    FIN;
    _euler();
    for(int i = 1; i <= 40; i++)
        cout << euler(i) << ' ';
    cout << '\n';
    for(int i = 1; i <= 40; i++)
        cout << phi[i] << ' ';


    EjecuteTime;
    return 0;
}       
