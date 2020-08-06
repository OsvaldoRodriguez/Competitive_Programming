#include <bits/stdc++.h>
#define fin ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ii pair<int,int>
#define F first
#define S second
#define pb push_back
#define pf push_front
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define fore(i,a,b) for(int i = a;i < b; i+= 1)
#define forr(i,a) for(int i = a; i >= 0; i--)
#define fori(i,m) for(auto i = m.begin(); i != m.end(); i++) 
#define w(t) while(t--)
#define sz(s) int(s.size())
#define cls(a,car) memset(a,car,sizeof (a))
#define ff(x) cerr << #x << " is " << x << '\n'
#define FL freopen("in", "r", stdin),freopen("out", "w", stdout);
#define time cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n"
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ii> vii;
const int N = 1 * 1e5 + 5;
const ll mod = 998244353;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
const double E = 1e-9;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b) 
int delta = 100;
int a[300][300], b[300][300];
void print(int n, int m, int v[][300]){
    for(int i = delta; i < n; i++){
        for(int j = delta; j < m; j++){
            cout << v[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}
int main(){
    
    //FL;
    fin;
    int r1, c1;
    cin >> r1 >> c1;
    for(int i = delta; i < r1 + delta; i++){
        string s;
        cin >> s;
        for(int j = delta; j < c1 + delta; j++)
            a[i][j] = s[j - delta] - '0';
    }
    int r2, c2;
    cin >> r2 >> c2;
    for(int i = delta; i < r2 + delta; i++){
        string s;
        cin >> s;
        for(int j = delta; j < c2 + delta; j++)
            b[i][j] = s[j - delta] - '0';
    }
    int ans = 0;
    int X, Y;
    int dl = 50;
    for(int i = -dl; i <= dl; i++){
        for(int j = -dl; j <= dl; j++){
            int cur = 0;
            for(int k = delta; k < r1 + delta; k++){
                for(int l = delta; l < c1 + delta; l++){
                    cur += a[k][l] * b[k + i][l + j];
                }
            }
            if(ans < cur){
                ans = cur;
                X = i;
                Y = j;
            }
        }
    }
    cout << X << " " << Y <<  '\n';
    time;
    return 0;
}   
