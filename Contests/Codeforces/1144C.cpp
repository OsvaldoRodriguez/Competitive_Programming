#include <bits/stdc++.h>
#define fin ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
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
#define w(t) while(t--)
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
// fflush(stdout)
// cout << flush
int pre[N];
int main(){
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    fin;
    int n;
    cin >> n;
    vector<int> inc,dec;
    fore(i, 0, n){
        int x;
        cin >> x;
        pre[x]++;
    }
    bool flag = 1;
    fore(i, 0, N)
        if(pre[i] > 2){
            flag = 0;
            break;
        }
    if(!flag)
        cout << "NO\n";
    else{
        fore(i, 0, N){
            if(pre[i] != 0){
                if(pre[i] == 2){
                    inc.pb(i);
                    dec.pb(i);
                }
                else
                    inc.pb(i);
            }
        }
    
    sort(all(inc));
    sort(all(dec));
    reverse(all(dec));
    cout << "YES\n";
    cout << sz(inc) << '\n';
    for(auto i : inc)
        cout << i << ' ';cout << '\n';

    cout << sz(dec) << '\n';
    for(auto i : dec)
        cout << i << ' ';cout << '\n';
}
    return 0;
}   