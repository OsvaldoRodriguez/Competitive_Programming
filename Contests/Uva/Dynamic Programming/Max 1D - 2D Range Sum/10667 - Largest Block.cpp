#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>> A(n + 2, vector<int>(n + 2, 1));
        vector<vector<int>> acc(n + 2, vector<int>(n + 2, 0));
        int q;
        cin >> q;
        while(q--){
            int r1, c1, r2, c2;
            cin >> r1 >> c1 >> r2 >> c2;
            for(int i = r1; i <= r2; i++)
                for(int j = c1; j <= c2; j++)
                    A[i][j] = 0;
        }


        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++){
                acc[i][j] = acc[i - 1][j] + acc[i][j - 1] + A[i][j] - acc[i - 1][j - 1];
            }

        
        int ans = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                for(int k = i; k <= n; k++){
                    for(int l = j; l <= n; l++){
                        int cur = acc[k][l] - acc[k][j - 1] - acc[i - 1][l] + acc[i - 1][j - 1];
                        if(cur == (l - j + 1) * (k - i + 1))
                            ans = max(ans, cur);
                    }
                }
            }
        }
        cout << ans << '\n';

    }
    

    return 0;
}
