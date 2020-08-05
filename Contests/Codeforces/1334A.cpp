#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
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
const int N = 1 * 1e5 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
const double E = 1e-9;
int main(){
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    fast;
    int t;
    cin >> t;
    while(t--){
        int n;
        bool flag = 1;
        cin >> n;
        int v[n + 1],c[n + 1];
        fore(i, 0, n)
            cin >> v[i] >> c[i];
        if(n == 1){
            if(c[0] > v[0]){
                cout << "NO\n";
                continue;
            }
        }
        if(c[0] > v[0])
            flag = 0;
        fore(i, 1, n){
            if(c[i] < c[i - 1] or v[i] < v[i - 1])
                flag = 0;
            if(c[i] > c[i - 1] && v[i] <= v[i - 1])
                flag = 0;
            if(c[i] == c[i - 1] && v[i] < v[i - 1])
                flag = 0;
            if(c[i] > c[i - 1] && v[i] > v[i - 1] && (c[i] - c[i - 1]) > (v[i] - v[i - 1]))
                flag = 0;
        }
        cout << (flag?"YES":"NO") << '\n';
    }
    return 0;
}   
