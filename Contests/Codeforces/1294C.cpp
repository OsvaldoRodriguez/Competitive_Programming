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
const int N = 1 * 1e5 + 5;
const int mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
vector<ii> arr;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        bool flag = 1;
        int n;
        scanf("%d",&n);
        int i = 2;
        while(i * i < n){
            if(n % i == 0){
                int j = 2;
                while(j * j < (n / i)){
                    if((n / i) % j == 0){
                        if(i != j && i != (n / i / j) && j != (n / i / j)){
                            printf("YES\n%d %d %d\n",i,j,(n / i) / j);
                            j = i = n;
                            flag = 0;
                            break;
                            break;
                        }
                    }
                    j++;
                }
            }
            i++;
        }
        if(flag)
            printf("NO\n");
    }
    return 0;
}
