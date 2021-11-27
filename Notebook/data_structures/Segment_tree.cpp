#include <bits/stdc++.h>
#define ii          pair<int,int>
#define sz(s)       int(s.size())
using namespace std;
typedef long long   ll;
typedef vector<int> vi;
typedef vector<ii>  vii;
const int N = 1 * 1e4 + 5;

/*
Complexity
Space:  
    build   ->  O(n)
Time:
    build   ->  O(n)
    update  ->  O(log (n))
    query   ->  O(log (n))
*/
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
        return a < b ? a : b;
    }

    int left(int x){return (x << 1);}
    int right(int x){return (x << 1) | 1;}

};
int main(){
    int n, m;
    cin >> n >> m;
    vi v(n);
    for(auto &i : v)
        cin >> i;
    SegTree tree(n, v);
    tree.build();
    while(m--){
        int op, l, r;
        cin >> op >> l >> r;
        if(op == 1)
            tree.update(l, r);
        else
            cout << tree.get(l, r - 1) << '\n';
    }
    return 0;
}       
