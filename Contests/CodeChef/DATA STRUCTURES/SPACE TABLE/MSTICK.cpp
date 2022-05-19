#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int LOG = 20;
int A[N], ST1[LOG + 1][N], ST2[LOG + 1][N];
int n;

int f(int a, int b){
    return min(a, b);
}
int g(int a, int b){
    return max(a, b);
}
void build(){
    for(int i = 0; i < n; i++){
        ST1[0][i] = A[i];
        ST2[0][i] = A[i];
    }

    for(int i = 1; (1 << i) <= n; i++){
        for(int j = 0; j + (1 << i) - 1 < n; j++){
            ST1[i][j] = f(ST1[i - 1][j], ST1[i - 1][j + (1 << (i - 1))]);
            ST2[i][j] = g(ST2[i - 1][j], ST2[i - 1][j + (1 << (i - 1))]);
        }
    }
}

int query1(int L, int R){
    if(R < L)
        return 1e9;
    int len = R - L + 1;
    int log = 32 - 1 - __builtin_clz(len);
    return f(ST1[log][L], ST1[log][R - (1 << log) + 1]);
}

int query2(int L, int R){
    if(R < L)
        return 0;
    int len = R - L + 1;
    int log = 32 - 1 - __builtin_clz(len);
    return g(ST2[log][L], ST2[log][R - (1 << log) + 1]);
}

int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> A[i];
    build();
    cin >> q;
    
    int ans = 0;
    while(q--){
        int L, R;
        cin >> L >> R;

        int mx = g(query2(0, L - 1), query2(R + 1, n - 1));
        int mn = query1(L, R);
        double ans = mn + mx;
        int mx2 = query2(L, R);
        ans = max(ans, (double)(mx2 - mn) / 2.0 + (double) mn);

        cout << fixed << setprecision(1) << ans << '\n';
    }
    return 0;
}

