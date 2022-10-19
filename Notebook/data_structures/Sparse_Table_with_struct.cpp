#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
typedef  long long ll;

/*
Complextity
Space: 
    build   ->  O(log(n) * n)
Time:
    build   ->  O(log (n) * n)
    query   -> O(1) 
*/
struct SparseTable{
    int N_MAX;
    int LOG;
    vector<vector<int>> ST;
    vector<int> A;
    SparseTable(){
        N_MAX = LOG = 0;
    }
    SparseTable(vector<int> &v){
        N_MAX = (int) v.size();
        LOG = 31 - __builtin_clz(N_MAX);
        ST.assign(LOG + 2, vector<int> (N_MAX));
        A = v;
    }
    int f(int a, int b){
        return max(a, b);
    }
    void build(){
        for(int i = 0; i < N_MAX; i++)
            ST[0][i] = A[i];
        for(int i = 1; (1 << i) <= N_MAX; i++){
            for(int j = 0; j + (1 << i) - 1 < N_MAX; j++){
                ST[i][j] = f(ST[i - 1][j], ST[i - 1][j + (1 << (i - 1))]);
            }
        }
    }
    
    int query_log_n(int L, int R){
        int len = R - L + 1;
        int ans = 1e9;
        for(int i = LOG; i >= 0; i--){
            if((1 << i) & len){
                ans = f(ans, ST[i][L]);
                L += (1 << i);
            }
        }
        return ans;
    }
    int query(int L, int R){
        int len = R - L + 1;
        int log = 31 - __builtin_clz(len);

        return f(ST[log][L], ST[log][R - (1 << log) + 1]);
    }

    void mostrar(){
        for(int i = 0; i <= LOG; i++) {
            for(int j = 0; j < N_MAX; j++)
                cout << ST[i][j] << " ";
            cout << endl;
        }

    }
};

int main(){

    int n;
    cin >> n;
    vector<int> A(n);
    for(int &i : A)cin >> i;

    SparseTable ST(A);
    
    ST.build();
    
    cout << ST.query(0, 5) << '\n';
    cout << ST.query(0, 3) << '\n';

    return 0;
}

/*
6
1 4 3 0 7 3
*/
