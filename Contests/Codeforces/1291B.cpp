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
const int N = 3 * 1e5 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
int v[N],ans[N];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        cls(ans,0);
        int n;
        scanf("%d",&n);
        bool sw = 1;
        fore(i,0,n){
            scanf("%d",v + i);
        }
        if(n == 1)
            printf("Yes\n");
        else if(n == 2){
            if(v[0] == 0 && v[1] == 0)
                printf("No\n");
            else 
                printf("Yes\n");
        }else{
            
            ans[n - 1] = 0;
            ans[0] = 0;
            bool flag = 1;
            for(int i = 0; i < (n + 1)/ 2;i++)
                ans[i] = ans[n - i - 1] = i;
            
            if(n & 1){
                fore(i,0,n){
                    if(ans[i] > v[i]){
                        flag = 0;
                        break;
                    }
                }
                if(flag)
                    printf("Yes\n");
                else
                    printf("No\n");
            }else{
                int mid = n / 2;
                ans[mid]++;
                bool sw = 1,sw1 = 1;
                fore(i,0,n){
                    if(ans[i] > v[i]){
                        sw = 0;
                        break;
                    }
                }
                ans[mid]--;
                mid--;
                ans[mid]++;
                fore(i,0,n){
                    if(ans[i] > v[i]){
                        sw1 = 0;
                        break;
                    }
                }
                if(sw or sw1)
                    printf("Yes\n");
                else
                    printf("No\n");

            }

            
        }
    }
    return 0;
}
