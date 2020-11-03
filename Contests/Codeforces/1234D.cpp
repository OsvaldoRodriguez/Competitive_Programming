#include <bits/stdc++.h>
#define ii              pair<int,int>
#define F               first
#define S               second
#define pb              push_back
#define all(x)          (x).begin(),(x).end()
#define rall(x)         (x).rbegin(),(x).rend()
#define fore(i, a, b)   for(int i = a; i < b; i += 1)
#define forr(i, a)      for(int i = a; i >= 0; i--)
#define sz(s)           int(s.size())
#define cls(a,car)      memset(a,car,sizeof (a))
#define db(x)           cerr << #x << " is " << x << '\n'
#define angle(x)        double(x * acos(-1) / 180.0)
using namespace std;
typedef long long   ll;
typedef vector<int> vi;
typedef vector<ii>  vii;
const int N = 2e5 + 5;
const ll mod = 1e9 + 7;
const double E = 1e-7;
const int oo = 1e9;
int BIT[30][N];
string str; 
void update(int i, int pos, int val){
    for(int j = pos; j <= sz(str); j += j&(-j))
        BIT[i][j] += val;
}

int get(int letra, int pos){
    int ans = 0;
    for(int j = pos; j >= 1; j -= j&(-j))
        ans += BIT[letra][j];
    return ans;
}

int get(int pos, int i, int j){
    if(i == 0)
        return get(pos, j);
    return get(pos, j) - get(pos, i - 1);
}
void solve(){
    int q, ope, l, r;
    char c;
    cin >> str >> q;
    str = "@" + str;
    for(int i = 1; i < sz(str); i++)
        update(str[i] - 'a', i, 1);
    
    while(q--){
        cin >> ope >> l;
        if(ope == 2){
            cin >> r;
            int ans = 0;
            for(int i = 0; i < 26; i++)
                ans += (get(i, l, r) != 0);
            cout << ans << '\n';
        }else{
            cin >> c;
            update(str[l] - 'a', l, -1);
            update(c - 'a', l, + 1);
            str[l] = c;
        }
    }
}
int main(){
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #endif

    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++)
        solve();

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}
