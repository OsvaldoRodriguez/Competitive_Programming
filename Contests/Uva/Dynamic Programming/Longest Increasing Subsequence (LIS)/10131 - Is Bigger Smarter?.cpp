#include <bits/stdc++.h>
using namespace std;

void solve(){
    int w, s;
    vector<pair<int, pair<int, int>>> A;
    int idx = 1;
    while(cin >> w >> s){
        A.push_back({s, {w, idx++}});
    }
    sort(A.rbegin(), A.rend());
    int n = A.size();
    vector<int> dp(n, 1);
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(A[j].second.first < A[i].second.first and A[j].first > A[i].first){
                dp[i] = max(dp[i], dp[j] + 1);

            }
        }
    }

    int ans = *max_element(dp.begin(), dp.end());
    cout << ans << '\n';
    stack<int> st;
    idx = n - 1;
    while(idx >= 0){
        if(dp[idx] == ans){
            ans--;
            st.push(A[idx].second.second);
        }
        idx--;
    }

    while(st.size()){
        cout << st.top() << '\n';
        
        st.pop();
    }

    // for(auto i : A)
    //     cout << i.second.first << " " << i.first << " " << i.second.second << endl;
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
