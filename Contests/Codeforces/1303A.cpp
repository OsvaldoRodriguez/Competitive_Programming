#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ii pair<int,int>
#define F first
#define S second
#define pb push_back
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
    string s;
    cin >> t;
    while(t--){
        cin >> s;
        bool flag = 1;
        int ans = 0;
        fore(i,0,sz(s)){
            if(s[i] == '1'){
                int j = i;
                i++;
                while(i < sz(s) && s[i] == '0')
                    i++;
                i--;
            ans += (i - j);
            }
        }
        int tmp = 0;
        for(int i = sz(s) - 1; i >= 0; i--)
            if(s[i] == '0')
                tmp++;
            else
                break;
        ans -= tmp;
        if(ans < 0)
            ans = 0;
        cout << ans << '\n';
    }
    return 0;
}
    
