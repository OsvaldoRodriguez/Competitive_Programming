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
const int N = 2 * 1e5 + 5;
const int mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,k1,k2;
        scanf("%d %d %d",&n,&k1,&k2);
        int mx1 = 0, mx2 = 0;
        int x;
        fore(i,0,k1){
            scanf("%d",&x);
            mx1 = max(mx1,x);
        }

        fore(i,0,k2){
            scanf("%d",&x);
            mx2 = max(mx2,x);
        }
        printf(mx1 > mx2?"YES\n":"NO\n");
    }
    return 0;
}
