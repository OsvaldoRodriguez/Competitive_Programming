#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ii pair<int,int>
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define allr(x) (x).rbegin(),(x).rend()
#define fore(i,a,b) for(int i = a;i < b; i+= 1)
#define forr(i,a) for(int i = a; i >= 0; i--)
#define fori(i,m) for(auto i = m.begin(); i != m.end(); i++) 
#define sz(s) int(s.size())
#define cls(a,car) memset(a,car,sizeof (a))
using namespace std;
typedef long long ll;
typedef pair<ll,ll> llp;
const int N = 2 * 1e5 + 5;
const int mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
vector<string> v,w;
int main(){
    fast;
    int x,y;
    string z;
    v.clear();
    w.clear();
    cin >> x >> y;
    fore(i,0,x){
        cin >> z;
        v.pb(z);
    }

    fore(i,0,y){
        cin >> z;
        w.pb(z);
    }

    int cont = x * y;
    vector<string> ans;
    ans.clear();
    int i = 0,j = 0;
    while(cont--){
        string aux = v[i] + w[j];
        ans.pb(aux);
        i = (i + 1) % x;
        j = (j + 1) % y;
    }
    int t;
    cin >> t;
    while(t--){
        int r;
        cin >> r;
        r--;
        cout << (ans[r % (x * y)])  << '\n';

    }
    return 0;
}
