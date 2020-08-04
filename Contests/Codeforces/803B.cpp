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
int v[N];
int dis[N];
int main(){
    int n;
    scanf("%d",&n);
    fore(i,0,n){
        dis[i] = (1 << 30);
        scanf("%d",v + i);
    }
    fore(i,0,n){
        if(v[i] == 0){
            int j = i + 1;
            int k = i - 1;
            dis[i] = 0;
            while(v[j] != 0 && j < n && dis[j - 1] + 1 < dis[j]){
                dis[j] = dis[j - 1] + 1;
                j++;
            }
            while(v[k] != 0 && k >= 0 && dis[k + 1] + 1 < dis[k]){
                dis[k] = dis[k + 1] + 1;
                k--;
            }
        }
    }
    fore(i,0,n)
        printf("%d ",dis[i]);
    
    return 0;
}
