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
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    // /sfast;
    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> v(n),color(n,0);
        for(auto &i : v)
            cin >> i;
        color[0] = 0;
        int idx = -1;
        fore(i,1,n){
            if(v[i] != v[i - 1])
                color[i] = color[i - 1] ^ 1;
            else{
                idx = i;
                color[i] = color[i - 1];
            }

        }
        int aux = v[0],cnt = 0;
        fore(i,0,n)
            if(v[i] == aux)
                cnt++;
        if(cnt == n){
            cout << 1 << '\n';
            fore(i,0,n)
                cout << 1 << ' ';
            cout << '\n';
            continue;
        }
        if(color[0] == color[n - 1]){ 
            if(idx == -1){
                if(v[0] != v[n - 1])
                    color[n - 1] = 2;
            }
            else{
                color[idx] ^= 1;
                fore(i,idx + 1, n){
                    if(v[i] != v[i - 1])
                        color[i] = color[i - 1] ^ 1;
                    else{
                        idx = i;
                        color[i] = color[i - 1];
                    }
                }
            }
        }
        int mx = 0;
        for(auto i : color)
            mx = max(mx,i);
        cout << mx + 1 << '\n';
        for(auto i : color)
           cout <<  i + 1 << ' ';cout << '\n'; 
    }
	return 0;
}
