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
        vector<vector<int>> A(2 * n + 2, vector<int>(2 * n + 2, 0));
        vector<vector<int>> acc(2 * n + 2, vector<int>(2 * n + 2, 0));
        


        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++){
                cin >> A[i][j];
                A[i + n][j] = A[i][j + n] = A[i + n][j + n] = A[i][j];
            }


        for(int i = 1; i < A.size(); i++){
            for(int j = 1; j < A.size(); j++)
                acc[i][j] = acc[i - 1][j] + acc[i][j - 1] + A[i][j] - acc[i - 1][j - 1];
                
        }


        int ans = 0;
        for(int i = 1; i < A.size(); i++){
            for(int j = 1; j < A.size(); j++){
                for(int k = i; k < A.size(); k++){
                    for(int l = j; l < A.size(); l++){
                        int cur = acc[k][l] - acc[k][j - 1] - acc[i - 1][l] + acc[i - 1][j - 1];
                        if((l - j + 1) <= n and  (k - i + 1) <= n)
                            ans = max(ans, cur);
                    }
                }
            }
        }
        cout << ans << '\n';

    }
    

    return 0;
}
