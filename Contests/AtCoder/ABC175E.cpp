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
const int N = 3e3 + 5;
const ll mod = 1e9 + 7;
const double E = 1e-9;
int dx[] = {1, 0}, dy[] = {0, 1};
//int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
//int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
int r, c, k;
int arr[N][N];
ll dp[N][N][4];
ll f(int i, int j, int row){
    if(i + 1 == r && j + 1 == c){
        if(row < 3)
            return arr[i][j];
        return 0;
    }
    ll &ans = dp[i][j][row];
    if(ans == -1){
        ans = 0;
        for(int k = 0; k < 2; k++){
            int _i = i + dx[k];
            int _j = j + dy[k];
            if(_i >= 0 && _i < r && _j >= 0 && _j < c){
                if(!k){//down
                    if(row < 3)
                    ans = max(ans, f(_i, _j, 0) + arr[i][j]);
                    ans = max(ans, f(_i, _j, 0));                   
                }else{// right
                    if(row < 3)
                        ans = max(ans, f(_i, _j, row + 1) + arr[i][j]);
                    ans = max(ans, f(_i, _j, row));
                }
            }
        }
    }
    return ans;
}
int main(){
    FIN;
    cin >> r >> c >> k;
    for(int i = 0; i < k; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        arr[u][v] = w;
    }
    
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            for(int k = 0; k < 4; k++)
                    dp[i][j][k] = -1;
    cout << f(0, 0, 0) << '\n';
    EjecuteTime;
    return 0;
}       
