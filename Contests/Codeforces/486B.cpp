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

int main(){
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    fin;
    int m, n;
    cin >> m >> n;
    int v[m + 1][n + 1];
    int row[m][n];
    //int r[m], c[n];
    int r = 0, c = 0;
    cls(row, 0);
    fore(i, 0, m)
        fore(j, 0, n)
            cin >> v[i][j];
    fore(i, 0, m){
        int tmp = 0;
        fore(j, 0, n)
            tmp += (v[i][j] == 1);
        if(tmp == n)
            r++;
    }
    fore(i, 0, n){
        int tmp = 0;
        fore(j, 0, m){
            tmp += (v[j][i] == 1);
        }
        if(tmp == m)
            c++;
    }
    bool flag = 1;
    cerr << r << " " << c << endl;
    fore(i, 0, m){
        fore(j, 0, n){
            if(v[i][j] == 1){
                int tmp = 0;
                fore(k, 0, n)
                    tmp += (v[i][k] == 1);
                int tmp_1 = 0;
                fore(l, 0, m)
                    tmp_1 += (v[l][j] == 1);
                bool sw_1 = 0;
                bool sw_2 = 0;
               // cout << i << ' ' << j << ' ' << tmp << ' ' << tmp_1 << " alue\n"; 
                if(tmp_1 == m && tmp == n){
                    row[i][j] = 1;
                    continue;
                }
                if(tmp < n){
                    if(tmp > c){
                        cout << "NO\n";
                        return 0;
                    }
                }
                if(tmp_1 < m){
                    if(tmp_1 > r){
                        cout << "NO\n";
                        return 0;
                    }
                }
                
                
            }
        }
    }
    fore(i, 0, m){
        fore(j, 0, n){
            if(v[i][j] == 1){
                bool sw_1 = 0;
                fore(k, 0, n)
                    sw_1 |= row[i][k];
                bool sw_2 = 0;
                fore(l, 0, m)
                    sw_2 |= row[l][j];
                if(!sw_2 && !sw_1){
                    cout << "NO\n";
                    return 0; 
                }
            }
        }
    }
    cout << "YES\n";
    fore(i, 0, m){
        fore(j, 0, n)
            cout << row[i][j] << ' ';
            cout << '\n';
    }
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}   
