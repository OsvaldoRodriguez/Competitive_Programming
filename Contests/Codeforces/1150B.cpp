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
#define what_is(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ii> vii;
const int N = 1 * 1e5 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
const double E = 1e-9;
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
int main(){
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    int n;
    cin >> n;
    char v[n + 1][n + 1];
    fore(i, 0, n)
        fore(j, 0, n)
            cin >> v[i][j];
    bool flag = 1;
    fore(i, 1, n - 1){
        fore(j, 1, n - 1){
            if(v[i][j] == '.'){
                bool sw = 1;
                fore(k, 0, 4){
                    int u = i + dx[k];
                    int v1 = j + dy[k];
                    sw &= (v[u][v1] == '.');
                }
                if(sw){
                    v[i][j] = '#';
                    fore(k, 0, 4){
                        int u = i + dx[k];
                        int v1 = j + dy[k];
                        v[u][v1] = '#';
                    }
                }
            }
        }
    }
    fore(i, 0, n){
        fore(j, 0, n){
            flag &= (v[i][j] == '#');
        }
    }
    cout << (flag ? "yes" : "no") << '\n';
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}   
