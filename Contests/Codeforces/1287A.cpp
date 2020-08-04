#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ii pair<int,int>
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define allr(x) (x).rbegin(),(x).rend()
#define fore(i,a,b) for(int i = a;i < b; i+= 1)
#define forr(i,a) for(int i = a; i >= 0; i--)
#define fori(i,m) for(auto i = m.begin(); i != m.end(); i++) 
#define sz(s) int(s.size())
#define cls(a,car) memset(a,car,sizeof (a))
using namespace std;
typedef long long ll;
typedef pair<ll,ll> llp;
const int N = 1 * 1e5 + 5;
const int mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
int main(){
    fast;
    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n >> s;
        int mx = 0;
        int tmp = 0;
        fore(i,0,n){
            if(s[i] == 'A'){
                int j = i + 1;
                tmp = 0;
                bool flag = 0;
                while(j < n && s[j] == 'P'){
                    tmp++;
                    flag = 1;
                    j++;
                }
                i = j;
                i--;
                mx = max(mx,tmp);
            }
        }
        cout << mx << '\n';
    }
    return 0;
}
