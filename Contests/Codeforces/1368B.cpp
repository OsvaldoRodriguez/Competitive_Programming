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
#define FL          freopen("in", "r", stdin),freopen("out", "w", stdout);
#define EjecuteTime cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n"
#define angle(x)    double(x * acos(-1) / 180.0)
using namespace std;
typedef long long   ll;
typedef vector<int> vi;
typedef vector<ii>  vii;
const int N = 400;
const ll mod = 1e9 + 7;
const double E = 1e-9;
//int dx[] = {1, 0}, dy[] = {0, 1};
//int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
ll v[15][N];
int fre[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
map<int, char> mp;
int main(){
    //FL;
    mp[1] = 'c';
    mp[2] = 'o';
    mp[3] = 'd';
    mp[4] = 'e';
    mp[5] = 'f';
    mp[6] = 'o';
    mp[7] = 'r';
    mp[8] = 'c';
    mp[9] = 'e';
    mp[10] = 's';

    int cnt = 2;
    fore(i, 0, N){
        ll cur = 1LL;
        fore(j, 1, 11)
            cur *= 1ll * fre[j];
        v[0][i] = cur;
        
        fore(j, 1, 11){
            v[j][i] = fre[j];
        }
        bool flag = 1; 
        fore(j, 1, 11){
            if(fre[j] < cnt){
                fre[j]++;
                flag = 0;
                break;
            }
        }
        if(flag){
            cnt++;
            fre[1]++;
        }
    }
    ll k;
    cin >> k;
    int a = -1, b = N - 1, mid;
    while(b - a > 1){
        mid = (a + b) >> 1;
        if(v[0][mid] >= k)
            b = mid;
        else
            a = mid;
    }
    fore(i, 1, 11)
        fore(j, 0, v[i][b])
            cout << mp[i];
    cout << '\n';

    EjecuteTime;
    return 0;
}       
