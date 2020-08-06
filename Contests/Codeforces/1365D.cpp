#include <bits/stdc++.h>
#define fin ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ii pair<int,int>
#define F first
#define S second
#define pb push_back
#define pf push_front
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define fore(i,a,b) for(int i = a;i < b; i+= 1)
#define forr(i,a) for(int i = a; i >= 0; i--)
#define fori(i,m) for(auto i = m.begin(); i != m.end(); i++) 
#define w(t) while(t--)
#define sz(s) int(s.size())
#define cls(a,car) memset(a,car,sizeof (a))
#define db(x) cerr << #x << " is " << x << '\n'
#define FL freopen("in", "r", stdin),freopen("out", "w", stdout);
#define time cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n"
#define angle(x) double(x * acos(-1) / 180.0)
using namespace std;
typedef unsigned long long ll;
typedef vector<int> vi;
typedef vector<ii> vii;
const int N = 2 * 1e5 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
const double E = 1e-9;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
char v[55][55];
int vis[55][55];
int n, m;
void bfs(int x, int y){
    queue<int> q;
    q.push(x);
    q.push(y);
    vis[x][y] = 1;
    if(v[x][y] != '#')
    while(sz(q)){
        int a = q.front();q.pop();
        int b = q.front();q.pop();
        fore(i, 0, 4){
            int a1 = a + dx[i];
            int b1 = b + dy[i];
            if(a1 >= 0 && a1 < n && b1 >= 0 && b1 < m && v[a1][b1] != '#' && vis[a1][b1] == -1){
                q.push(a1);
                q.push(b1);
                vis[a1][b1] = 1;
            }
        }
    }
}
int main(){
    //FL;
    fin;
    int t;
    cin >> t;
    w(t){
        cin >> n >> m;
        fore(i, 0, n)fore(j, 0, m){
            cin >> v[i][j];
            vis[i][j] = -1;
        }
        fore(i, 0, n){
            fore(j, 0, m){
                if(v[i][j] == 'B'){
                    fore(k, 0, 4){
                        int u = i + dx[k];
                        int w = j + dy[k];
                        if(u >= 0 && u < n && w >= 0 && w < m && v[u][w] == '.')
                            v[u][w] = '#';
                        
                    }
                }
            }
        }
        
            bfs(n - 1, m - 1);
            string ans = "Yes";
            fore(i, 0, n){
                fore(j, 0, m){
                    if(v[i][j] == 'G'){
                        if(vis[i][j] == -1)
                            ans = "No";
                    }
                    if(v[i][j] == 'B'){
                        if(vis[i][j] == 1)
                            ans = "No";
                    }
                }
            }
            cout << ans << '\n';
       

    }

    time;
    return 0;
}       
