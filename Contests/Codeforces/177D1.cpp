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
const ll mod = 998244353;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
const double E = 1e-9;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
int main(){
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    fin;
    int n, m, c;
    cin >> n >> m >> c;
    int v[n + 1];
    int sum[m + 1], pre[m + 1], suf[m + 1];
    fore(i, 0, n){
        cin >> v[i];
        v[i] %= c;
    }
    fore(i, 0, m)cin >> sum[i];
    pre[0] = sum[0] % c;
    fore(i, 1, m)
        pre[i] = (pre[i - 1] % c + sum[i] % c) % c;
    suf[m - 1] = sum[m - 1] % c;
    for(int i = m - 2; i >= 0; i--)
        suf[i] = (suf[i + 1] % c + sum[i] % c) % c;
    vi left, right, mid;
    int i = 0;
    int j = m - 1;
    int k = n - 1;
    int df;
    if(m < n - m)
        df = m - 1;
    else
        df = n - m;
    while(i <= df){
        left.pb((v[i] + pre[i]) % c);
        i++;
        right.pb((v[k--] + suf[j--]) % c);
    }
    int l = 0;
    if(df == m - 1)
        while(i <= k){
            mid.pb((v[i] + suf[0] % c) % c);
            i++;
        }
    else 
        while(i <= k){
            mid.pb((v[i] + (pre[i] - pre[l++] + c) % c) % c);
            i++;
        }
    
    fore(i, 0, sz(left))
        cout << left[i] << " ";
    fore(i, 0, sz(mid))
        cout << mid[i] << " ";
    reverse(all(right));
    fore(i, 0, sz(right))
        cout << right[i] << " ";

    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}   
