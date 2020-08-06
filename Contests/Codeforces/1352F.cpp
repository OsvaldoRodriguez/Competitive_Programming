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
        int a, b, c;
        cin >> a >> b >> c;
        if(b == 0){
            for(int i = 0; i <= max(a, c); i++)
                cout << (a ? 0 : 1);
            cout << '\n';
        }else{
            string aux = "";
            if(c)
            fore(i, 0, c + 1)
                aux += '1';
            if(a){
                fore(i, 0, a + 1)
                    aux = '0' + aux;
                b--;
            }
            int lim = b;
            if(aux == "" or !c)
                lim++;
            fore(i, 0, lim){
                if(c)
                    aux += (i & 1 ? '1' : '0');
                else
                    aux += (i & 1 ? '0' : '1');
            }
            cout << aux <<  '\n';
        }
    }
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}   
