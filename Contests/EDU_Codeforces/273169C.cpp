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
const int N = 3 * 1e5 + 5;
const ll mod = 1e9 + 7;
const double E = 1e-9;
//int dx[] = {1, 0}, dy[] = {0, 1};
//int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
struct SegTree{
    int N_MAX;
    vector<ii> A, ST;
    SegTree(int n, const vector<int> &B){
        N_MAX = n;
        ST.assign((N_MAX << 2) + 5, {0, 0});
        A.assign((N_MAX << 2) + 5, {0, 0});
        for(int i = 0; i < n; i++){
            A[i].F = B[i];
            A[i].S = 1;
        }
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
    ii query(int node, int a, int b, int l, int r){
        int m = (a + b) >> 1;
        if(a >= l && b <= r)
            return ST[node];
        if(r <= m)
            return query(left(node), a, m, l, r);
        if(l > m)
            return query(right(node), m + 1, b, l, r);
        return f(query(left(node), a, m, l, r), query(right(node), m + 1, b, l, r));
    }

    void update(int node, int a, int b, int i, int val){
        if(a == b)
            ST[node] = {val, 1};
        else{
            int m = (a + b) >> 1;
            if(i <= m)
                update(left(node), a, m, i, val);
            else
                update(right(node), m + 1, b, i, val);
            ST[node] = f(ST[left(node)], ST[right(node)]);
        }
    }
    ii get(int i, int j){
        return query(1, 0, N_MAX - 1, i, j);
    }
    void update(int i, ll val){
        update(1, 0, N_MAX - 1, i, val);
    }
    ii f(ii a, ii b){
        if(a.F == b.F)
            return {a.F, a.S + b.S};
        if(a.F < b.F)
            return a;
        return b;
    }

    int left(int x){return (x << 1);}
    int right(int x){return (x << 1) | 1;}

};
int main(){
    //FL;
    //FIN;
    int n, m;
    cin >> n >> m;
    vi v(n);
    for(int &i : v)cin >> i;
    SegTree tree(n, v);
    tree.build();
    w(m){
        int op, l, r;
        cin >> op >> l >> r;
        if(op == 2){
            ii cur = tree.get(l, r - 1);
            cout << cur.F << " " << cur.S << '\n';
        }
        else
            tree.update(l, r);
    }
    EjecuteTime;
    return 0;
}       
