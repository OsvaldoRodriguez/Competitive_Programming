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
#define what_is(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ii> vii;
const int N = 1 * 1e6 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
const double E = 1e-9;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
char v[1005][1005];
int vis[1005][1005];
int n, m;
void bfs(int x, int y){
    queue<int> q;
    q.push(x);
    q.push(y);
    vis[x][y] = 1;
    while(sz(q)){
        int a = q.front();q.pop();
        int b = q.front();q.pop();
        fore(i, 0, 4){
            int a1 = a + dx[i];
            int b1 = b + dy[i];
            if(a1 >= 0 && a1 < n && b1 >= 0 && b1 < m && vis[a1][b1] == -1 && v[a1][b1] == '#'){
                vis[a1][b1] = 1;
                q.push(a1);
                q.push(b1);
            }
        }
    }
}
int main(){
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    fin;
    cin >> n >> m;
    int cnt=  0;
    fore(i, 0, n)fore(j, 0, m){
        cin >> v[i][j];
        if(v[i][j] == '#')cnt++;
    }
    if(!cnt){
        cout << 0 << '\n';
        return 0;
    }
    if(n == 1 or m == 1){
        if(cnt > 0 && cnt != n * m){
            cout << -1 << '\n';
            return 0;
        }
    }
    bool w1 = 0, w2 = 0;
    bool flag = 1;
    fore(i, 0, n){
        int white_1 = 0;
        fore(j, 0, m)
            if(v[i][j] == '.')
                white_1++;
        if(white_1 == m)
            w1 = 1;
        int j = 0;
        while(j < m && v[i][j] != '#')
            j++;
        while(j < m && v[i][j] == '#')
            j++;
        while(j < m){
            if(v[i][j++] == '#'){
                flag = 0;
                break;
            }
        }
    }
    if(flag)
    fore(i, 0, m){
        int white_2 = 0;
        fore(j, 0, n)
            if(v[j][i] == '.')
                white_2++;
        if(white_2 == n)
            w2 = 1;
        int j = 0;
        while(j < n && v[j][i] != '#')
            j++;
        while(j < n && v[j][i] == '#')
            j++;
        while(j < n){
            if(v[j++][i] == '#'){
                flag = 0;
                break;
            }
        }
    }
    if(!flag)
        cout << -1 << '\n';
    else{
        if((w1 && !w2) or (!w1 && w2)){
            cout << -1 << '\n';
            return 0;
        }
        cls(vis, -1);
        int ans = 0;
        fore(i, 0, n){
            fore(j, 0, m){
                if(vis[i][j] == -1 && v[i][j] == '#'){
                    bfs(i, j);
                    ans++;
                }
            }
        }
        cout << ans << '\n';
    }
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}   
