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
int v[105];
int main(){ 
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int sum = 0;
        int prod = 1;
        fore(i,0,n){
            scanf("%d",v + i);
            sum += v[i];
            prod *= v[i];
        }
        if(sum != 0 && prod != 0)
            printf("0\n");
        else{
            int tmp = 0;
            fore(i,0,n){
                if(v[i] == 0){
                    tmp++;
                }
            }
            if(tmp + sum != 0)
                printf("%d\n",tmp);
            else
            printf("%d\n",tmp + 1);
        }
    }
    return 0;
}
    
