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
#define cls(a,car)      memset(a,car,sizeof (a))
#define db(x)           cerr << #x << " is " << x << '\n'
#define angle(x)        double(x * acos(-1) / 180.0)
using namespace std;
typedef long long   ll;
typedef vector<int> vi;
typedef vector<ii>  vii;
const int N = 2e5 + 5;
const ll mod = 1e9 + 7;
const double E = 1e-7;
const int oo = 1e9;
 
typedef ll T;
struct punto{
    T x, y;
    punto(): x(0), y(0){}
    punto(T x, T y):x(x), y(y){}
    punto operator + (punto &A){return punto(x + A.x, y + A.y);}
    punto operator - (punto &A){return punto(x - A.x, y - A.y);}
    punto operator * (T k){return punto(x * k, y * k);}
    T operator * (punto &A){return x * A.x + y * A.y;}
    T operator ^ (punto &A){return x * A.y - y * A.x;}
};
void solve(){
    int n;
    cin >> n;
    vector<punto> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i].x >> v[i].y;
 
    bool flag = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int k = j + 1; k < n; k++){
                punto IJ = v[j] - v[i];
                punto IK = v[k] - v[i];
                if((IJ ^ IK) == 0)
                    flag = 1;
            }
        }
    }
    cout << (flag ? "Yes" : "No") << '\n';
}
int main(){
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #endif
 
    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++)
        solve();
 
    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}
