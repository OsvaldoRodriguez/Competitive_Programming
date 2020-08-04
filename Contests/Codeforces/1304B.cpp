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
const int N = 1 * 1e5 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
vector<string> v;
vector<int> vis(101,-1);
int main(){
    fast;
    int n,m;
    cin >> n >> m;
    string aux = "@";
    bool flag = 1;
    deque<string> ans;
    fore(i,0,n){
        string x;
        cin >> x;
        v.pb(x);
        flag = 1;
        fore(j,0,m / 2)
            if(x[j] != x[m - j - 1]){
                flag = 0;
                break;
            }
        if(flag)
            aux = x;
    }
    int tmp = 0;
    if(aux != "@"){
        ans.pb(aux);
        tmp += sz(aux);
    }
    fore(i,0,n){
        fore(j,i + 1,n){
            string aux_1 = v[j];
            reverse(all(aux_1));
            if(aux_1 == v[i] && vis[i] == -1 && vis[j] == -1){
                ans.pf(v[i]);
                ans.pb(v[j]);
                tmp += sz(v[i]) * 2;
                vis[i] = 1;
                vis[j] = 1;
            }
        }
    }
    cout << tmp << '\n';
    while(sz(ans)){
        cout << ans.front();
        ans.pop_front();
    }
    return 0;
}
    
