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
vector<ii> v;
int main(){  
    int n,x;
    scanf("%d",&n);
    int cnt = 0;
    while(n--){
        int y;
        scanf("%d %d",&x,&y);
        v.pb(ii(x,y));
        if(y == 1)
            cnt++;
    }
    bool flag = 0;
    fore(i,1,sz(v)){
        if(v[i - 1].F >= 0 && v[i - 1].S == 1 && v[i].S == 2){
            flag = 1;
            break;
        }
        if(v[i - 1].F < 0 && v[i - 1].S == 2 && v[i].S == 1){
            flag = 1;
            break;
        }
    }
    if(flag)
        printf("Impossible\n");
    else{
        if(cnt == sz(v))
            printf("Infinity\n");
        else{
            int diff = 0,a = -1e9, b = 1e9;
            for(int i = 0; i < sz(v); i++){
                if(v[i].S == 1)
                    a = max(a,1900 - diff);
                else
                    b = min (b,1899 - diff);
                diff += v[i].F;
            }
            if(b == 1e9)
                printf("Infinity\n");
            else if(b < a)
                printf("Impossible\n");
            else
                b += diff,printf("%d\n",b);
        }
    }
    return 0;
}
    
