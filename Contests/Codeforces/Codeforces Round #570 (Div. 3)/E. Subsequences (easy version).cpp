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
void solve(){
    int n, k;
    string str;
    cin >> n >> k >> str;
    int l = k;
    set<string> s;
    queue<string> q;
    q.push(str);

    int ans = 0;
    bool flag = true;
    while(q.size() and flag){
        string cur = q.front();
        q.pop();
        l--;
        ans += n - (int)cur.size();
        if(l == 0)
            break;
        for(int i = 0; i < (int) cur.size(); i++){
            string nw = "";
            for(int j = 0; j < (int) cur.size(); j++){
                if(i == j)continue;
                nw += cur[j];
            }
            if(!s.count(nw)){
                q.push(nw);
                s.insert(nw);
            }

        }
    }  
    if(l)
        ans = -1;
    cout << ans << '\n';
   
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

    #ifdef FURY
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}
