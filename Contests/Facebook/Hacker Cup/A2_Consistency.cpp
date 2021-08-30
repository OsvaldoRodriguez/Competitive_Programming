#include <bits/stdc++.h>
#define ii              pair<int,int>
#define F               first
#define S               second
#define pb              push_back
#define all(x)          (x).begin(),(x).end()
#define rall(x)         (x).rbegin(),(x).rend()
#define fore(i, a, b)   for(int i = a; i < b; i += 1)
#define forr(i, a)      for(int i = a; i >= 0; i--)
#define sz(s)           int(s.size())
#define cls(a, car)     memset(a,car,sizeof (a))
#define db(x)           cout << #x << " is " << x << '\n'
#define angle(x)        double(x * acos(-1) / 180.0)
using namespace std;
void debug(){cout << endl;}
template<typename T, typename... Args>
void debug(T a, Args... args){cout << a << " "; debug(args...);}
typedef long long   ll;
typedef vector<int> vi;
typedef vector<ii>  vii;
const int N = 2e2 + 15;
const ll mod = INT_MAX;
const double E = 1e-7;
vector<int> G[30];
bool is_vowel(char x){
    return x == 'A' or x == 'E' or x == 'I' or x == 'O' or x == 'U';
}
int dis[30][30];
vector<int> dist;
void bfs(int node, int row){
    queue<int> q;
    q.push(node);
    // dist.assign(30, -1);
    while(q.size()){
        int u = q.front();q.pop();
        for(int i = 0; i < G[u].size(); i++){
            int v = G[u][i];
            if(dis[row][v] == -1){
                dis[row][v] = dis[row][u] + 1;
                q.push(v);
            }
        }
    }

    // for(int i = 0; i < 26; i++){
    //     cout << char(i + 'A') << " " << dist[i] << endl;
    // }
    
}
void solve(){
    string str;
    cin >> str;
    for(int i = 0; i < 26; i++)
        G[i].clear();

    int n;
    cin >> n;
    string nodes;
    cls(dis, -1);
    while(n--){
        cin >> nodes;
        G[nodes[0] - 'A'].pb(nodes[1] - 'A');
    }

    // for(int i = 0; i < 26; i++){

    //     cout << char(i + 'A') << "-> ";
    //     for(int j = 0; j < G[i].size(); j++){
    //         cout << char(G[i][j] + 'A') << ", ";
    //     }
    //     cout << '\n';
    // }
    // cout << endl;
    for(int i = 0; i < 26; i++){
        bfs(i, i);
    }

    // cout << "  ";
    // for(char x = 'A'; x  <= 'Z'; x++)
    //     printf("%2c ", x);

    // cout << endl;

    // for(int i = 0; i < 26; i++){
    //     cout << char('A' + i) << ' ';
    //     for(int j = 0; j < 26; j++){
    //         // cout << dis[i][j] << ' ';
    //         printf("%2d ", dis[i][j]);
    //     }
    //     cout << '\n';
    // }

    int ans = 1e9;
    for(int i = 0; i < 26; i++){
        int cur = 0;
        bool flag = 1;
        for(char j : str){
            if(j == char(i + 'A'))
                continue;
            if(dis[j - 'A'][i] == -1)
                flag = 0;
            cur += (dis[j - 'A'][i] + 1);
        }
        if(flag == 1)
            ans = min(ans, cur);
    }
    if(ans == 1e9)
        ans = -1;
    cout << ans <<  '\n';
    
}
int main(){
    #ifdef FURY
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #endif
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++){ 
        cout << "Case #" << i << ": "; 
        solve();
    }

    #ifdef FURY
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}
