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
#define ff(x) cerr << #x << " is " << x << '\n'
#define FL freopen("in", "r", stdin),freopen("out", "w", stdout);
#define time cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n"
using namespace std;
typedef unsigned long long ll;
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
    //FL;
    //fin;
    int t;
    cin >> t;
    w(t){
        int n;
        cin >> n;
        int l = 1, r = n;
        int v[n + 1];
        if(n <= 2){
            fore(i, 1, n + 1)
                cout << i << ' ';
                cout << '\n';
                continue;
        }
        priority_queue< pair < int, ii >, vector<pair < int, ii > > ,greater<pair < int, ii > > > p;
        int aux = r - l + 1;
        int mid = 0;
        if(aux & 1)
            mid = (l + r) >> 1;
        else
            mid = (l + r - 1) >> 1;
            
        v[mid] = 1;
        int cur = (mid - 1) - l + 1;
        p.push({-cur, {l, mid - 1}});
        cur = r - (mid + 1) + 1;
        p.push({-cur, {mid + 1, r}});
        int cnt = 2;

        
        while(sz(p)){
            pair<int, ii> df = p.top();
            p.pop();
            l = df.S.F;
            r = df.S.S;
            aux = r - l + 1;
            if(aux & 1)
                mid = (l + r) >> 1;
            else
                mid = (l + r - 1) >> 1;
            v[mid] = cnt++;
            cur = (mid - 1) - l + 1;
            if(cur > 0)
                p.push({-cur, {l, mid - 1}});
            cur = r - (mid + 1) + 1;
            if(cur > 0)
                p.push({-cur, {mid + 1, r}});

        }
        fore(i, 1, n + 1)
            cout << v[i] << ' ';cout << '\n';

    }
    time;
    return 0;
}   
