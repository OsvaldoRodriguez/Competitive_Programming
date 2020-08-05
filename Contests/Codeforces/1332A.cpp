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
//freopen("","r",stdin);
//freopen("","w",stdout);
int main(){
    int t;
    ll a,b,c,d;
    ll x,y,x1,y1,x2,y2;
    scanf("%d",&t);
    while(t--){
        scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld",&a,&b,&c,&d,&x,&y,&x1,&y1,&x2,&y2);

        ll dx = b - a;
        ll dy = d - c;
        x += dx;
        y += dy;
        if(x1 <= x && x <= x2 && y1 <= y && y <= y2){
            if(x1 == x2 && (a or b))
                printf("No\n");
            else if(y1 == y2 && (d or c))
                printf("No\n");
            else
            printf("Yes\n");
        }
        else
            printf("No\n");

    }
    return 0;
}
