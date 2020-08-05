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
const int N = 1 * 1e5 + 5;
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
    int n;
    cin >> n;
    int A[n + 1], B[n + 1];
    int costA = 0, costB = 0;
    fore(i, 0, n){
        cin >> A[i] >> B[i];
        costA += A[i];
        costB += B[i];
    }
    int i = 0;
    string ans = "";
    if(costA >= costB){
        costB = 0;
        fore(i, 0, n)
            ans += 'A';
        while(abs(costA - costB) > 500){
            costA -= A[i];
            costB += B[i];
            ans[i] = 'G';
            i++;
        }
    }else if(costB > costA){
        costA = 0;
        fore(i, 0, n)ans += 'G';
        while(abs(costB - costA) > 500){
            costB -= B[i];
            costA += A[i];
            ans[i] = 'A';
            i++;
        }
    }
    if(abs(costA - costB) > 500)
        cout << -1 << '\n';
    else
        cout << ans << '\n';
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}   
