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
#define FI          freopen("input.txt", "r", stdin)
#define FO          freopen("output.txt", "w", stdout)
#define EjecuteTime cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n"
#define angle(x)    double(x * acos(-1) / 180.0)
using namespace std;
typedef long long   ll;
typedef vector<int> vi;
typedef vector<ii>  vii;
const int N = 1e5 + 50;
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
int f(char x){return x - '0';}
int main(){
    //FI;
    //FL;
    FIN;
    int t;
    cin >> t;
    while(t--){
        vi zero, one;
        int team = 0;
        int n;
        string str;
        cin >> n >> str;
        vi ans(n , -1);
        for(int i = 0; i < n; i++){
            if(str[i] == '0'){
                if(sz(one)){
                    ans[i] = one.back();
                    zero.pb(ans[i]);
                    one.pop_back();
                }else{
                    team++;
                    ans[i] = team;
                    zero.pb(ans[i]);
                }
            }else{
                if(sz(zero)){
                    ans[i] = zero.back();
                    one.pb(ans[i]);
                    zero.pop_back();
                }else{
                    team++;
                    ans[i] = team;
                    one.pb(ans[i]);
                }
            }
        }
        cout << team << '\n';
        for(auto i : ans)cout << i << " ";cout << '\n';
    
    }

    EjecuteTime;
    return 0;
}       
