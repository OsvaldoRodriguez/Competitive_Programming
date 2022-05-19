#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int LOG = 20;
int A[N], ST[LOG + 1][N];
int logs2[N];
int n;
int f(int a, int b){
    return min(a, b);
}
 
// Complexity O(log n)
int query(int L, int R){
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
// Complexity O(1)
int _query(int L, int R){
    int len = R - L + 1;
    // int log = 32 - __builtin_clz(len) - 1;
    int log = logs2[len];
    return f(ST[log][L], ST[log][R - (1 << log) + 1]);
}
 
void build(){
    logs2[1] = 0;
    for(int i = 2; i < N; i++)
        logs2[i] = logs2[i / 2] + 1;
 
    for(int i = 0; i < n; i++)
        ST[0][i] = A[i];
    for(int i = 1; (1 << i) <= n; i++){
        for(int j = 0; j + (1 << i) - 1 < n; j++){
            ST[i][j] = f(ST[i - 1][j], ST[i - 1][j + (1 << (i - 1))]);
        }
    }
}
int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> A[i];
    build();
    // for(int i = 0; i < 4; i++){
    //     for(int j = 0; j < n; j++)
    //         cout << ST[i][j] << " ";
    //     cout << endl;
    // }
 
    int q;
    cin >> q;
    while(q--){
        int L, R;
        cin >> L >> R;
        // --L; --R;
        cout << _query(L, R) << '\n';
    }
    return 0;
}
