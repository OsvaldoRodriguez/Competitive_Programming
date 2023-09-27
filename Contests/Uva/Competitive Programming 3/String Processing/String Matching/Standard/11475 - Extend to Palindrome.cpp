#include "bits/stdc++.h"
// #include <ext/pb_ds/assoc_container.hpp> // Common file
// #include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#define fastio      ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll          long long
#define all(_)      (_).begin(), (_).end()
#define sz(_)       int(_.size())
#define pii         pair<int, int>
#define pll         pair<ll, ll>
using namespace std;
// using namespace __gnu_pbds; // ordered_set
const int N = 2e5 + 5;
ll mod = 998244353;
const double eps = 1e-9;
// less<type>  prioridad menor
// greater<type>  prioridad mayor
// add equal<type>  less_equal or greater_equal // multiset
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
int di[] = {1, 0, 0, -1}, dj[] = {0, -1, 1, 0};
// string dir = "DLRU";
//**********************************************************************
// Later or Sooner discipline overcomes talent, come on, I can do it.
// ll A[N], H[N];
vector<int> z_function(string &s){ //O(|S|)
    int n = sz(s);
    vector<int> z(n);
    z[0] = 0;//definition
    for(int i = 1, l = 0, r = 0; i < n; i++){
        if(i <= r)
            z[i] = min(z[i - l], r - i + 1);
        while(i + z[i] < n && s[z[i]] == s[z[i] + i])
            z[i]++;
        if(i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

vector<int> counting_preffix(string &str){
    int n = str.size();
    vector<int> ans(n + 1);
    vector<int> z = z_function(str);

    for(int x : z) ans[0]++, ans[x + 1]--;
    for(int i = 1 ;i <= n; i++) ans[i] += ans[i - 1];
    for(int i = 1; i <= n; i++) ans[i]++;
    return ans;
}

// find all preffix than be palindromes
// the idea es SS = S + S' (S' is reverse of S)
// then if z[i] = k => if SS.size() - i == z[i] then palindrome
// ignore all i < S.size() 
vector<int> palindrome(string &str){
    string str2 = str;
    int n = str.size();
    reverse(all(str2));
    str += str2;
    int n_new = str.size();
    vector<int> z = z_function(str);
    vector<int> ans(n + 1);
    for(int i = n; i < n_new; i++){
        int k = n_new - i; // preffix's length 
        if(k == z[i]){
            ans[z[i]] = 1;
        }
    }
    return ans;
}

void solve(){
    string str;
    while(cin >> str){
        reverse(all(str));
        string copy_str = str;
        // cout << copy_str << endl;
        vector<int> p = palindrome(str);
        // for(int i : p)cout << i << " " ; cout << endl;
        for(int i = p.size() - 1; i >= 0; i--){
            if(p[i]){
                // cout << i << " pos\n";
                string add = copy_str.substr(i, copy_str.size());
                string add2 = add;
                reverse(all(add2));
                // cout << add << " " << add2 << endl;
                string ans = add2 + copy_str.substr(0, i) + add;
                cout << ans << "\n";
                break;
            }
        }
    }
}
int main(){
    fastio;
    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++){
        if(i > 1)
            cout << "\n";
        solve();
    }
    
    return 0;
}   
// solo recorre en los bits encendidos
// O(bits_encendidos en mask)
// for(int x = mask; x; x &= (x - 1)){
//     int v = __builtin_ctz(x); // da la posicion donde esta 
// }
