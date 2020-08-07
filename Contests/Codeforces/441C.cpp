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
const int N = 1 * 1e2 + 50;
const ll mod = 1e9 + 7;
const double E = 1e-9;
//int dx[] = {1, 0}, dy[] = {0, 1};
//int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
//int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
int main(){
    //FL;
    FIN;
    int n, m, k;
    cin >> n >> m >> k;
    vii ans;
    for(int i = 1; i <= n; i++){
        if(!(i & 1)){
            for(int j = m; j >= 1; j--)
                ans.pb({i, j});
        }
        else{
            for(int j = 1; j <= m; j++)
                ans.pb({i, j});
        }
    }
    int j = 0;
    for(int i = 1; i <= k; i++){
        if(i == k){
            cout << sz(ans) - j << ' ';
            while(j < sz(ans)){
                cout << ans[j].F << ' ' << ans[j].S << ' ';
                j++;
            }
        }else{
            cout << 2 << " " << ans[j].F << " " << ans[j].S << " " << ans[j + 1].F << " " << ans[j + 1].S << '\n';
            j += 2;
        }
    }
    EjecuteTime;
    return 0;
}       
