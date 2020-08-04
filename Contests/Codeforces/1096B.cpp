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
const int N = 2 * 1e5 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
int main(){
    fast;
    int t;
    ll mod = 998244353;
    string s;
    cin >> t >> s;
    if(t == 2)
        cout << "3\n";
    else{
        if(s[0] != s[1] && s[t - 1] != s[t - 2] && s[0] != s[t - 1])
            cout << "3\n";
        else{
            ll ans = 0;
            ll cnt_1 = 0,cnt_2 = 0;
            int i = 1;
            while(i < t && s[i] == s[i - 1])
                i++,cnt_1++;

            i = t - 2;
            while(i >= 0 && s[i] == s[i + 1])
                i--,cnt_2++;
            cnt_2++;
            cnt_1++;
            if(s[0] != s[t - 1])
                ans = (cnt_1 % mod + cnt_2 % mod + 1 % mod) % mod;
            else{
                cnt_2++;
                cnt_1++;
                ans = (cnt_1 % mod * cnt_2 % mod) % mod;
            }
            cout << ans << '\n';
        }
    }
    return 0;
}
    
