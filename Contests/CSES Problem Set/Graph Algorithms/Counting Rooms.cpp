#include "bits/stdc++.h"
#define fastio      ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll          long long
#define all(_)      (_).begin(), (_).end()
#define sz(_)     int(_.size())
using namespace std;
const int N = 2e5 + 20;
const int mod = 1e9 + 7;
const double eps = 1e-9;
int di[] = {1, 0, -1, 0}, dj[] = {0, 1, 0, -1};
// int di[] = {2, 1, -2, -1, -2, -1,  1,  2, 3, 1, -3, -1, -3, -1,  1,  3};
// int dj[] = {1, 2,  1,  2, -1, -2, -2, -1, 1, 3,  1,  3, -1, -3, -3, -1};

// int dx[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

char a[1010][1010];
int vis[1010][1010];
int n, m;
void dfs(int i, int j){
    vis[i][j] = 1;
    for(int k = 0; k < 4; k++){
        int x = i + di[k];
        int y = j + dj[k];
        if(x >= 0 and x < n and y >= 0 and y < m and vis[x][y] == 0 and a[x][y] == '.')
            dfs(x, y);
    } 
}
void solve(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];

    int ans = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(!vis[i][j] and a[i][j] == '.'){
                dfs(i, j);
                ans++;
            }
    cout << ans << "\n";
}

int main(){
    fastio;
    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++)
        solve();
    return 0;
}
