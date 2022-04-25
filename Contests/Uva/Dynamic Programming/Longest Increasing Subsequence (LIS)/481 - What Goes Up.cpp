#include <bits/stdc++.h>
using namespace std;

void solve(){
    int x;
    vector<int> v;
    while(cin >> x)
        v.push_back(x);

    int n = (int) v.size();
    vector<int> I(1, -1e9), dp(n, 1);
    for(int i = 0; i < n; i++){
        int pos = lower_bound(I.begin(), I.end(), v[i]) - I.begin();
        if(pos == (int) I.size())
            I.push_back(v[i]);
        else
            I[pos] = v[i];

        dp[i] = pos;
    }

    
    int ans = I.size() - 1;
    cout << ans << '\n';

    stack<int> s;
    int idx = n - 1;
    while(idx >= 0){
        if(dp[idx] == ans){
            ans--;
            s.push(v[idx]);
        }
        idx--;
    }

    cout << "-\n";
    while(s.size()){
        cout << s.top() << '\n';
        s.pop();
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++)
        solve();
}

// 10
// 8 1 9 8 3 4 6 1 5 2
