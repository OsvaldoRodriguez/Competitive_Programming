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
#define FI          freopen("input.txt", "r", stdin)
#define FO          freopen("output.txt", "w", stdout)
#define EjecuteTime cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n"
#define angle(x)    double(x * acos(-1) / 180.0)
using namespace std;
typedef long long   ll;
typedef vector<int> vi;
typedef vector<ii>  vii;
const int N = 2e3 + 5;
const ll mod = 1e9 + 7;
const double E = 1e-9;
//int dx[] = {0, -1}, dy[] = {-1, 0};
//int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
//int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
ll v[N][N], D1[2 * N], D2[2 * N];
void solve(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> v[i][j];
            D1[i + j] += v[i][j];
            D2[i - j + n - 1] += v[i][j];
        }
    }
    ii a = {-1, -1}, b = {-1, -1};
    ll sum1 = -1, sum2 = -1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            ll aux = D1[i + j] + D2[i - j + n - 1] - v[i][j];
            ii cur = {i, j};
            if((i + j) & 1){
                if(aux > sum1){
                    a = cur;
                    sum1 = aux;
                }
            }else{
                if(aux > sum2){
                    b = cur;
                    sum2 = aux;
                }
            }
        }
    }
    cout << sum2 + sum1 << '\n';
    cout << a.F + 1 << " " << a.S + 1 << " " << b.F + 1 << " " << b.S + 1 << '\n';

}
int main(){
    FIN;
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    EjecuteTime;
    return 0;
}       
