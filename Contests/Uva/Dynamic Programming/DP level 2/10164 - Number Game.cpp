#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e3 + 50;
const ll mod = 1e9 + 7;
int A[2 * N];
int sol[2 * N];
int n, cp;
int f(int i, int sum, int len){
    if(len == cp)
        return sum % cp == 0;
    if(i < n){
        sol[len] = A[i];
        if(f(i + 1, (sum + A[i]) % cp, len + 1))
            return true;
        if(f(i + 1, sum, len))
            return true;
    }
    
    return false;
}


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(cin >> n and n){
        cp = n;
        n = 2 * n - 1;
        for(int i = 0; i < n; i++)
            cin >> A[i];

        int ans = f(0, 0, 0);
        if(ans){
            cout << "Yes\n";
            for(int i = 0; i < cp; i++){
                cout << sol[i];
                if(i + 1 < cp)
                    cout << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}
