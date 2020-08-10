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
const int N = 1e5 + 5;
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
int dp[5 * N][1 << 3];
short v[3][5 * N];
int n, m;
int f(int i, int mask){
    if(i == m)return 0;
    int &ans = dp[i][mask];
    if(ans == -1){
        ans = 1e9;
        for(int j = 0; j < (1 << n); j++){
            int cost = 0;
            for(int k = 0; k < n; k++){
                int cur = (j & (1 << k)) != 0;
                cost += (v[k][i] != cur);
            }
            // mask
            int up, down, sum_up, sum_down;
            if(n == 3){
                up = ((mask & (1 << 2)) > 0) + ((mask & (1 << 1)) > 0);
                down = ((mask & (1 << 1)) > 0) + ((mask & (1 << 0)) > 0);

                sum_up = ((j & (1 << 2)) > 0) + ((j & (1 << 1)) > 0);
                sum_down = ((j & (1 << 1)) > 0) + ((j & (1 << 0)) > 0);


                 if(((up + sum_up) & 1) && ((down + sum_down) & 1)){
                    ans = min(ans, cost + f(i + 1, j));
                }
            }else{
                up = ((mask & (1 << 1)) > 0) + ((mask & (1 << 0)) > 0);
                down = sum_down = 0;
                sum_up = ((j & (1 << 1)) > 0) + ((j & (1 << 0)) > 0);
                if((up + sum_up) & 1)
                    ans = min(ans, cost + f(i + 1, j));

            }

           
            
        }
    }
    return ans;
}
int main(){
    FIN;
    cin >> n >> m;
    char x;
    if(n > 3){
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> x;
        cout << -1 << '\n';
    }
    else{
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                cin >> x;
                v[i][j] = (x == '1' ? 1 : 0);
            }
        
        if(n == 1){cout << 0 << '\n';return 0;}
        
        cls(dp, -1);
        int ans = 1e9;
        for(int i = 0; i < (1 << n); i++){
            int cost = 0;
            for(int j = 0; j < n; j++){
                int cur = ((i & (1 << j)) > 0);
                cost += (v[j][0] != cur);
            }
            ans = min(ans, f(1, i) + cost);
        }
        cout << ans << '\n';
    }
    EjecuteTime;
    return 0;
}       
