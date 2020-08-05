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
int local[N], visit[N];
vii arr;
int main(){
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    int k, n;
    cin >> k >> n;
    vi arr;
    fore(i, 0, n){
        int x;
        cin >> x;
        arr.pb(x);
    }
    sort(all(arr));
    bool flag = 1;
    if(n == 0){
        cout << "YES\n";
        return 0;
    }
    if(arr[0] == 1 && n > 0)
        flag = 0;
    if(n <= 2 && (arr[0] == k or arr[1] == k)){
        cout << "NO\n";
        return 0;
    }

    if(flag)
    fore(i, 0, n - 2){
        if(arr[i] + 1 == arr[i + 1] && arr[i + 1] + 1 == arr[i + 2]){
            flag = 0;
            break;
        }
        if(arr[i] == k or arr[i + 1] == k or arr[i + 2] == k){
            flag = 0;
            break;
        }
    }
    cout << (flag ? "YES" : "NO") << '\n';
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}   
