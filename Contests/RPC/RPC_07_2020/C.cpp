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
const int N = 3e5 + 50;
const ll mod = 1e9 + 7;
const double E = 1e-9;
//int dx[] = {0, -1}, dy[] = {-1, 0};
//int _dx[] = {0, 1}, _dy[] = {1, 0};
//int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
//int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
ll d(ll x, ll y, ll x_1, ll y_1){
    return (x - x_1) * (x - x_1) + (y - y_1) * (y - y_1);
}
int main(){
    //FL;
    FIN;
    ll cx, cy, cr, rx, ry, rl, crr;
    cin >> cx >> cy >> cr >> rx >> ry >> rl;
    crr = cr;
    cr *= cr;
    int ans = 0;
    int cnt = 0;
    ll x = rx, y = ry;
    for(int i = 0; i <= rl; i++){// horizontal
        if(d(x, y, cx, cy) < cr)
            ans = 2;
        else if(d(x, y, cx, cy) == cr && ans == 0)
            ans = 1;
        x++;

    }
    x = rx;
    y = ry;
    for(int i = 0; i <= rl; i++){// vertical
        if(d(x, y, cx, cy) < cr)
            ans = 2;
        else if(d(x, y, cx, cy) == cr && ans == 0)
            ans = 1;
        y++;
    }
    x = rx;
    y = ry + rl;
    for(int i = 0; i <= rl; i++){
        if(d(x, y, cx, cy) < cr)
            ans = 2;
        else if(d(x, y, cx, cy) == cr && ans == 0)
            ans = 1;
        x++;
    }

    x = rx + rl;
    y = ry;
    for(int i = 0; i <= rl; i++){
        if(d(x, y, cx, cy) < cr)
            ans = 2;
        else if(d(x, y, cx, cy) == cr && ans == 0)
            ans = 1;
        y++;
    }
    bool flag = 1;
    if(cx + crr > rx + rl or cx - crr < rx or cy + crr > ry + rl or cy - crr < ry)
        flag = 0;

    if(flag)
        ans = 2;
    cout << ans << '\n';
    EjecuteTime;
    return 0;
}       