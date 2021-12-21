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
#define ff(x) cerr << #x << " is " << x << '\n'
#define FL freopen("in", "r", stdin),freopen("out", "w", stdout);
#define time cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n"
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ii> vii;
const int N = 3 * 1e5 + 5;
const ll mod = 998244353;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
const double E = 1e-9;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)  
vi G[105],vis(105, -1);
bool flag = 1;
void dfs(int  u){
    vis[u] = 1;
    if(sz(G[u]) == 1)
        flag = 1;
    for(auto  v : G[u])
        if(vis[v] == -1)dfs(v);
}
int main(){
    //FL;
    fin;
    string s;
    cin >> s;
    string str = "";
    int tmp = 0;
    fore(i, 0, sz(s)){
        if('0' <= s[i] && s[i] <= '9')
            tmp++;
        if(s[i] == '.')break;
    }
    tmp %= 3;
    int i = 0;
    if(s[0] == '-'){
        cout << '(';
        i = 1;
    }
    cout << '$';
    if(tmp == 0)
        tmp = 3;
    w(tmp)
        cout << s[i++];
    for(; i < sz(s); i++){
        if(s[i] == '.')
            break;
        str += s[i];
        if(sz(str) % 3 == 0){
            cout << ',';
            cout << str;
            str = "";
        }
    }
    cout << '.';
    tmp = 2;
    i++;
    while(tmp > 0 && i < sz(s)){
        cout << s[i++];
        tmp--;
    }
    w(tmp)
        cout << '0';
    if(s[0] == '-')
        cout << ')';
    cout << '\n';
    time;
    return 0;
}   
