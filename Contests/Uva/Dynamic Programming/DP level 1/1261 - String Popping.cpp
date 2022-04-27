#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e4 + 550;
const ll mod = 1e9 + 7;
unordered_map<string, int> m;
int g(string &A){
    if(A == ""){
        return 1;
    }

    if(m.count(A) != 0)
        return m[A];
    
    int &ans = m[A];

    for(int k = 0; k < A.size(); k++){
        int l = k;
        while(l < A.size() and A[l] == A[k])
            l++;        
        l--;
        if(l - k + 1 >= 2){
            string aux = "";

            for(int i = 0; i < k; i++)
                aux += A[i];
            for(int i = l + 1; i < A.size(); i++)
                aux += A[i];
            
            ans |= g(aux);
        }

    }

    return ans;
}



int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    string str;
    while(t--){
        cin >> str;
        int ans = g(str);
        cout << ans << '\n';
        
    }
    return 0;

}
