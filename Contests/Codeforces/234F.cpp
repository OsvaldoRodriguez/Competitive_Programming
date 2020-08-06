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
const int N = 1 * 1e5 + 5;
const ll mod = 1e9 + 7;
const double E = 1e-9;
int dx[] = {1, 0}, dy[] = {0, 1};
//int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
int add(int a, int b){return  a + b > mod ? a + b - mod : a + b;}
int mul(int a, int b){return a * b > mod ? a * b % mod : a * b;}
int v[202];
int n, r, g;
int dp[2][2][4 * 10010];
int query(int i, int j){
    if(i == 0)
        return v[j];
    return v[j] - v[i - 1];
}
// 0 red, 1 green
int f(int i, bool last, int red){
    int green = v[i - 1] - red;
    //if(red > r or green > g)
        //return 1e9;
    if(i == n + 1)
        return 0;
    int &ans = dp[i][last][red];
    if(ans == -1){
        ans = 1e9;
        int auxred = query(i, i);
        int cost = min(query(i, i), query(i - 1, i - 1));
        if(!last){// red
            if(red + auxred <= r)
                ans = min(ans, f(i + 1, 0, red + auxred));
            if(green + auxred <= g)
            ans = min(ans, f(i + 1, 1, red) + cost);
        }else{// green
            if(green + auxred <= g)
            ans = min(ans, f(i + 1, 1, red));
            if(red + auxred <= r)
            ans = min(ans, f(i + 1, 0, red + auxred) + cost);
        }
    }return ans;
}
int main(){
    FL;
    FIN;
    cin >> n >> r >> g;
    fore(i, 1, n + 1)cin >> v[i]; 
    fore(i, 2, n + 1)v[i] += v[i - 1];
    //OPTIMIZANDO MEMORIA
    for(int i = n + 1; i >= 1; i--){
        for(int last = 0; last < 2; last++){
            for(int red = 0; red <= r; red++){
                int &ans = dp[i & 1][last][red];    
                if(i == n + 1){
                    ans = 0;
                    continue;
                }
                ans = 1e9;
                int green = v[i - 1] - red;
                int auxred = query(i, i);
                int cost = min(query(i, i), query(i - 1, i - 1));
                if(!last){// red
                    if(auxred + red <= r)
                        ans = min(ans, dp[(i + 1) & 1][0][red + auxred]);
                    if(green + auxred <= g)
                        ans = min(ans, dp[(i + 1) & 1][1][red] + cost);
                }else{// green
                    if(auxred + green <= g)
                        ans = min(ans, dp[(i + 1) & 1][1][red]);
                    if(auxred + red <= r)
                        ans = min(ans, dp[(i + 1) & 1][0][red + auxred] + cost);

                }
            }
        }
    }
    int ans = min(dp[1 & 1][0][0], dp[1 & 1][1][0]);
    if(ans == 1e9)
        ans = -1;
    cout << ans << '\n';
    /*cls(dp, -1);
    int ans2 = min(f(1, 0, 0), f(1, 1, 0));
    if(ans2 == 1e9)
        ans2 = -1;
    db(ans2);*/
    EjecuteTime;
    return 0;
}       
