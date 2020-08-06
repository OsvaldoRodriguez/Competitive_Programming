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
const int N = 1 * 1e6 + 5;
const ll mod = 1e9 + 7;
const double E = 1e-9;
int dx[] = {1, 0}, dy[] = {0, 1};
//int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
struct SegTree{
    int N_MAX;
    vector<int> ST, A;

    SegTree(int n, const vector<int> &B){
        N_MAX = n;
        ST.assign((N_MAX << 2) + 5, 0);
        A = B;
    }
    void build(int ope){
        build(1, 0, N_MAX - 1, ope);
    }
    void build(int node, int a, int b, int ope){
        if(a == b) 
            ST[node] = A[a];
        else{
            int m = (a + b) >> 1;
            build(left(node), a, m, ope - 1);
            build(right(node), m + 1, b, ope - 1);
            ST[node] = f(ST[left(node)], ST[right(node)], ope);
        }
    }
    int query(int node, int a, int b, int l, int r, int ope){
        int m = (a + b) >> 1;
        if(a >= l && b <= r)
            return ST[node];
        if(r <= m)
            return query(left(node), a, m, l, r, ope - 1);
        if(l > m)
            return query(right(node), m + 1, b, l, r, ope - 1);
        return f(query(left(node), a, m, l, r, ope - 1), query(right(node), m + 1, b, l, r, ope - 1), ope);
    }

    void update(int node, int a, int b, int i, int val, int ope){
        if(a == b)
            ST[node] = val;
        else{
            int m = (a + b) >> 1;
            if(i <= m)
                update(left(node), a, m, i, val, ope - 1);
            else
                update(right(node), m + 1, b, i, val, ope - 1);

                ST[node] = f(ST[left(node)], ST[right(node)], ope);
        }
    }
    int get(int i, int j, int ope){
        return query(1, 0, N_MAX - 1, i, j, ope);
    }
    void update(int i, int val, int ope){
        update(1, 0, N_MAX - 1, i, val, ope);
    }
    int f(int a, int b, int ope){
        if(ope & 1)
            return a | b;
        return a ^ b;
    }
    int left(int x){return (x << 1);}
    int right(int x){return (x << 1) | 1;}

};
int main(){
    //FL;
    FIN;
    int n, m;
    cin >> n >> m;
    vi v(1 << n);
    for(auto &i : v)
        cin >> i;
    SegTree tree(1 << n, v);
    tree.build(n);
    while(m--){
        int l, r;
        cin >> l >> r;
        l--;
        tree.update(l, r, n);
        cout << tree.get(0, (1 << n) - 1, n) << '\n';
    }
    EjecuteTime;
    return 0;
}       
