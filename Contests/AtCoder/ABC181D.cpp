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
void solve(){
    string t;
    cin >> t;
    if(sz(t) <= 2){
        bool flag = 0;
        flag |= (atoi(t.data()) % 8 == 0);
        reverse(all(t));
        flag |= (atoi(t.data()) % 8 == 0);
        cout << (flag ? "Yes" : "No") << '\n';
    }
    else{
        vi v(10);
        for(auto i : t)
            v[i - '0']++;
        bool flag = 0;
        for(int i = 1; i < 10; i++)
            for(int j = 1; j < 10; j++)
                for(int k = 1; k < 10; k++){
                    vi aux = v;
                    if(aux[i] > 0)
                        aux[i]--;
                    else
                        continue;
                    if(aux[j] > 0)
                        aux[j]--;
                    else
                        continue;
                    if(aux[k] > 0)
                        aux[k]--;
                    else
                        continue;
                    if((i * 100 + j * 10 + k) % 8 == 0)flag = 1;
 
                }
        cout << (flag ? "Yes" : "No") << '\n';
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
