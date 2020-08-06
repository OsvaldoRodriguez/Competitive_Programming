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
typedef unsigned long long   ll;
typedef vector<int> vi;
typedef vector<ii>  vii;
const int N = 2 * 1e5 + 5;
const ll mod = 1e9 + 7;
const double E = 1e-9;
//int dx[] = {1, 0}, dy[] = {0, 1};
//int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
//int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
int main(){
    //FL;
    FIN;
    int t;
    cin >> t;
    w(t){
        ii v[3];
        int w[3];
        cin >> v[0].F >> v[1].F >> v[2].F;
        w[0] = v[0].F; 
        w[1] = v[1].F;
        w[2] = v[2].F;
        v[0].S = 0, v[1].S = 1, v[2].S = 2;
        sort(v, v + 3);
        reverse(v, v + 3);
        // cout << "yesy\n";
        // for(int i = 0; i < 3; i++)
        //     cout << v[i].F << " " << v[i].S << endl;
        int a = v[0].F;
        int c = v[2].F;
        int b = 1;
        if(w[v[0].S] == max(a, b) && w[v[1].S] == max(a, c) && w[v[2].S] == max(b, c))
            cout << "YES\n" << a << " " << b << " " << c << '\n';
        else{
            b = v[0].F;
            a = 1;
            c = v[2].F;
            if(w[v[0].S] == max(a, b) && w[v[1].S] == max(a, c) && w[v[2].S] == max(b, c))
                cout << "YES\n" << a << " " << b << " " << c << '\n';
            else 
                cout << "NO\n";
        }
    }
    EjecuteTime;
    return 0;
}       
