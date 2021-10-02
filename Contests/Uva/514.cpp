#include <bits/stdc++.h>
#define ii              pair<int,int>
#define F               first
#define S               second
#define pb              push_back
#define all(x)          (x).begin(),(x).end()
#define rall(x)         (x).rbegin(),(x).rend()
#define sz(s)           int(s.size())
#define cls(a, car)     memset(a,car,sizeof (a))
#define db(x)           cout << #x << " is " << x << '\n'
#define angle(x)        double(x * acos(-1) / 180.0)
using namespace std;
void debug(){cout << endl;}
template<typename T, typename... Args>
void debug(T a, Args... args){cout << a << " "; debug(args...);}
typedef long long   ll;
typedef vector<int> vi;
typedef vector<ii>  vii;
const int N = 2e5 + 15;
const ll mod = INT_MAX;
const double E = 1e-7;


int v[N];
void solve(){
    int n;
    int test = 1;
    while(cin >> n && n){
        if(test > 1)
            cout << "\n";
        
        while(cin >> v[0]){
            if(!v[0])
                break;
            for(int i = 1; i < n; i++)
                cin >> v[i];
            vi aux, ans;
            aux.pb(v[n - 1]);
            for(int i = n - 2; i >= 0; i--){
                while(sz(aux) && v[i] < aux.back()){
                    ans.pb(aux.back());
                    aux.pop_back();
                }
                aux.pb(v[i]);
            }
            while(sz(aux)){
                ans.pb(aux.back());
                aux.pop_back();
            }
            bool flag = 1;
            for(int i = 0; i < sz(ans) - 1; i++){
                if(ans[i] < ans[i + 1]){
                    cout << "No\n";
                    flag = 0;
                    break;
                }
            }
            if(flag){
                cout << "Yes\n";
            }
        }
        test++;
    }
}
int main(){
    #ifdef FURY
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #endif
    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++){ 
        solve();
    }
    cout << '\n';
    #ifdef FURY
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}
