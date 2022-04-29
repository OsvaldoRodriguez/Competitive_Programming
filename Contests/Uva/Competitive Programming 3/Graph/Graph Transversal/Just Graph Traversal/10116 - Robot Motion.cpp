#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 550;
const ll mod = 1e9 + 7;
int n, m;
char A[15][15];
int vis[15][15];
int dist[15][15];
bool flag;
stack<pair<int, int> > nodes;

bool ok(int a, int b){
    return a >= 0 and a < n and b >= 0 and b < m;
}

int ANS1, CYCLE;
void dfs(int x, int y, int dis){
    // cout << x + 1 << " " << y + 1 << " " << dis << endl;
    nodes.push({x, y});
    dist[x][y] = dis;
    int xx, yy;
    // S

    if(A[x][y] == 'S'){
        xx = x + 1;
        yy = y;
    }
    if(A[x][y] == 'N'){
        xx = x - 1;
        yy = y;
    }
    if(A[x][y] == 'E'){
        xx = x;
        yy = y + 1;
    }
    if(A[x][y] == 'W'){
        xx = x;
        yy = y - 1;
    }

    if(ok(xx, yy)){
        if(vis[xx][yy] == -1){
            vis[xx][yy] = 0;
            dfs(xx, yy, dis + 1);
            vis[xx][yy] = 1;
        }else{
            if(vis[xx][yy] == 0){
                ANS1 = dist[xx][yy];
                CYCLE = nodes.size() - ANS1;
                // cout << " pila " << nodes.size() << '\n';
                flag = true;
            }
        }
    }else if(!flag)
        ANS1 = dis;

    
    

}
int main(){
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int col;
    while(cin >> n >> m >> col and (n or m or col)){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> A[i][j];
            }
        }
        while(nodes.size())
            nodes.pop();
        flag = false;
        ANS1 = CYCLE = 0;
        memset(vis, -1, sizeof vis);
        vis[0][col - 1] = 0;
        dfs(0, col - 1, 0);    
        if(!flag)
            cout << ANS1 + 1 << " step(s) to exit\n";
        else{
            cout << (ANS1) << " step(s) before a loop of " << CYCLE << " step(s)\n";
        }
        // cout << ANS1 << " " << CYCLE << '\n';
    }
 
    return 0;
 
}
