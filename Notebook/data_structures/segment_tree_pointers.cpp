#include <bits/stdc++.h>
using namespace std;

struct st{ // informacion de cada nodo
    st *left, *right;
    int l, r, m; // l, r intervalo de cada nodo
    long long sum;
    long long ope(long long a, long long b){
        return a + b;
    }
    st(int l, int r, vector<int> &data) : l(l), r(r), sum(0){
        if(l == r)
            sum = data[l];
        else{
            m = (l + r) >> 1;
            left = new st(l, m, data);
            right = new st(m + 1, r, data);
            sum = ope(left -> sum, right -> sum);
        }
    }

    void update(int i, int v){
        if(l == r){
            sum = v;
        }else{
            if(i <= m)
                left -> update(i, v);
            else
                right -> update(i, v);
            sum = ope(left -> sum, right -> sum);
        }

    }

    long long get(int i, int j){// intervalo de consulta
        if(i <= l and r <= j)
            return sum;
        if(j <= m)
            return left -> get(i, j);
        if(i > m)
            return right -> get(i, j);

        return ope(left -> get(i, j), right -> get(i, j));
    }


};
int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    
    int n, m, ope, l, r;
    cin >> n >> m;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    st tree(0, n - 1, v);

    while(m--){
        cin >> ope >> l >> r;
        if(ope == 1)
            tree.update(l, r);
        else
            cout << tree.get(l, r - 1) << '\n';
    }


    return 0;
}
