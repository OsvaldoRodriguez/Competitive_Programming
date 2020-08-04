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
int v[N];
int main(){ 
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        n *= 2;
        fore(i,0,n)
            scanf("%d",v + i);
        sort(v,v + n);
        int ans = 1e9;
        n /= 2;
        ans = min(v[n] - v[n - 1],ans);
        if(n % 2 == 0 && n != 1)
            ans = min(v[n + 1] - v[n - 2],ans);
        printf("%d\n",ans   );
    }
    return 0;
}
    
