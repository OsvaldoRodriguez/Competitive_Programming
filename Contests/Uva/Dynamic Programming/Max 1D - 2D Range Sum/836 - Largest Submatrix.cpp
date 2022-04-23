#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int N = 2e2 + 10;
const ll mod = 1e9 + 7;
int A[N][N];
int acc[N][N];
void solve(){
    int n;
    int t;
    cin >> t;
    // cout << t << endl;
    string str;
    // cin.ignore();
    // cin.ignore();
    cin.ignore();
    cin.ignore();
    bool flag = false;
    while(t--){
        vector<string> s;
        while(getline(cin, str)){
            if(str == "")
                break;
            s.push_back(str);
        }

        int n = s.size();

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++)
                A[i][j] = s[i - 1][j - 1] - '0';
                // cout << s[i - 1][j - 1];
            // cout << endl;
        }
        
        // for(int i = 1; i <= n; i++){
        //     for(int j = 1; j <= n; j++)
        //         cout << A[i][j] << " ";
        //     cout << endl;
        // }


        // for(int i = 1; i <= n; i++)
        //     for(int j = 1; j <= n; j++)
        //         cin >> A[i][j];

        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                acc[i][j] = acc[i - 1][j] + acc[i][j - 1] - acc[i - 1][j - 1] + A[i][j];

        int ans = 0;
        pair<int, pair<int, pair<int, int >>> tmp = {-1, {-1, {-1, -1}}};
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                for(int k = i; k <= n; k++){
                    for(int l = j; l <= n; l++){
                        int cur = acc[k][l] - acc[k][j - 1] - acc[i - 1][l] + acc[i - 1][j - 1];
                        if(ans < cur and (k - i + 1) * (l - j + 1) == cur){
                            ans = cur;
                            tmp = {i, {j, {k, l}}};
                        }
                    }
                }
            }
        }
        if(flag){
            cout << "\n";
        }
        flag = true;
        cout << ans << '\n';
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
