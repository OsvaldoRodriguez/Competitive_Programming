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
const int N = 1 * 1e6 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
const double E = 1e-9;
// fflush(stdout)
// cout << flush
vi A;
int dp[N], idx[N];
int n;
void bfs(){
    queue<int> q;
    q.push(1);
    while(sz(q)){
        int u = q.front();q.pop();
        A.pb(u);
            fore(i, 0, 2)
                if(u * 10 + i <= 1000000)
                    q.push(u * 10 + i);
    }
}
int f(int u){
    if(u == 0)
        return dp[u] = 0;
    if(dp[u] != -1)return dp[u];
    int  &ans = dp[u];
    ans = 1e6;
    fore(i, 0, sz(A))
        if(u >= A[i]){
            int aux = f(u - A[i]) + 1;
            if(aux < ans){
                ans = aux;
                idx[u] = A[i]; 
            }
        }
    return ans;
}
int main(){
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    bfs();
    cin >> n;
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        dp[i] = 1e6;
        fore(j, 0, sz(A)){
            if(i >= A[j]){
                int mn = dp[i - A[j]] + 1;
                if(mn < dp[i]){
                    dp[i] = mn;
                    idx[i] = A[j];
                }
            }
        }
    }
    int x = n;
    cout << dp[x] << '\n';
    while(x > 0){
        cout << idx[x] << ' ';
        x -= idx[x];
    }
    return 0;
}   
