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
int v[1005];
int color[1005];
int pos[1005];
vector<ii> pr;
//freopen("","r",stdin);
//freopen("","w",stdout);
int main(){
    int k = 0;
    for(int i = 2; i < 1005; i++)
        if(!v[i]){
            for(int j = i + i; j < 1005; j += i)
                v[j] = 1;
        }

    fore(i,2,1005)
        v[i] = i;
    for(int i = 2; i * i < 1005; i++){
        if(v[i] == i)
            for(int j = i * i; j < 1005; j += i)
                if(v[j] == j)
                    v[j] = i;
    }

    int t,n;
    scanf("%d",&t);
    while(t--){
        cls(color,-1);
        cls(pos,-1);
        scanf("%d",&n);
        vector<int> arr(n);
        for(auto  &i : arr)
            cin >> i;
        int col = 1;
        fore(i,0,n){
            int j = arr[i];
            bool flag = 1;
            //printf("%d : ",j);
            while(j != 1 && flag){
                if(pos[v[j]] == -1){
                    pos[v[j]] = col++;
                }
                color[i] = pos[v[j]];
                flag = 0;
                //printf("%d ",v[j]);
                j /= v[j];
            }
           // printf("\n");
        }
        int mx = 0;
        fore(i,0,1005)
            mx = max(mx,color[i]);
        //printf("Sol\n");
        printf("%d\n",mx);
        fore(i,0,n){
            printf("%d ",color[i]);
        }
        printf("\n");
    }
    return 0;
}
