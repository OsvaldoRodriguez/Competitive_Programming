#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 550;
const ll mod = 1e9 + 7;
string dp[10005][105];
string a, b;

string add(string &A, string &B){
    string C, D;
    int len = abs((int)A.size() - (int)B.size());
    string zero(len, '0');
    if(A.size() > B.size()){
        C = A;
        D = zero + B;
    }else{
        C = B;
        D = zero + A;
    }

    string ans(C.size(), '0');

    int carry = 0;
    for(int i = C.size() - 1; i >= 0; i--){
        int num = (C[i] - '0') + (D[i] - '0');
        int value = num + carry;
        int dec = value % 10;
        ans[i] = (dec + '0');
        carry = value / 10;
    }
    if(carry){
        string aux = "";
        aux += (carry + '0');
        ans = aux + ans;
    }
    return ans;

}

string f(int i, int j){
    if(i == a.size()){
        string aux = "0";    
        if(j == b.size())
            return aux = "1";
        return aux;
    }
    string ans = dp[i][j];
    if(ans != "-1")
        return ans;

    ans = "0";
    if(j < b.size())
        if(a[i] == b[j]){
            string cur = f(i + 1, j + 1);
            ans = add(ans, cur);
        }
    string tmp = f(i + 1, j);
    ans = add(ans, tmp);

    return dp[i][j] = ans;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> a >> b;
        // memset(dp, -1, sizeof dp);
        for(int i = 0; i <= a.size(); i++)
            for(int j = 0; j <= b.size(); j++)
                dp[i][j] = "-1";

        cout << f(0, 0) << '\n';
    }

    return 0;

}
