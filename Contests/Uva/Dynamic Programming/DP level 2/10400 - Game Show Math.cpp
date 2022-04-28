#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e2 + 50;
const ll mod = 1e9 + 7;
int n, sum;
int A[N];
int go(int a, int b, int ope){
    if(ope == 0)
        return a + b;
    if(ope == 1)
        return a - b;
    if(ope == 2)
        return a * b;
    return 0;
}

char ope(int op){
    if(op == 0)
        return '+';
    else if(op == 1)
        return '-';
    else if(op == 2)
        return '*';
    else if(op == 3)
        return '/';
    return ' ';
}


const int offset = 32000;
int dp[N][2 * offset + 50];
int f(int i, int s){
    // cout << i << " " << s  << endl;
    if(i == n){
        // cout << "base: " << s << endl;
        return (s == sum);
    }
    int &ans = dp[i][s + offset];
    if(ans != -1)
        return ans;
    ans = 0;
    for(int j = 0; j < 4; j++){
        if(j == 3){
            if( A[i] != 0 and s % A[i] == 0)
                ans |= f(i + 1, s / A[i]);
        }else{
            if(go(s, A[i], j) <= offset and go(s, A[i], j) >= -offset)
                ans |= f(i + 1, go(s, A[i], j));
        }
    }

    return ans;
}

void r(int i, int s){
    if(i == n){
        return;
    }
    int &ans = dp[i][s + offset];

    for(int j = 0; j < 4; j++){
        if(j == 3){
            if( A[i] != 0 and s % A[i] == 0 and ans == f(i + 1, s / A[i])){
                cout << ope(j) << A[i];
                r(i + 1, s / A[i]);
                return;
                break;
            }
        }else{
            if(go(s, A[i], j) <= offset and go(s, A[i], j) >= -offset and ans == f(i + 1, go(s, A[i], j))){
                cout << ope(j) << A[i];
                r(i + 1, go(s, A[i], j));
                return;
                break;
            }
        }
    }
}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> A[i];
        cin >> sum;
        memset(dp, -1, sizeof dp);
        int ans = f(1, A[0]);
        if(ans){
            cout << A[0];
            r(1, A[0]);
            cout << '=' << sum << "\n";
        }else
            cout << "NO EXPRESSION\n";
    }

    return 0;
}
