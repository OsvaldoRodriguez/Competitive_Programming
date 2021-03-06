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
const int N = 1 * 1e4 + 5;
const ll mod = 1e9 + 7;
const double E = 1e-9;
int dx[] = {1, 0}, dy[] = {0, 1};
//int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
struct SegTreeLazy{
    int N_MAX;
    vector<ll> ST, A, LAZY;
    SegTreeLazy(int n, const vector<ll> &B){
        N_MAX = n;
        ST.assign((N_MAX << 2) + 5, 0);
        LAZY.assign((N_MAX << 2) + 5, 0);
        A = B;
    }
    void build(){
        build(1, 0, N_MAX - 1);
    }
    void build(int node, int a, int b){
        if(a == b)
            ST[node] = A[a];
        else{
            int m = (a + b) >> 1;
            build(left(node), a, m);
            build(right(node), m + 1, b);
            ST[node] = f(ST[left(node)], ST[right(node)]);
        }
    }
    ll query(int node, int a, int b, int l, int r){
        propagate(node, a, b);
        int m = (a + b) >> 1;
        if(a >= l && b <= r)
            return ST[node];
        if(r <= m)
            return query(left(node), a, m, l, r);
        if(l > m)
            return query(right(node), m + 1, b, l, r);
        return f(query(left(node), a, m, l, r), query(right(node), m + 1, b, l, r));
    }

    void update(int node, int a, int b, int i, int j, ll val, int ope){
        propagate(node, a, b);// veriifcar si tengo algo pendiente
        if(i > b or j < a or j < i)return;
        if(a >= i && b <= j){
            LAZY[node] += val;// reemplazar valor, para sumar  +=
            propagate(node, a, b); 
        }
        else{    
            int m = (a + b) >> 1;
            update(left(node), a, m, i, j, val, ope);
            update(right(node), m + 1, b, i, j, val, ope);
            ST[node] = f(ST[left(node)], ST[right(node)]);
        }
    }
    void propagate(int node, int a, int b){
        if(LAZY[node] != 0){
            ST[node] += LAZY[node];// reemplazar val, para sumar  +=
            if(a != b){
                LAZY[left(node)] += LAZY[node];
                LAZY[right(node)] += LAZY[node];
            }
            LAZY[node] = 0;
        }
    }
    ll get(int i, int j){
        return query(1, 0, N_MAX - 1, i, j);
    }
    void update(int i, int j, int val, int ope){
        update(1, 0, N_MAX - 1, i, j, val, ope);
    }
    ll f(ll a, ll b){
        return a < b ? a : b;
    }

    int left(int x){return (x << 1);}
    int right(int x){return (x << 1) | 1;}

};

ll to_int(string &a){
    ll ans = 0;
    int start = 0;
    if(a[0] == '-')
        start = 1;
    for(int i = start; i < a.size(); i++)
        ans = ans * 10 + (a[i] - '0');
    if(a[0] == '-')
        ans *= -1;
    return ans;   
}
int main(){
    //FL;
    FIN;
    int n;
    cin >> n;
    vector<ll> v(n);
    for(auto &i : v)cin >> i;
    SegTreeLazy tree(n, v);
    tree.build();
    int q;
    cin >> q;
    cin.ignore();
    w(q){
        string str;
        getline(cin, str);
        vector<ll> aux;
        for(int i = 0; i < sz(str); i++){
            string cur = "";
            while(i < sz(str) and str[i] != ' ')
                cur += str[i++];
            aux.pb(to_int(cur));
        }
        if(sz(aux) == 2){
            if(aux[0] <= aux[1])
                cout << tree.get(aux[0], aux[1]) << '\n';
            else
            cout << min(tree.get(aux[0], n - 1), tree.get(0, aux[1])) << '\n';
        }
        else{
            if(aux[0] <= aux[1])
                tree.update(aux[0], aux[1], aux[2], 1);
            else{
                tree.update(aux[0], n - 1, aux[2], 2);
                tree.update(0, aux[1], aux[2], 2);
            }
        }
    }
    EjecuteTime;
    return 0;
}       
