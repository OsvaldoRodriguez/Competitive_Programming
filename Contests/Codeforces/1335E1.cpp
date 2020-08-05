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
#define sz(s) int(s.size())
#define cls(a,car) memset(a,car,sizeof (a))
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ii> vii;
const int N = 2 * 1e5 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
const double E = 1e-9;
const int  M = 201;
vi G[M];
int v[M][N];
int n;
int f(int row, int l, int r){
    return (l == 0?v[row][r]:v[row][r] - v[row][l - 1]);
}
int main(){
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    fin; 
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        fore(i, 0, M){
            fore(j, 0, n + 1)
                v[i][j] = 0;
            G[i].clear();
        }
        fore(i, 0, n){
            int x;
            cin >> x;
            x--;
            G[x].pb(i);
            v[x][i] = 1;
        }

        fore(i, 0, M)
            fore(j, 1, n)
                v[i][j] += v[i][j - 1];
/*        fore(i, 0, 5){
            fore(j, 0, n)
                cout << v[i][j] << ' ';cout << endl;
        }

        fore(i, 0, n){
            if(sz(G[i])){
                cout << i + 1 << " : ";
                fore(j, 0, sz(G[i]))
                    cout << G[i][j] << " ";cout << endl; 
            }
        }*/
        int mx = 0;
        fore(i, 0, M)
            mx = max(mx, f(i, 0, n - 1));
        fore(i, 0, M){
            fore(j, 0, (sz(G[i])) >> 1){
                int l = G[i][j];
                int r = G[i][sz(G[i]) - j - 1];
                int mid = 0;
                int lr = 0;
                l++;
                r--;    
                //cout << "pre\n"; 
                fore(k, 0, M){
                    int l1 = f(k, 0, l - 1);
                    int r1 = f(k, r + 1, n - 1);
                    int mid_1 = f(k, l, r);
                    mid = max(mid, mid_1);
                    int auxix = min(l1, r1) * 2;
                    lr = max(lr, auxix);
                    //cout << k << "\n";
                    //cout << l1 << " " << r1 << " " << mid << endl; 
                    
                }
                mx = max(mx, mid + lr);
            }
        }
        cout << mx << "\n";
    }
    return 0;
}   
