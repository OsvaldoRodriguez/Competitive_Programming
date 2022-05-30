#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 2;
struct SegTree{

    int N;
    vector<int> ST;
    vector<int> A;

    SegTree(int n, vector<int> &A){
        this -> N = n;
        this -> A = A;
        ST.assign((N << 2) + 5, 0);
    }

    void build(){
        build(1, 0, N - 1);
    }
    void build(int node, int l, int r){
        if(l == r){
            ST[node] = l;
        }else{
            int m = (l + r) >> 1;
            build(left(node), l, m);
            build(right(node), m + 1, r);
            ST[node] = f(ST[left(node)], ST[right(node)]);
        }
    }
    void update(int pos, int val){
        update(1, 0, N - 1, pos, val);
    }
    void update(int node, int l, int r, int pos, int val){
        if(l == r){
            A[pos] = val;
        }else{
            int m = (l + r) >> 1;
            if(pos <= m)
                update(left(node), l, m, pos, val);
            else
                update(right(node), m + 1, r, pos, val);

            ST[node] = f(ST[left(node)], ST[right(node)]);
        }
    }
    int query(int L, int R){
        return A[query(1, 0, N - 1, L, R)];
    }
    int query(int node, int l, int r, int L, int R){
        if(l >= L and  r <= R)
            return ST[node];

        int m = (l + r) >> 1;
        if(R <= m)
            return query(left(node), l, m, L, R);
        if(L > m)
            return query(right(node), m + 1, r, L, R);
        return f(query(left(node), l, m, L, R), query(right(node), m + 1, r, L, R));
    }

    int left(int x){return (x << 1);}
    int right(int x){return ((x << 1) | 1);}
    int f(int a, int b){
        return (A[a] < A[b] ? a : b);
    }

    void mostrar(){
        cout << "A \n";
        for(int i = 0; i < A.size(); i++)
            cout << i << " " << A[i] << endl;
        cout << "SEGMENT TREE\n";
        for(int i = 0; i < ST.size(); i++){
            cout << i << " " << ST[i] << endl; 
        }
    }

};
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> A;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        A.push_back(x);
    }

    SegTree ST(n, A);
    ST.build();

    cout << ST.query(0, 2);
    update(0, 3);
    return 0;
}
