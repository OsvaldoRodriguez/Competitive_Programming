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
    int n;
    cin >> n;
    vector<int> v(n);
    fore(i, 0, n)
        cin >> v[i];
    
    int ans = 1;
    int cnt = 1;
    fore(i, 1, n){
        if(v[i] >= v[i - 1])
            cnt++;
        else{
            ans = max(ans,cnt),cnt = 1;
        }
    }
    ans = max(ans,cnt);
    cout << ans << '\n';
    return 0;
}   
