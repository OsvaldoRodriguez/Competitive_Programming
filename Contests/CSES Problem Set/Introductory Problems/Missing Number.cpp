#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 10;
bitset<N> A;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        int x;
        cin >> x;
        x--;
        A.set(x);
    }

    for(int i = 0; i < n; i++){
        if(A[i] == 0){
            cout << i + 1 << '\n';
            break;
        }
    }

    return 0;
}
