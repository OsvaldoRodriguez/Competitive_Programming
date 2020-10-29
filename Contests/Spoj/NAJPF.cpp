#include <bits/stdc++.h>
#define FIN         ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ii          pair<int,int>
#define F           first
#define S           second
#define pb          push_back
#define all(x)      (x).begin(),(x).end()
#define rall(x)     (x).rbegin(),(x).rend()
#define fore(i,a,b) for(int i = a;i < b; i+= 1)
#define forr(i,a)   for(int i = a; i >= 0; i--)
#define fori(i,m)   for(auto i = m.begin(); i != m.end(); i++) 
#define w(t)        while(t--)
#define sz(s)       int(s.size())
#define cls(a,car)  memset(a,car,sizeof (a))
#define db(x)       cerr << #x << " is " << x << '\n'
#define FI          freopen("input.txt", "r", stdin)
#define FO          freopen("output.txt", "w", stdout)
#define EjecuteTime cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n"
#define angle(x)    double(x * acos(-1) / 180.0)
using namespace std;
typedef long long   ll;
typedef vector<int> vi;
typedef vector<ii>  vii;
const int N = 2e2 + 5;
const ll mod = 1e9 + 7;
const double E = 1e-7;
const int INF = 1e2;
vector<int> get_phi(string &p){
    vector<int> phi(sz(p));
    for(int i = 1, j = 0; i < sz(p); i++){
        while(j > 0 && p[i] != p[j])j = phi[j - 1];
        if(p[i] == p[j])j++;
        phi[i] = j;
    }
    return phi;
}
 
vector<int> get_match(string &t, string &p){
    vector<int> mathes, phi = get_phi(p);
    for(int i = 0, j = 0; i < sz(t); i++){
        while(j > 0 && t[i] != p[j])j = phi[j - 1];
        if(t[i] == p[j])j++;
        if(j == sz(p)){
            mathes.pb(i - sz(p) + 1);
            j = phi[j - 1];
        }
    }
    return mathes;
}
void solve(){   
    string t, p;
    cin >> t >> p;
    vector<int> ans = get_match(t, p);
    if(!sz(ans)){
        cout << "Not Found\n";
        return;
    }
    cout << sz(ans) << '\n';
    for(auto i : ans)cout << i + 1 << ' ';
    cout << '\n';
    
}
int main(){
    FIN;
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++){
        if(i > 1)cout <<  '\n';
        solve();
    }
    //EjecuteTime;
    return 0;
 
} 
