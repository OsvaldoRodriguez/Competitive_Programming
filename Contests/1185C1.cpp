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
int dx[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
ll v[N];
int occ[105];
int main(){
    fin;
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    int n, m;
    cin >> n >> m;
    fore(i, 0, n)cin >> v[i];
    ll sum = 0;
    ll mx = 0;
    fore(i, 0, n){
        sum += v[i];
        mx = max(mx, v[i]);
        occ[v[i]]++;
        if(sum <= m)
            cout << 0 << ' ';
        else{
            int tmp = 0;
            ll par = sum;
            int occ_1[105];
            fore(k, 0 ,101)
                occ_1[k] = occ[k];
            int j = mx;
            while(j >= 0){
                if(occ_1[j] > 0){
                    if(j == v[i]){
                        if(occ_1[j] > 1){
                            par -= j;
                            occ_1[j]--;
                            tmp++;
                        }else j--;
                    }else{    
                        par -= j;
                        occ_1[j]--;
                        tmp++;
                    }
                }else j--;
                if(par <= m)
                    break;
            }
            cout << tmp << ' ';
        }
    }
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}   
