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
#define db(x) cerr << #x << " is " << x << '\n'
#define FL freopen("in", "r", stdin),freopen("out", "w", stdout);
#define EjecuteTime cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n"
#define angle(x) double(x * acos(-1) / 180.0)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ii> vii;
const int N = 1 * 1e5 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
const double E = 1e-9;
//int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
int v[N];
int main(){
    //FL;
    fin;
    int t;
    cin >> t;
    w(t){
        int n;
        cin >> n;
        fore(i, 0, n)cin >> v[i];
        int i = 1;
        int last = 0;
        vi idx;
        idx.pb(0);
        while(i < n){
            if(v[i] == v[i - 1]){
                i++;
                continue;
            }
            else if(v[i] < v[i - 1]){
                while(i < n && v[i] < v[i - 1])
                    i++;
                idx.pb(i - 1);
            }else{
                while(i < n && v[i] > v[i - 1])
                    i++;
                idx.pb(i - 1);
            }
        }   
        cout << sz(idx) << '\n';
        for(auto i : idx)cout << v[i] << ' ';
            cout << '\n';

    }
    EjecuteTime;
    return 0;
}       

