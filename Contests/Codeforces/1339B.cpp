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
typedef vector<int> vi;
typedef vector<ii> vii;
const int N = 1 * 1e6 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
const double E = 1e-9;
int main(){
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    fast;
    int t;
    cin >> t;
    int n;
    while(t--){
        cin >> n;
        vector<ll> p;
        fore(i, 0, n){
            ll x;
            cin >> x;
            p.pb(x);
        }
        sort(all(p));
        vi aux;
        int i,j;
        if(n & 1){
            i = j = n / 2;
            aux.pb(p[i]);
        }
        else{
            j = n / 2;
            i = n / 2 - 1;
            aux.pb(p[i]);
            aux.pb(p[j]);
        }
        int abs1 = abs(p[i] - p[j]);
        i--;
        j++;
        while(1){
            if(i < 0 && j >= n){
                break;
            }
            ll dif = aux[sz(aux) - 1];
           // cout << dif << " dof " << abs1 << endl;
            if(abs(dif - p[i]) >= abs1){
                if(i >= 0 && sz(aux) < n)
                    aux.pb(p[i]);
                if(j < n && sz(aux) < n)
                    aux.pb(p[j]);
            }else{
                if(j < n && sz(aux) < n)
                    aux.pb(p[j]);
                if(i >= 0 && sz(aux) < n)
                    aux.pb(p[i]);
            }
            abs1 = abs(aux[sz(aux) - 1] - aux[sz(aux) - 2]);
            i--;
            j++;
        }
        /*fore(i, 0, sz(p))
            cout << p[i] << ' ';cout << endl;
        cout << "ans\n";
        */fore(i,0, sz(aux))
            cout << aux[i] << ' ';
            cout << '\n';
        /*fore(i, 0, sz(aux) - 1)
            cout << abs(aux[i] - aux[i + 1]) << ' ';
            cout << endl;
    */}
    return 0;
}   
