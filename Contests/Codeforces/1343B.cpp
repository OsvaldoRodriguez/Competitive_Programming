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
const int N = 1 * 1e5 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
const double E = 1e-9;
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
        int n;
        cin >> n;
        int aux = n / 2;
        if(aux & 1)
            cout << "NO\n";
        else{
            cout << "YES\n";
            vi arr1, arr2;
            int even = 2;
            int odd = 1;
            bool flag = 1;
            fore(i, 0, aux){
                if(flag){
                    arr1.pb(even);
                    flag = 0;
                    even += 2;
                    arr2.pb(odd);
                    odd += 2;
                }else{
                    odd += 2;
                    arr1.pb(even);
                    arr2.pb(odd);
                    flag = 1;
                    even += 2;
                    even += 2;
                    odd += 2;
                }
            }
            for(auto i : arr1){
                cout << i << ' ';
            }
            for(auto i : arr2){
                cout << i << ' ';
            }
                cout << '\n';
        }
    }
    return 0;
}   
