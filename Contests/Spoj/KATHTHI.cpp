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
const int N = 2 * 1e5 + 5;
const ll mod = 1e9 + 7;
const double E = 1e-9;
//int dx[] = {1, 0}, dy[] = {0, 1};
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy[] = {0 ,1, 1, 1, 0, -1, -1, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
int n, m;
char v [1010][1010];
int dis[1010][1010];
int main(){
    //FL;
    //FIN;
    int t;
    scanf("%d", &t);
    while(t--){
        //cin >> n >> m;
        scanf("%d %d", &n, &m);
        char cad[m + 1];
        for(int i = 0; i < n; i++){
            scanf("%s", v[i]);
        }
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                dis[i][j] = 1e6 + 50;
        dis[0][0] = 0;
        deque<pair<int, int> > q;
        q.push_back({0, 0});
        while(!q.empty()){
            int a = q.front().F;
            int b = q.front().S;
            q.pop_front();
            for(int i = 0; i < 4; i++){
                int a1 = a + dx[i];
                int b1 = b + dy[i];
                int cost = v[a][b] != v[a1][b1];
                if(a1 >= 0 && a1 < n && b1 >= 0 && b1 < m && dis[a][b] + cost < dis[a1][b1]){
                    dis[a1][b1] = dis[a][b] + cost;
                    
                    if(cost == 0){
                        q.push_front({a1, b1});
                    }else
                        q.push_back({a1, b1});
                }
            }
        }
        printf("%d\n",dis[n - 1][m - 1]);
    }
    //EjecuteTime;
    return 0;
}
