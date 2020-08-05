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
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ii> vii;
const int N = 2 * 1e5 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
const double E = 1e-9;
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)

int n, t, a, b, c, d;
int v[N], arr[N], acc[N];
int main(){
    fin;
    cin >> t;
    w(t){
        int k;
        cin >> n >> k;
        fore(i, 0, n)
            cin >> v[i];
        arr[0] = arr[n - 1] = 0;
        fore(i, 1, n - 1){
            if(v[i] > v[i - 1] && v[i] > v[i + 1])
                arr[i] = 1;
            else
                arr[i] = 0;
        }
        acc[0] = arr[0];
        fore(i, 1, n){
            acc[i] = acc[i - 1] + arr[i];
        }

        int ans = 0;
        int l = 0;
        ans = acc[k - 1] - arr[k - 1] - arr[0];
        //cout << ans << '\n';
        fore(i, k, n){
            //cout << i - k + 1<< " " << i << endl;
            int x = i - k + 1;
            int y = i;
            int q = acc[y] - acc[x - 1] - arr[x] - arr[y];
            if(ans < q){
                ans = q;
                l = x;
            }
            //cout << q << '\n';
            //cout << q << " consultando rango " << i << " " << i - k << endl; 
        }
        cout << ans + 1 << " " << l + 1 << '\n';
        
    }
    return 0;
}   
