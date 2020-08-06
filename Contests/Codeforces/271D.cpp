#include <bits/stdc++.h>
#define fin         ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
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
#define FL          freopen("in", "r", stdin),freopen("out", "w", stdout);
#define EjecuteTime cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n"
#define angle(x)    double(x * acos(-1) / 180.0)
using namespace std;
typedef long long   ll;
typedef vector<int> vi;
typedef vector<ii>  vii;
const int N = 2 * 1e5 + 5;
const ll mod = 1e9 + 7;
const double E = 1e-9;
//int dx[] = {1, 0}, dy[] = {0, 1};
//int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
struct Hash{
    //primos 999727999,1070777777
    // B 33 , 997 
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
    void build(const vector<int> &v){
        long long hash = 0, POT = 1;

        for(int i = 0; i < N_MAX; i++){
            hash = (hash + (1LL * v[i] * POT) % mod) % mod;
            h1[i] = hash;
            POT = (POT * B) % mod;
        }
        hash = 0;
        POT = 1;
        for(int i = N_MAX - 1;i >= 0; i--){
            hash = (hash + (1LL * v[i] * POT) % mod) % mod;
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

string str;

set<pair<ll, ll> > s;
int fre[30];
int acc[2000];
int main(){
    //FL;
    fin;
    string pat;
    int lim;
    cin >> str >> pat >> lim;
    fore(i, 0, sz(pat))
        fre[i] = pat[i] - '0';
    Hash h(sz(str), 33, ll(1e9 + 7));
    vi v(sz(str));
    fore(i, 0, sz(str))
        v[i] = str[i] - 'a' + 1;
    h.build(v);
    fore(i, 0, sz(str))
        if(!fre[str[i] - 'a']){    
            acc[i + 1] = 1;
        }
    fore(i, 2, sz(str) + 1)
        acc[i] += acc[i - 1];

    fore(i, 0, sz(str)){
        fore(j, i, sz(str)){
            ll hsh1 = h.getLR(i, j);
            ll hsh2 = h.getRL(i, j);
            int aux = 0;
            
            int L;
            if(i == 0)
                L = 0;
            else
                L = acc[i];
            aux = acc[j + 1] - L;
            if(aux <= lim)
                s.insert({hsh1, hsh2});
        }
    }
    cout << sz(s) << '\n';
    EjecuteTime;
    return 0;
}       
