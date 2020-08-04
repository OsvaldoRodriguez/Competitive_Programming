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
const int N = 1 * 1e5 + 5;
const int mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
vector<ii> arr;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        arr.clear();
        fore(i,0,n){
            int x,y;
            cin >> x >> y;
            arr.pb(ii(x,y));
        }
        sort(all(arr));
        string ans = "";
        ii ant = ii(0,0);
        int ans1 = 0;
        fore(i,0,n){
            if(arr[i].F >= ant.F && arr[i].S >= ant.S){
                ans1++;
                fore(j,0,arr[i].F - ant.F)
                    ans += 'R';
                fore(j,0,arr[i].S - ant.S)
                    ans += 'U';
                ant = arr[i];
            }else break;
        }
        if(ans1 == n){
            cout << "YES\n" << ans << '\n';
        }else printf("NO\n");
    }
    return 0;
}
