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
const int N = 2 * 1e5 + 50;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1; 
int arr[1005];
int v[105];
int main(){
    int n;  
    cls(arr,0);
    scanf("%d",&n);
    fore(i,0,n){
        int x;
        scanf("%d",&x);
        arr[x]++;
        v[i] = x;
    }
    int ans = 0;
    fore(i,0,n){
        fore(j,i,n){
            if(v[j] - v[i] == j - i){
                if(i == 0 && j + 1 == n){
                    if(v[i] == 1 or v[j] == 1000)
                        ans = max(ans,j - i);
                    else ans = max(ans,j - i - 1);
                }
                if(v[j] == j + 1 && v[i] == i + 1)
                    ans = max(ans,j - i);
                if(i == 0 && j < n + 1 && v[j] - v[i] == j - i){
                    if(v[j] == j + 1)
                        ans = max(ans,j - i);
                    else ans = max(ans,j - i - 1);
                }
                if(i > 0 && j < n + 1 && v[j] - v[i] == j - i){
                    ans = max(ans,j - i - 1);
                }
                if(i > 0 && j + 1 == n && v[j] - v[i] == j - i){
                    if(v[n - 1] != 1000)
                        ans = max(ans,j - i - 1);
                    else ans = max(ans, j - i);
                }

            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
