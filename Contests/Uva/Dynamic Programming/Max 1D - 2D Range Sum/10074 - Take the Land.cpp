#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    while(cin >> n >> m and (n or m)){
        vector<vector<int>> A(n + 2, vector<int>(m + 2));
        vector<vector<int>> acc(n + 2, vector<int>(m + 2));
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++){
                cin >> A[i][j];
                A[i][j] = 1 - A[i][j];
                acc[i][j] = acc[i - 1][j] + acc[i][j - 1] + A[i][j] - acc[i - 1][j - 1];
            }

        int ans = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                for(int k = i; k <= n; k++){
                    for(int l = j; l <= m; l++){
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
