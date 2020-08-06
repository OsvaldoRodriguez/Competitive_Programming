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
#define what_is(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ii> vii;
const int N = 1 * 1e6 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
const double E = 1e-9;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
int main(){
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    fin;
    int t;
    cin >> t;
    w(t){
        ll n, k;
        cin >> n >> k;
        if(n == k){
            cout << "YES\n";
            fore(i, 0, k)
                cout << 1 << ' ';cout << '\n';
        }else{
            if(k == 1){
                cout << "YES\n" << n << "\n";
            }else{
                bool ok = 0;
                vi arr;
                ll sum = 0;
                ll nn = n;
                    ll kk = k - 1;
                    bool flag  = 1;
                    w(kk){
                        sum += 2;
                        nn -= 2;
                        arr.pb(2);
                        if(nn < 0)
                           flag = 0; 
                    }   
                        if(nn > 0 && nn % 2 == 0){
                            arr.pb(nn);
                            sum += nn;
                        }
                    
                    if(sum == n && flag && sz(arr) == k){
                        cout << "YES\n";
                        for(auto i : arr)
                            cout << i << " ";cout << endl;
                    }else{
                        sum = 0;
                        arr.clear();
                        nn = n;
                        kk = k - 1;
                        flag = 1;
                        w(kk){
                            sum++;
                            nn--;
                            arr.pb(1);
                            if(nn < 0)
                                flag = 0;
                        }
                        if(nn > 0 && (nn & 1)){
                            arr.pb(nn);
                            sum += nn;
                        }
                        if(sum == n && flag && sz(arr) == k){
                            cout << "YES\n";
                            for(auto i : arr)cout << i << ' ';cout << '\n';
                        }else cout << "NO\n";

                    }

            }
        }
    }
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}   
