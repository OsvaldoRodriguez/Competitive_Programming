#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int &i : v)
        cin >> i;
    vector<int> dp(n, 1);

    // O(n ^ 2) LIS
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(v[j] < v[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    // ans tiene el LIS
    int ans = *max_element(dp.begin(), dp.end());
    cout << ans << "\n-\n";

    int i = n - 1;
    int value = ans;
    stack<int> s;

    // reconstruccion de la solucion (la mas grande)

    // O(n)
    while(i >= 0){
        if(dp[i] == value){
            s.push(v[i]);
            value--;
        }
        i--;
    }

    while(s.size()){
        cout << s.top() << '\n';
        s.pop();
    }
    return 0;
}

// 10
// 8 1 9 8 3 4 6 1 5 2
