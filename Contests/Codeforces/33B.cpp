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
const double E = 1e-7;
//int dx[] = {0, -1}, dy[] = {-1, 0};
//int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
//int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
int cost[30][30];
void floyd(){
    for(int k = 0; k < 26; k++)
        for(int i = 0; i < 26; i++)
            for(int j = 0; j < 26; j++)
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
}
void solve(){
    string a, b;
    cin >> a >> b;
    for(int i = 0; i < 30; i++)
        for(int j = 0; j < 30; j++){
            cost[i][j] = 1e9;
            cost[i][i] = 0;
        }
    int q;
    cin >> q;
    string ans = "";
    while(q--){
        int w;
        char x1, x2;
        cin >> x1 >> x2 >> w;
        cost[x1 - 'a'][x2 - 'a'] = min(cost[x1 - 'a'][x2 - 'a'], w); 
    }
    int dis = 0;
    if(sz(a) != sz(b)){
        cout << -1 << '\n';
        return ;
    }
    floyd();
    fore(i, 0, sz(a)){
        if(a[i] == b[i]){
            ans += b[i];
            continue;
        }
        int cur = 1e9;
        string c = "";
        for(int j = 0; j < 26; j++){
            if(cost[a[i] - 'a'][j] + cost[b[i] - 'a'][j] < cur){
                cur = cost[a[i] - 'a'][j] + cost[b[i] - 'a'][j];
                c = char(j + 'a');
            }
        }
        ans += c;
        dis += cur;
    }
    if(sz(ans) != sz(a) or sz(ans) != sz(b)){
        cout << -1 << '\n';
        return ;
    }
    cout << dis << '\n';
    cout << ans << '\n';
}  
int main(){
    FIN;
    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++){
        solve(); 
    }
    EjecuteTime;
    return 0;
}  
