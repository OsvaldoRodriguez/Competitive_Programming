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
const int N = 1 * 1e5 + 50;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
int v[N];
int main(){
    int n;
    scanf("%d",&n);
    int x1 = 1, x2 = 1e6;
    int mx1 = 0,mx2 = 1e6;
    fore(i,0,n){
        int x;
        scanf("%d",&x);
        if(x <= 500000)
            mx1 = max(mx1,x);
        else
            mx2 = min(mx2,x);
    }
    int a1 = 0,a2 = 0;
    if(mx1 != 0)
        a1 = mx1 - x1;
    if(mx2 != (int)1e6)
        a2 = x2 - mx2;

    printf("%d\n",max(a1,a2));
    return 0;
}
