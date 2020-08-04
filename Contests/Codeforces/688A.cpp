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
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
int main(){
    int n,m;
    cin >> m >> n;
    char v[n][m];
    fore(i,0,n)
        fore(j,0,m)
            cin >> v[i][j];
    int ans = 0;
    int cnt = 0;
    int tmp = 0;
    fore(i,0,n){
        cnt = 0;
        fore(j,0,m)
            if(v[i][j] - '0' == 1)
                cnt++;
        if(cnt == m){
            ans = max(ans,tmp);
            cnt = 0;
            tmp = 0;
        }else
            tmp++;
    }
    ans = max(ans,tmp);
    cout << ans << '\n';    
    return 0;
}
    
