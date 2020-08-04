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
bool occ[110];
int v[110];
int n;
bool sort(){
    fore(i,1,n)
        if(v[i] < v[i - 1])
            return 0;
    return 1;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int m,x;
        cls(occ,0);
        scanf("%d%d",&n,&m);
        fore(i,0,n)
            scanf("%d",v + i);
        fore(i,0,m){
            scanf("%d",&x);
            x--;
            occ[x] = 1;
        }
        bool flag = 0;
        while(true){
            bool band = 0;
            if(sort()){
                flag = 1;
                break;
            }
            fore(i,0,n - 1){
                if(occ[i]){
                    if(v[i] > v[i + 1]){
                        band = 1;
                        swap(v[i + 1],v[i]);
                    }
                }
            }
            if(!band)
                break;
        }
        printf(flag?"YES\n":"NO\n");
    }
    return 0;
}
    
