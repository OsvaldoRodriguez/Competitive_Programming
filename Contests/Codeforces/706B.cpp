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
int main(){
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    fin;
    int n;
    cin >> n;
    int v[n + 1];
    fore(i, 0, n)
        cin >> v[i];
    sort(v,v + n);
    int q, x;
    cin >> q;
    w(q){
        cin >> x;
        int a = -1, b = n, mid;
        while(b - a > 1){
            mid = (a + b) >> 1;
            if(v[mid] <= x)
                a = mid;
            else
                b = mid;
        }
        cout << a + 1 << '\n';
    }
    return 0;
}   
