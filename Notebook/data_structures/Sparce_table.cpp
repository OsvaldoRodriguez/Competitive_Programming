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
int A[N], ST[20][N];
int n;
int f(int a, int b){return __gcd(a, b);}
void build(){
    for(int i = 0; i < n; i++)
        ST[0][i] = A[i];
    for(int i = 1; (1 << i) <= n; i++){// i <= log_2(n)
        for(int j = 0; j < n - (1 << i) + 1; j++){
            int a = j;
            int b = j + (1 << (i - 1));
            ST[i][j] = f(ST[i - 1][a], ST[i - 1][b]);
        }
    }
}
int query(int I, int J){
    int a = 31 - __builtin_clz(J - I + 1);
    int x = ST[a][I];
    int y = ST[a][J - (1 << a) + 1];
    return f(x, y);
}
int main(){
    //FL;
    FIN;
    int q;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> A[i];
    int l, r;
    build();
    
    cin >> q;
    while(q--){
        cin >> l >> r;
        cout << query(l - 1, r - 1) << '\n';
    }   
    EjecuteTime;
    return 0;
}       