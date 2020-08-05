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
    scanf("%d",&t);
    while(t--){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        int mn = 1 << 30;
        int a1 = -1,b1 = -1,c1 = -1;
        fore(i,1,10004){
            for(int j = i; j < 2e4; j+= i)
                for(int k = j; k < 2e4; k += j){
                    int aux = abs(a - i) + abs(j - b) + abs(k - c);
                    if(aux < mn){
                        a1 = i;
                        b1 = j;
                        c1 = k;
                        mn = aux;
                    }
                }
        }
        printf("%d\n",mn);
        printf("%d %d %d\n",a1,b1,c1);
    }
    return 0;
}
