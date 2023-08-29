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
const int N = 7e3 + 5;
ll mod = 1e9 + 7;
const double eps = 1e-9;
// less<type>  prioridad menor
// greater<type>  prioridad mayor
// add equal<type>  less_equal or greater_equal // multiset
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
int di[] = {1, 0, 0, -1}, dj[] = {0, -1, 1, 0};
// string dir = "DLRU";
//**********************************************************************
// Later or Sooner discipline overcomes talent, come on, I can do it.

vector<vector<ll>> mul_matrix(vector<vector<ll>> A, vector<vector<ll>> B){
    int R1 = A.size();
    int C1 = A[0].size();
    int R2 = B.size();
    int C2 = B[0].size();
    vector<vector<ll>> ans(R1, vector<ll>(C2));

    for(int i = 0; i < R1; i++)
        for(int j = 0; j < C2; j++)
            for(int k = 0; k < R2; k++){
                ans[i][j] += (A[i][k] % mod * B[k][j] % mod) % mod;
                ans[i][j] %= mod;
            }
    return ans;
}

vector<vector<ll>> power(vector<vector<ll>> A, ll b){
    int n = (int) A.size();
    vector<vector<ll>> ans(n, vector<ll> (n));
    for(int i = 0; i < n; i++)
        ans[i][i] = 1LL;

    while(b){
        if(b & 1)
            ans = mul_matrix(ans, A);
        b >>= 1;
        A = mul_matrix(A, A);
    }
    return ans;
}


void solve(){

    ll a, b, n, m;
    cin >> a >> b >> n >> m;

    mod = 1;
    for(int i = 0; i < m; i++){
        mod *= 10;
    }

    vector<vector<ll>> X = {{0, 1}, {1, 1}};
    vector<vector<ll>> exp = power(X, n);
    vector<vector<ll>> init = {{a}, {b}};
    exp = mul_matrix(exp, init);

    cout << exp[0][0] << "\n";

}

int main(){
    fastio;
    int t = 1;
    cin >> t;

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
