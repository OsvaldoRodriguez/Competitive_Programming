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
const int N = 1e3 + 50;
const ll mod = 1e9 + 7;
const double E = 1e-9;
int G[N][N], dis[N][N];

/*
n vetex
m edges
Complexity
Time:
    floyd -> O(n ^ 3) matrix adjadency matrix
*/

void floyd_warshall(int n){
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
}
int main(){
    //FL;
    FIN;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> G[i][j];
            if(G[i][j] == 0)
                dis[i][j] = (1 << 30); // infinity
            else
                dis[i][j] = G[i][j];
        }
    }
    floyd_warshall(n);
    EjecuteTime;
    return 0;
}       