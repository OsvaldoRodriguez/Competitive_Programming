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
    int n, m, ta, tb, k;
    cin >> n >> m >> ta >> tb >> k;
    int v[n + 1], arr[m + 1];
    fore(i, 0, n){
        cin >> v[i];
        v[i] += ta;
    }
    fore(i, 0, m){
        cin >> arr[i];
    }

    if(k >= n or k >= m){
        cout << -1 << '\n';
        return 0;
    }
    int mx = 0;
    fore(i, 0, k + 1){
        int a = -1, b = m, mid;
        while(b - a > 1){
            mid = (a + b) >> 1;
            if(arr[mid] >= v[i])
                b = mid;
            else
                a = mid;
        }
        if(b == m){
            cout << -1 << '\n';
            return 0;
        }else{
            if(b + k - i >= m){
                cout << -1 << '\n';
                return 0;
            }
            mx = max(mx, arr[b + k - i] + tb);
        }
    }
    cout << mx << '\n';
    return 0;
}   
