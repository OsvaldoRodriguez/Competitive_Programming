#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int N = 1e3 + 10;
const ll mod = 1e9 + 7;
int A[N][N];
int acc[N][N];
void solve(){
    int n, m;
    bool flag = false;
    while(cin >> n >> m){
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                cin >> A[i][j];



        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                acc[i][j] = acc[i - 1][j] + acc[i][j - 1] - acc[i - 1][j - 1] + A[i][j];

        vector<ll> ans;
        for(int i = 1; i <= n - m + 1; i++)
            for(int j = 1; j <= n - m + 1; j++){
                // cout << i << " " << j << "  " << i + m - 1 << " " << j + m - 1 << '\n';
                int cur = acc[i + m - 1][j + m - 1] - acc[i + m - 1][j - 1] - acc[i - 1][j + m - 1] + acc[i - 1][j - 1];
                ans.push_back(1LL * cur);
            }

        if(flag)
            cout << "\n";
        flag = true;
        for(ll i : ans)
            cout << i << '\n';

        cout << accumulate(ans.begin(), ans.end(), 0LL) << '\n';

    }
}
 
int main(){
        
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++){
        solve();
    }
    return 0;
}
