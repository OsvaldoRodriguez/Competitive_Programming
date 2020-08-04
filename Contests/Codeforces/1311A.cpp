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
const int N = 1 * 1e5 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
int main(){
    int t;
    int a,b;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&a,&b);
        if(a == b)
            printf("0\n");
        else{
            if(a < b){
                if(b - a == 1)
                    printf("1\n");
                else{
                    int ans = 0;
                    int aux = b - a;
                    if(!(aux & 1))
                        ans = 2;
                    else
                        ans = 1;
                    printf("%d\n",ans);
                }
            }else{
                if(a - b == 2)
                    printf("1\n");
                else{
                    int ans = 0;
                    int aux = a - b;
                    if(aux & 1)
                        ans = 2;
                    else
                        ans = 1;
                    printf("%d\n",ans);
                }
            }
        }
    }
    return 0;
}
    
