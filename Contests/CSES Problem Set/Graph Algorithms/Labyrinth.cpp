#include "bits/stdc++.h"
#define fastio      ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll          long long
#define all(_)      (_).begin(), (_).end()
#define sz(_)       int(_.size())
#define pii         pair<int, int>
using namespace std;
const int N = 2e5 + 20;
const int mod = 1e9 + 7;
const double eps = 1e-9;
// DLRU
int di[] = {1, 0, 0, -1}, dj[] = {0, -1, 1, 0};
string dir = "DLRU";
char a[1010][1010];
int vis[1010][1010];
pii parent[1010][1010];
string direction[1010][1010];
int n, m;
int endi, endj;

int bi, bj;
void dfs(int i, int j){
    // cout << i << " " << j << endl;
    if(a[i][j] == 'B'){
        cout << "llega\n";
        return;
    }

    for(int k = 0; k < 4; k++){
        int ui = i + di[k];
        int uj = j + dj[k];
        if(ui >= 0 and ui < n and uj >= 0 and uj < m and vis[i][j] == 1 + vis[ui][uj]){
            // ans = dir[k] + ans;
            dfs(ui, uj);
            return;
        }
    }
    return;
}


void bfs(int a1, int b){
    queue<int> q;
    q.push(a1);
    q.push(b);
    memset(vis, -1, sizeof vis);
    vis[a1][b] = 1;
    while(q.size()){
        int ui = q.front(); q.pop();
        int uj = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int vi = ui + di[i];
            int vj = uj + dj[i];
            if(vi >= 0 and vi < n and vj < m and vj >= 0 and vis[vi][vj] == -1 and a[vi][vj] != '#'){
                vis[vi][vj] = vis[ui][uj] + 1;
                parent[vi][vj] = {ui, uj};
                direction[vi][vj] = dir[i];
                q.push(vi);
                q.push(vj);
            }
        }
    }
}
void solve(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            if(a[i][j] == 'A'){
                bfs(i, j);
                bi = i, bj = j;
            }
            if(a[i][j] == 'B')
                endi = i, endj = j;
        }


   

    if(vis[endi][endj] != -1){
        cout << "YES\n";
        pii node = {endi, endj};
        string ans = "";

        cout << vis[endi][endj] - 1 << "\n";
        stack<string> cur;
        while(node != (pii){bi, bj}){
            cur.push(direction[node.first][node.second]);
            node = parent[node.first][node.second];
        }
        while(cur.size()){
            cout << cur.top();
            cur.pop();
        }
        cout << "\n";

    }else
        cout << "NO\n";
}

int main(){
    // fastio;
    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++)
        solve();
    return 0;
}
