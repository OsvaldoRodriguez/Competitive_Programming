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
int arr[100][100];
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    if(n * n < k)
        printf("-1\n");
    else{
        fore(i,0,n){
            fore(j,0,n){
                if(arr[i][j] == 0)
                if(i == j && k > 0){
                    arr[i][j] = 1;
                    k--;
                }else{
                    if(k > 1){
                        arr[i][j] = arr[j][i] = 1;
                        k -= 2;
                    }
                }
            }
        }
        fore(i,0,n){
            fore(j,0,n){
                printf("%d ", arr[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
