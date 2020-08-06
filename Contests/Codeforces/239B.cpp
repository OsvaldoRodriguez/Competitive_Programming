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
typedef unsigned long long ll;
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
ll POW(ll a,  ll b){
    ll ans = 1;
    while(b){
        if(b & 1)
            ans *= a;
        b >>= 1;
        a *= a;
    }return ans;
}
int main(){
    
    //FL;
    //fin;
    int n, q;
    cin >> n >> q;
    string str;
    cin >> str;
    int v[10];
    w(q){
        cls(v, 0);
        int l, r;
        cin >> l >> r;
        l--; r--;
        string cur = "";
        fore(i, l, r + 1)
            cur += str[i];
        int i  = 0, j = 1;
        while(i >= 0 && i < sz(cur)){
            if(cur[i] >= '0' && cur[i] <= '9'){
                v[cur[i] - '0']++;
                if(cur[i] == '0'){
                    cur.erase(i, 1);
                    if(j == -1)
                        i--;
                }
                else{
                    cur[i]--;
                    i += j;
                }
            }else{
                if(cur[i] == '>'){
                    j = 1;
                    i += j;
                    if(i < sz(cur) && (cur[i] == '<' or cur[i] == '>')){
                        cur.erase(i - 1, 1);
                        i--;
                    }
                }
                else{
                    j = -1;
                    i += j;
                    if(i >= 0 && (cur[i] == '<' or cur[i] == '>')){
                        cur.erase(i + 1, 1);
                    }
                }
                
            }
        }
        fore(i, 0, 10)cout << v[i] << ' ';cout << '\n';
    }
    time;
    return 0;
}   
