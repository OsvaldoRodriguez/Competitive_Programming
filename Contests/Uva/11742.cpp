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
typedef unsigned long long   ll;
typedef vector<int> vi;
typedef vector<ii>  vii;
const int N = 1e5 + 5;
const ll mod = 1e9 + 7;
const double E = 1e-9;
//int dx[] = {0, -1}, dy[] = {-1, 0};
//int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
//int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
void solve(){
    int n, m;
    while(cin >> n >> m && (n or m)){
        int v[n];
        int A[m], B[m], C[m];
        iota(v, v + n, 0);
        for(int j = 0; j < m; j++)
            cin >> A[j] >> B[j]  >> C[j];
        
        int ans = 0;
        int cnt = 0;
        do{
            int x = -1, y = -1;
            bool flag = 1;
            for(int j = 0; j < m; j++){
                for(int i = 0; i < n; i++){
                    if(v[i] == A[j])
                        x = i;
                    if(v[i] == B[j])
                        y = i;
                }
                if(C[j] < 0){
                    if(abs(x - y) < abs(C[j]))
                        flag = 0;
                }else{
                    if(abs(x - y) > C[j])
                        flag = 0;
                }
            }
            if(flag)
                ans++;
            cnt++;
        }while(next_permutation(v, v + n)); 
        if(!m)
            ans = cnt;
        cout << ans << '\n';
    }
}
int main(){
    FIN;
    int t = 1;
    for(int i = 1; i <= t; i++){
        solve();
    }
    EjecuteTime;
    return 0;
}       
