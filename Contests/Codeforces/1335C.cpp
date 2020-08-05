#include <bits/stdc++.h>
#define fin ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
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
typedef vector<int> vi;
typedef vector<ii> vii;
const int N = 2 * 1e5 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
const double E = 1e-9;
int v[N];
int main(){
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    fin;    
    int t;
    cin >> t;
    while(t--){
        cls(v, 0);
        int n;
        cin >> n;
        fore(i, 0, n){
            int x;
            cin >> x;
            v[x]++;
        }
        int mx = 0;
        int dif = 0;
        int aux = 0;
        fore(i,0, N){
            if(v[i]){
                dif++;
                if(v[i] > 1)
                    aux++;
                mx = max(mx, v[i] - 1);
            }
        }
        int ans = 0;
        if((mx == 0)){
            if(dif == 1)
                ans = 0;
            else
            ans = 1;
        }
        else{
            ans = min(mx, dif);
            ans = max(ans, min(mx + (aux != 0), dif - (aux != 0)));
        }
        //cout << mx << " " << dif << " " << aux << '\n';
        cout << ans << "\n";
    } 
    return 0;
}   
