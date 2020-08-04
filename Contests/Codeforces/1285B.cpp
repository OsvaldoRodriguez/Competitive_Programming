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
ll arr[N],acc[N];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        ll yaser = 0,adel = 0;
        fore(i,0,n){
            scanf("%lld",arr + i);
            yaser += arr[i];
        }
        acc[0] = max(0LL,arr[0]);
        fore(i,1,n)
            acc[i] =max(0LL,acc[i - 1] + arr[i]);
        
        int idx2 = -1,idx1 = -1;
        ll mx = 0;
        fore(i,0,n){
            if(mx <= acc[i]){
                mx = acc[i];
                idx2 = i;
            }
        }
        adel = mx;
        int i = idx2;
        while(i >= 0){
            if(acc[i] == 0){
                idx1 = i;
                break;
            }
            i--;
        }
        if(idx1 == -1 && idx2 == n - 1){
            int mx1 = 0;
            bool flag = 1;
            fore(i,0,n){
                if(acc[i] == mx && flag){
                    flag = 0;
                    continue;
                }
                if(mx1 < acc[i])
                    mx1 = acc[i];
            }
            adel = mx1;
        }
        printf(yaser > adel?"YES\n":"NO\n");

    }
    return 0;
}
