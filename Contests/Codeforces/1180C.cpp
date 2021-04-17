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
#define FL          freopen("in", "r", stdin),freopen("out", "w", stdout);
#define EjecuteTime cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n"
#define angle(x)    double(x * acos(-1) / 180.0)
using namespace std;
typedef long long   ll;
typedef vector<int> vi;
typedef vector<ii>  vii;
const int N = 1 * 1e6 + 5;
const ll mod = 1e9 + 7;
const double E = 1e-9;
//int dx[] = {1, 0}, dy[] = {0, 1};
//int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
deque<int> dq;
vii arr, cycle;
int main(){
    //FL;
    FIN;
    int n, q;

    cin >> n >> q;
    int mx = 0;
    fore(i, 0, n){
        int x;
        cin >> x;
        dq.push_back(x);
        mx = max(mx, x);
    }
    int cur = 0;
    while(dq.front() != mx){
        int aux = dq.front();
        dq.pop_front();
        int aux_2 = dq.front();
        dq.pop_front();
        arr.pb({aux, aux_2});
        if(aux < aux_2)
            swap(aux, aux_2);
        dq.push_front(aux);
        dq.push_back(aux_2);
        cur += 1;
    }
    dq.pop_front();
    while(sz(dq)){
        cycle.pb({mx, dq.front()});
        dq.pop_front();
    }
    w(q){
        ll X;
        cin >> X;
        if(X > cur){
            X -= cur;
            X--;
            X %= (sz(cycle));
            //db(X);
            cout << cycle[X].F << " " << cycle[X].S << '\n';
        }else cout << arr[X - 1].F << " " << arr[X - 1].S << '\n';
    }
    EjecuteTime;
    return 0;
}       