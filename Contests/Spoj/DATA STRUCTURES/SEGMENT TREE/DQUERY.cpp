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

struct SegTree{
    int N_MAX;
    vector<int> ST, A;

    SegTree(int n, const vector<int> &B){
        N_MAX = n;
        ST.assign((N_MAX << 2) + 5, 0);
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
    int query(int node, int a, int b, int l, int r){
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
            ST[node] = val;
        else{
            int m = (a + b) >> 1;
            if(i <= m)
                update(left(node), a, m, i, val);
            else
                update(right(node), m + 1, b, i, val);
            ST[node] = f(ST[left(node)], ST[right(node)]);
        }
    }
    int get(int i, int j){
        return query(1, 0, N_MAX - 1, i, j);
    }
    void update(int i, ll val){
        update(1, 0, N_MAX - 1, i, val);
    }
    int f(int a, int b){
        return a + b;
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
    vector<int> A(1e6 + 5, 0);
    SegTree ST(1e6 + 5, A);

    int q;
    cin >> q;
    vector<tuple<int, int, int>> queries(q);
    vector<int> last(1e6 + 5, -1), ans(q);

    for(int j = 0; j < q; j++){
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        queries[j] = tie(r, l, j);
    }
    sort(all(queries));
    for(int i = 0; i < q; i++){
        int l, r, pos;
        tie(r, l, pos) = queries[i];
        // cout << l <<  " " << r << " " << pos << endl;
    }

    int j = 0;
    for(int i = 0; i < q; i++){
        int l, r, pos;
        tie(r, l, pos) = queries[i];
        while(j <= r){
            int pos_last = last[v[j]];
            if(pos_last != -1)
                ST.update(pos_last, 0);
            
            last[v[j]] = j;
            ST.update(j, 1);
            j++;
            // cout << "ST\n";
            // for(int k = 0; k < n; k++){
            //     cout << ST.get(k, k) << " ";
            // }
            // cout << endl;
        }
        // cout << l << " " << r << " " << j << endl;
        ans[pos] = ST.get(l, r);
    }

    for(int i = 0; i < q; i++)
        cout << ans[i] << "\n";
    
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
