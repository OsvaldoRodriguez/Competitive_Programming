#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e2 + 100;
const ll mod = 1e9 + 7;


void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int &i : v)
        cin >> i;
    vector<int> dp(n, 1);
    vector<int> I(1, -1e9);

    for(int i = 0; i < n; i++){
        int pos = lower_bound(I.begin(), I.end(), v[i]) - I.begin();
        if(pos == I.size()){
            I.push_back(v[i]);
        }else{
            I[pos] = v[i];
        }
        dp[i] = pos;
    }

    cout << *max_element(dp.begin(), dp.end()) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++)
        solve();
    return 0;
}
