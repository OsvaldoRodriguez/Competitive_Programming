#include <bits/stdc++.h>
#define FIN         ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ii          pair<int,int>
#define F           first
#define S           second
#define pb          push_back
#define all(x)      (x).begin(),(x).end()
#define rall(x)     (x).rbegin(),(x).rend()
#define fore(i,a,b) for(int i = a;i < b; i+= 1)
#define forr(i,a)   for(int i = a; i >= 0; i--)
#define fori(i,m)   for(auto i = m.begin(); i != m.end(); i++) 
#define w(t)        while(t--)
#define sz(s)       int(s.size())
#define cls(a,car)  memset(a,car,sizeof (a))
#define db(x)       cerr << #x << " is " << x << '\n'
#define FL          freopen("input.txt", "r", stdin),freopen("output.txt", "w", stdout);
#define EjecuteTime cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n"
#define angle(x)    double(x * acos(-1) / 180.0)
using namespace std;
typedef long long   ll;
typedef vector<int> vi;
typedef vector<ii>  vii;
const int N = 1e5 + 50;
const ll mod = 1e9 + 7;
const double E = 1e-9;
//int dx[] = {0, -1}, dy[] = {-1, 0};
//int _dx[] = {0, 1}, _dy[] = {1, 0};
//int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
//int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
ll v[N], idx[N];
ll BIT[N];
int n;
void uptade(int pos, int val){
    for(int i = pos; i <= n; i += i&(-i))
        BIT[i] += val;
}
void build(){
    for(int i = 1; i <= n; i++)
        uptade(i, v[i]);
}
ll get(int pos){
    ll sum = 0;
    for(int i = pos; i > 0; i -= i&(-i))
        sum += BIT[i];
    return sum;
}
ll getSum(int pos_i, int pos_j){
    return get(pos_j) - get(pos_i - 1);
}
int main(){
    //FL;
    //FIN;
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        cls(BIT, 0);
        for(int i = 1; i <= n; i++){
            cin >> v[i];
            idx[v[i]] = i;
        }
        build();
        ll ans = 0;
        int mark = 1;
        for(int i = 1; i <= n; i++){


            int ini = mark;
            int end = idx[i] - 1;
            ll _aux;
            if(ini <= end)
                _aux = getSum(mark, idx[i] - 1);
            else
                _aux = getSum(mark, n) + getSum(1, end);
            ll cmp = getSum(1, n) - _aux;
            if(_aux == 0){
                mark = idx[i];
                uptade(idx[i], - v[idx[i]]);
                v[idx[i]] = 0;
                continue;
            }
            mark = idx[i];
            ans += min(_aux, cmp);
            uptade(idx[i], -v[idx[i]]);
            v[idx[i]] = 0;
        }
        cout << ans << '\n';
    }
    EjecuteTime;
    return 0;
}       