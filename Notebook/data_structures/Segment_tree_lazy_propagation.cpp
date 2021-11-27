#include <bits/stdc++.h>
#define ii          pair<int,int>
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
    propagate   ->  O(1)
*/
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

    void update(int node, int a, int b, int i, int j, ll val){
        propagate(node, a, b);
        if(i > b or j < a or j < i)return;
        if(a >= i && b <= j){
            LAZY[node] += val;// reemplazar valor, para sumar  +=
            propagate(node, a, b); 
        }
        else{    
            int m = (a + b) >> 1;
            update(left(node), a, m, i, j, val);
            update(right(node), m + 1, b, i, j, val);
            ST[node] = f(ST[left(node)], ST[right(node)]);
        }
    }
    void propagate(int node, int a, int b){
        if(LAZY[node] != 0){
            ST[node] += 1ll * (b - a + 1) * LAZY[node];// reemplazar val, para sumar  +=
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
    void update(int i, int j, ll val){
        update(1, 0, N_MAX - 1, i, j, val);
    }
    ll f(ll a, ll b){
        return a + b;
    }

    int left(int x){return (x << 1);}
    int right(int x){return (x << 1) | 1;}

};
int main(){
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++){
        printf("Case %d:\n", i);
        int n, q;
        scanf("%d %d", &n, &q);
        vector<ll> v(n, 0LL);
        SegTreeLazy SL(n, v);
        SL.build();
        while(q--){
            int ope, x, y;
            ll z;
            scanf("%d %d %d", &ope, &x, &y);
            if(ope == 0){
                scanf("%lld", &z);
                SL.update(x, y, z);
            }else
                printf("%lld\n",SL.get(x, y));
        }
    }
    return 0;
}       
