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
const int N = 5 * 1e3 + 5;
const ll mod = 1e9 + 7;
const double E = 1e-9;
//int dx[] = {1, 0}, dy[] = {0, 1};
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
int add(int a, int b){return  a + b > mod ? a + b - mod : a + b;}
int mul(int a, int b){return a * b >= mod ? a * b % mod : a * b;}  
int main(){
    //FL;
    FIN;
    int n, m;
    cin >> n >> m;
    int v[n], arr[m];
    map<int,int> mp;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        mp[v[i]]++;
    }
    for(int i = 0; i < m; i++)cin >> arr[i];
    set<pair<ll, ii>, greater<pair<ll, ii>> >  s;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j)continue;
            ll cur = LONG_LONG_MIN;
            int x, y;
            for(int k = 0; k < m; k++){
                if(cur < 1ll * v[j] * arr[k]){
                    cur = 1ll * v[j] * arr[k];
                    x = v[j];
                    y = arr[k];
                }
            }
            s.insert({cur, {x, y}});
        }
    }
    auto cur = *s.begin();
    if(s.empty() or mp[cur.S.F] > 1)
        cout << cur.F << '\n';
    else{
        s.erase(s.begin());
        cout << (*s.begin()).F << '\n';
    }
    EjecuteTime;
    return 0;
}       
