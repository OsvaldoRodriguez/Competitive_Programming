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
    scanf("%d",&t);
    while(t--){
        int v[5];
        scanf("%d %d %d",&v[0],&v[1],&v[2]);
        sort(v, v + 3);
        reverse(v,v + 3);
        int ans = 0;
        for(int i = 0; i < (1 << 3); i++){
            bool flag = 1;
            int cont = 0;
            for(int j = 0; j < 3; j++){
                if(i & (1 << j)){
                    if(v[j] > 0)
                        cont++;
                    else
                        flag = 0;
                }
            }
            if(flag && cont){
                ans++;
                for(int j = 0; j < 3; j++)
                    if(i & (1 << j))
                        v[j]--;
            }


        }
        printf("%d\n",ans);
    }
    return 0;
}
    
