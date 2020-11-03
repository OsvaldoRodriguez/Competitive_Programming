
#include <bits/stdc++.h>
#define ii              pair<int,int>
#define F               first
#define S               second
#define pb              push_back
#define all(x)          (x).begin(),(x).end()
#define rall(x)         (x).rbegin(),(x).rend()
#define fore(i, a, b)   for(int i = a; i < b; i += 1)
#define forr(i, a)      for(int i = a; i >= 0; i--)
#define sz(s)           int(s.size())
#define cls(a,car)      memset(a,car,sizeof (a))
#define db(x)           cerr << #x << " is " << x << '\n'
#define angle(x)        double(x * acos(-1) / 180.0)
using namespace std;
typedef long long   ll;
typedef vector<int> vi;
typedef vector<ii>  vii;
const int N = 2e2 + 5;
const ll mod = 1e9 + 7;
const double E = 1e-7;
const int oo = 1e9;
struct Hash{
    //primos 999727999,1070777777
    long long B, mod;
    int N_MAX;
    vector<long long> h1, h2, potIn;
    Hash(int N, long long Base, long long MOD){
        B = Base;
        mod = MOD;
        N_MAX = N;
        h1.resize(N_MAX);
        h2.resize(N_MAX);
        potIn.resize(N_MAX);
        long long POT = 1LL;
        for(int i = 0; i < N_MAX; i++){
            potIn[i] = POW(POT, mod - 2);
            POT = (POT * B) % mod;
        }

    }
    void build(const string &v){
        long long hash = 0, POT = 1;

        for(int i = 0; i < N_MAX; i++){
            hash = (hash + (1LL * (v[i] - 'a' + 1) * POT) % mod) % mod;
            h1[i] = hash;
            POT = (POT * B) % mod;
        }
        hash = 0;
        POT = 1;
        for(int i = N_MAX - 1; i >= 0; i--){
            hash = (hash + (1LL * (v[i] - 'a' + 1) * POT) % mod) % mod;
            h2[i] = hash;
            POT = (POT * B) % mod;
        }
    }
    long long POW(long long a, long long b){
        long long ans = 1;
        while(b){
            if(b & 1)
                ans = (ans * a) % mod;
            a = (a * a) % mod;
            b >>= 1LL;
        }
        return ans;
    }
    long long getLR(int i, int j){
        if(i == 0)
            return h1[j];
        return (((h1[j] - h1[i - 1] + mod) % mod) * potIn[i]) % mod;
    }
    long long getRL(int i, int j){
        if(j == N_MAX - 1)
            return h2[i];
        return (((h2[i] - h2[j + 1] + mod) % mod) * potIn[N_MAX - j - 1]) % mod;
    }
};

void solve(){
    string str;
    cin >> str;
    Hash H(sz(str), 997, mod);
    H.build(str);
    for(int i = sz(str) - 1; i >= 0; i--){
        if(H.getRL(0, i) == H.getLR(0, i)){
            cout << i + 1 << '\n';
            return;
        }
    }
}
int main(){
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++)
        solve();

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}
