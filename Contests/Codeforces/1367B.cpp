

#include <bits/stdc++.h>
#define fin         ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
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
const int N = 2 * 1e5 + 5;
const ll mod = 1e9 + 7;
const double E = 1e-9;
//int dx[] = {1, 0}, dy[] = {0, 1};
//int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
int v[50];
bool ok(int n){
    fore(i, 0, n)
        if(i % 2 != v[i] % 2)
            return 0;
    return 1;
}
int main(){
    //FL;
    fin;
    int t;
    cin >> t;
    w(t){
        int n;
        cin >> n;
        fore(i, 0, n){
            cin >> v[i];
            v[i] %= 2;
        }
        if(ok(n))
            cout << 0 << '\n';
        else{
            int even = 0;
            int odd = 0;
            fore(i, 0, n)
                if(v[i])
                    odd++;
                else
                    even++;
            if((n + 1) / 2 != even or n / 2 != odd)
                cout << -1 << '\n';
            else{
                int cur = 0;
                fore(i, 0, n)
                    if(v[i] != i % 2)
                        cur++;
                cout << (cur >> 1) << '\n';
            }
        }
    }
    EjecuteTime;
    return 0;
}       