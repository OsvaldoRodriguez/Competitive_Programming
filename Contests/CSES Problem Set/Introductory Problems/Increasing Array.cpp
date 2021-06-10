#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int N = 2e5 + 10;

int v[N];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll ans = 0;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> v[i];

    for(int i = 1; i < n; i++){
        if(v[i] < v[i - 1]){
            ans += 1LL * v[i - 1] - v[i];
            v[i] = v[i - 1];
        }
    }
    cout << ans << '\n';
    return 0;
}
