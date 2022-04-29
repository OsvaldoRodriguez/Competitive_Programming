#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 550;
const ll mod = 1e9 + 7;
vector<int> G[N];
int vis[N];
int main(){
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m, s;
        cin >> n >> m >> s;
        for(int i = 0; i < n; i++){
            vis[i] = -1;
            G[i].clear();
        }
        int u, v;
        for(int i = 0; i < m; i++){
            cin >> u >> v;
            --u;--v;
            G[u].push_back(v);
            G[v].push_back(u);
        }

        vector<pair<int, int>> soldiers;
        while(s--){
            int soldier, strength;
            cin >> soldier >> strength;
            soldier--;
            soldiers.push_back({soldier, strength});
        }

        bool flag = true;
        int color = 0;
        for(int i = 0; i < soldiers.size(); i++){
            color++;
            queue<pair<int, int>> q;
            if(soldiers[i].second > 0)
                q.push(soldiers[i]);
            if(vis[soldiers[i].first] != -1){
                flag = false;
                break;
            }
            vis[soldiers[i].first] = color;
            while(q.size() > 0){
                pair<int, int> u = q.front();q.pop();
                for(int v : G[u.first]){
                    if(u.second - 1 >= 0){
                        if(vis[v] == -1){    
                            vis[v] = color;
                            q.push({v, u.second - 1});
                        
                        }else if(vis[v] != color){
                            flag = false;
                        }
                    }
                }
            }
        }

        for(int i = 0; i < n; i++){
            if(vis[i] == -1)
                flag = false;
        }

        cout << (flag ? "Yes" : "No") << '\n';


    }
    return 0;
 
}
