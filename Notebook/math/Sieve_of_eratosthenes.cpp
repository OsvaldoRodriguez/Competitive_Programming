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
//int dx[] = {0, -1}, dy[] = {-1, 0};
//int _dx[] = {0, 1}, _dy[] = {1, 0};
//int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
//int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)

int v[N];// 0 is prime
bitset<N> pr; // 0 is prime

void sieve(){ //O(n log log n)
    v[0] = v[1] = 1;
    for(int i = 2; i * i < N; i++)
        if(!v[i])
            for(int j = i * i; j < N; j += i)
                v[j] = 1;
}

void sieveBitSet(){
    pr[0] = pr[1] = 1;
    for(int i = 2; i * i < N; i++)
        if(!pr[i])
            for(int j = i * i; j < N; j += i)
                pr[j] = 1;
}

void fact(){
    for(int i = 1; i < N; i++)
        v[i] = i;
    for(int i = 2; i * i < N; i++)
        if(v[i] == i)
            for(int j = i * i; j < N; j += i)
                if(v[j] == j)
                    v[j] = i; // smallest prime factor
}

map<int, int> recFact(int x){
    map<int, int> m;
    while(v[x] != 1){
        m[v[x]]++;
        x /= v[x];
    }
    return m;
}
int main(){
    //FL;
    FIN;
    int x = 93848;
    fact();
    auto cur = recFact(x);
    fori(i, cur)
    cout << i->F << " " << i->S << '\n';
    EjecuteTime;
    return 0;
}       
