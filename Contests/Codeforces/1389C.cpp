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
const int N = 2e5 + 50;
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
vi G[10];
int v[10][N];
int fre[10];
int q(int val, int i, int j){
    if(j < i)
        return 0;
    if(i == 0)
        return v[val][j];
    return v[val][j] - v[val][i - 1];
}
int main(){
    //FL;
    FIN;
    int t;
    cin >> t;
    w(t){
        string str;
        cin >> str;
        int ans = 1e9;
        cls(fre, 0);
        for(int i = 0; i < sz(str); i++)
            fre[str[i] - '0']++;
        int count = 0;
        for(int i = 0; i < 10; i++)
            count = max(count, fre[i]);
        ans = min(ans, sz(str) - count);

        for(int i = 0; i < 10; i++){
            G[i].clear();
            for(int j = 0; j < sz(str); j++)
                v[i][j] = 0;
        }
        for(int i = 0; i < sz(str); i++)
            G[str[i] - '0'].pb(i);
        for(int i = 0; i < 10; i++){
            if(sz(G[i]))
                G[i].pb(sz(str));
        }
        
        for(int i = 0; i < sz(str); i++)
            v[str[i] - '0'][i] = 1;
        
        for(int i = 0; i < 10; i++){
            for(int j = 1; j < sz(str); j++)
                v[i][j] += v[i][j - 1];
        }
        
        for(int i = 0; i < 10; i++){
            map<int, int> m;
            for(int j = 1; j < sz(G[i]); j++){
                int mx = 0;
                for(int k = 0; k < 10; k++){
                    int cur = q(k, G[i][j - 1] + 1, G[i][j] - 1);
                    if(cur > 0)
                        m[k]++;
                }
            }
            int _mx = 0;
            
            fori(i, m){
                _mx = max(_mx, i->S);
            }
            ans = min(ans, sz(str) - min(_mx, sz(G[i])) * 2);
        }
        cout << ans << '\n';

    }
    EjecuteTime;
    return 0;
}       
