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
    if(n == 1)
        cout << 1 << '\n';
    else if(n <= 3)
        cout << "NO SOLUTION\n";
    else{
        for(int i = 2; i <= n; i += 2)
            cout << i << ' ';
        for(int i = 1; i <= n; i += 2)
            cout << i << ' ';
    }
    return 0;
}
