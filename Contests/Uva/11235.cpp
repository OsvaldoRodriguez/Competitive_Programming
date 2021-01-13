#include <bits/stdc++.h>
#define ii              pair<int,int>
#define F               first
#define S               second
#define pb              push_back
#define all(x)          (x).begin(),(x).end()
#define rall(x)         (x).rbegin(),(x).rend()
#define fore(i, a, b)   for(int i = a; i < b; i += 1)
#define forr(i, a)      for(int i = a; i >= 0; i--)
#define sz(s)           int(s.size())
#define cls(a,car)      memset(a,car,sizeof (a))
#define db(x)           cout << #x << " is " << x << '\n'
#define angle(x)        double(x * acos(-1) / 180.0)
using namespace std;
void debug(){cout << endl;}
template<typename T, typename... Args>
void debug(T a, Args... args){cout << a << " "; debug(args...);}
typedef long long   ll;
typedef vector<int> vi;
typedef vector<ii>  vii;
const int N = 2e5 + 10;
const ll mod = 1e9 + 7;
const double E = 1e-7;
const int oo = 1e9;

struct nd{
    int mx, nmx, pref, npref, suf, nsuf;
    nd(): mx(0), nmx(0), pref(0), npref(0), suf(0), nsuf(0){};
    nd(int val){
        mx = pref = suf = val;
        nmx = npref = nsuf = 1;
    } 
    nd(int _mx, int _nmx, int _pref, int _npref, int _suf, int _nsuf){
        mx = _mx;
        nmx = _nmx;
        pref = _pref;
        npref = _npref;
        suf = _suf;
        nsuf = _nsuf;
    }
};
struct SegTree{
    int N_MAX;
    vector<nd> ST;
    vector<int> A;

    SegTree(int n, const vector<int> &B){
        N_MAX = n;
        ST.assign((N_MAX << 2) + 5, nd());
        A = B;
    }
    void build(){
        build(1, 0, N_MAX - 1);
    }
    void build(int node, int a, int b){
        if(a == b)
            ST[node] = nd(A[a]);
        else{
            int m = (a + b) >> 1;
            build(left(node), a, m);
            build(right(node), m + 1, b);
            ST[node] = f(ST[left(node)], ST[right(node)]);
        }
    }
    nd query(int node, int a, int b, int l, int r){
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
            ST[node] = nd(val);
        else{
            int m = (a + b) >> 1;
            if(i <= m)
                update(left(node), a, m, i, val);
            else
                update(right(node), m + 1, b, i, val);
            ST[node] = f(ST[left(node)], ST[right(node)]);
        }
    }
    nd get(int i, int j){
        return query(1, 0, N_MAX - 1, i, j);
    }
    void update(int i, ll val){
        update(1, 0, N_MAX - 1, i, val);
    }
    nd f(nd A, nd B){
        int mx, nmx, pref, npref, suf, nsuf;
        
        if(A.nmx > B.nmx){
            mx = A.mx;
            nmx = A.nmx;
        }else{
            mx = B.mx;
            nmx = B.nmx;
        }

        if(A.suf == B.pref && A.nsuf + B.npref > nmx){
            mx = A.suf;
            nmx = A.nsuf + B.npref;
        }

        pref = A.pref;
        npref = A.npref;
        if(A.pref == B.pref)
            npref += B.npref;
        
        suf = B.suf;
        nsuf = B.nsuf;
        if(A.suf == B.suf)
            nsuf += A.nsuf;

        return nd(mx, nmx, pref, npref, suf, nsuf);
    }

    int left(int x){return (x << 1);}
    int right(int x){return (x << 1) | 1;}

};
void solve(){
    int n, m, l, r;
    while(cin >> n >> m){
        vi v(n);
        for(auto &i : v)cin >> i;
        SegTree ST(n, v);
        ST.build();
        while(m--){
            cin >> l >> r;
            l--;r--;
            cout << ST.get(l, r).nmx << '\n';
        }
    }
}
int main(){
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
       ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #endif

    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++){
        solve();
    }

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}
