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
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
int main(){  
    fast;
    int n,x;
    string s;
    cin >> n;
    int dir_y = 0;
    bool flag = 1;
    while(n--){
        cin >> x >> s;
        if(dir_y == 0 && s != "South")
            flag = 0;

        if(dir_y == 20000 && s != "North")
            flag = 0;
        if(s == "South"){
            dir_y += x;
            if(dir_y > 20000)
                flag = 0;
        }
        else if(s == "North"){
            dir_y -= x;
            if(dir_y < 0)
                flag = 0;
        }
    }
    if(flag && dir_y == 0)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
    
