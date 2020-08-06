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
int dx[] = {1, 0}, dy[] = {0, 1};
//int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
int add(int a, int b){return  a + b > mod ? a + b - mod : a + b;}
int mul(int a, int b){return a * b >= mod ? a * b % mod : a * b;}  
int v[305][305];
int R[305], C[305];
int main(){
    //FL;
    //FIN;
    int t;
    cin >> t;
    w(t){
        int n, k;
        cin >> n >> k;
        int i = 0, j = 0;
        cls(v, 0);
        while(k--){
            v[i][j] = 1;
            j = (j + 1) % n;
            i = (i + 1) % n;
            if(i == 0)
                j = (j + 1) % n;
        }
        int cost = 0;
        int mxr = 0, mnr = 500;
        int mxc = 0, mnc = 500;
        int curr = 0, curc = 0;
        for(int i = 0; i < n; i++){
            curr = 0;
            curc = 0;
            for(int j = 0; j < n; j++){
                if(v[i][j] == 1)
                    curr++;
                if(v[j][i] == 1)
                    curc++;
            }
            mxr = max(mxr, curr);
            mnr = min(mnr, curr);

            mxc = max(mxc, curc);
            mnc = min(mnc, curc);   
        }
        cout << (mxr - mnr) * (mxr - mnr) + (mxc - mnc) * (mxc - mnc) << '\n';
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << v[i][j];
            }
            cout << '\n';
        }
    }
    EjecuteTime;
    return 0;
}       
