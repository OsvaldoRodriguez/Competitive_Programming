#include "bits/stdc++.h"
// #include <ext/pb_ds/assoc_container.hpp> // Common file
// #include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#define fastio      ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll          long long
#define all(_)      (_).begin(), (_).end()
#define sz(_)       int(_.size())
#define pii         pair<int, int>
#define pll         pair<ll, ll>
using namespace std;
// using namespace __gnu_pbds; // ordered_set
const int N = 2e5 + 5;
const ll mod = 1e9 + 7;
const double eps = 1e-9;
// less<type>  prioridad menor
// greater<type>  prioridad mayor
// add equal<type>  less_equal or greater_equal // multiset
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
int di[] = {1, 0, 0, -1}, dj[] = {0, -1, 1, 0};
// string dir = "DLRU";
//**********************************************************************
// Later or Sooner discipline overcomes talent, come on, I can do it.

struct nodito{
    ll pref = 0;
    ll suf = 0;
    ll sum = 0;
    ll max_sum = 0;
    ll val = 0;

    nodito(ll a, ll b, ll c, ll suma, ll valor){
        pref = a;
        suf = b;
        sum = c;
        max_sum = suma;
        val = valor;
    }
};
struct SegTree{
    int N_MAX;
    vector<int> A;
    vector<nodito> ST;

    SegTree(int n, const vector<int> &B){
        N_MAX = n;
        ST.assign((N_MAX << 2) + 5, nodito(0, 0, 0, 0, 0));
        A = B;
    }
    void build(){
        build(1, 0, N_MAX - 1);
    }
    void build(int node, int a, int b){
        if(a == b)
            ST[node] = {A[a], A[a], A[a], A[a], A[a]};
        else{
            int m = (a + b) >> 1;
            build(left(node), a, m);
            build(right(node), m + 1, b);
            ST[node] = f(ST[left(node)], ST[right(node)]);
        }
    }
    nodito query(int node, int a, int b, int l, int r){
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
            ST[node] = {val, val, val, val, val};
        else{
            int m = (a + b) >> 1;
            if(i <= m)
                update(left(node), a, m, i, val);
            else
                update(right(node), m + 1, b, i, val);
            ST[node] = f(ST[left(node)], ST[right(node)]);
        }
    }
    nodito get(int i, int j){
        return query(1, 0, N_MAX - 1, i, j);
    }
    void update(int i, ll val){
        update(1, 0, N_MAX - 1, i, val);
    }
    nodito f(nodito a, nodito b){
        ll pref_max = max({a.pref, a.sum + b.pref});
        ll suf_max = max({b.suf, a.suf + b.sum});
        ll sum = a.sum + b.sum;
        ll cur = a.suf + b.pref;
        ll max_sum = max({pref_max, suf_max, sum, cur, a.max_sum, b.max_sum});
        ll val = a.val + b.val;
        return nodito(pref_max, suf_max, sum, max_sum, val);
    }

    int left(int x){return (x << 1);}
    int right(int x){return (x << 1) | 1;}

};

void solve(){
    
    int n;
    cin >> n;
    vector<int> v(n);
    for(int &i : v)
        cin >> i;
    SegTree ST(n, v);
    ST.build();
    int q;
    cin >> q;
    
    int l, r;
    for(int j = 0; j < q; j++){
        cin >> l >> r;
        l--;
        r--;
        cout << ST.get(l, r).max_sum << "\n";

    }
    
} 


int main(){
    fastio;
    int t = 1;
    // cin >> t;

    for(int i = 1; i <= t; i++){
        solve();
    }
    return 0;
}   
// solo recorre en los bits encendidos
// O(bits_encendidos en mask)
// for(int x = mask; x; x &= (x - 1)){
//     int v = __builtin_ctz(x); // da la posicion donde esta 
// }
