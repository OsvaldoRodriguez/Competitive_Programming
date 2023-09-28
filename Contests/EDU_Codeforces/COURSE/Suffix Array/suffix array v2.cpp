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

// works in O(n)
void radix_sort(vector<pair<pair<int, int>, int>> &a){
    int  n = a.size();
    {
        vector<int> cnt(n);
        for(auto i : a)
            cnt[i.first.second]++; // sorting by second element of pair

        vector<pair<pair<int, int>, int>> a_new(n);
        vector<int> pos(n); // for each position of element after separate in  buckets

        pos[0] = 0;
        for(int i = 1; i < n; i++)
            pos[i] = pos[i - 1] + cnt[i - 1];

        // is filling to each bucket all element by second element of pair
        for(auto x : a){
            int i = x.first.second;
            a_new[pos[i]] = x;
            pos[i]++;
        }
        a = a_new;
    }

    // for first element of pair
    {
        vector<int> cnt(n);
        for(auto i : a)
            cnt[i.first.first]++; // sorting by second element of pair

        vector<pair<pair<int, int>, int>> a_new(n);
        vector<int> pos(n); // for each position of element after separate in  buckets

        pos[0] = 0;
        for(int i = 1; i < n; i++)
            pos[i] = pos[i - 1] + cnt[i - 1];

        // is filling to each bucket all element by second element of pair
        for(auto x : a){
            int i = x.first.first;
            a_new[pos[i]] = x;
            pos[i]++;
        }
        a = a_new;
    }


}


// works in (n log n)
vector<int> suffix_array(string &str){
    // c -> save the class of string of the length 2^k 
    // for compare string with integers in O(1)
    // p -> suffix_array with string s[i, i + 2^k - 1] they are sorted
    str += '$';
    int n = str.size();
    vector<int> p(n), c(n);
    // base case
    vector<pair<char, int>> a(n);
    for(int i = 0; i < n; i++) // for sort string with length 1
        a[i] = {str[i], i}; 
    sort(a.begin(), a.end());
    // build array p with indexes
    for(int i = 0; i < n; i++)
        p[i] = a[i].second;
    // assign class to array 
    c[p[0]] = 0;
    for(int i = 1; i < n; i++){
        if(a[i].first == a[i - 1].first)
            c[p[i]] = c[p[i - 1]];
        else
            c[p[i]] = c[p[i - 1]] + 1;
    }

    // we need iterate over all k while (1 << k) < n
    int k = 0;
    while((1 << k) < n){
        // ((a1, a2), index)
        // when the string is 2^(k + 1)
        // then a1 = 2^k and a2 = 2^k and index is index in s
        // index's a1 is i and index's a2 is i + (1 << k)
        vector<pair<pair<int, int>, int>> a(n);
        for(int i = 0; i < n; i++){
            a[i] = {{c[i], c[(i + (1 << k)) % n]}, i};
        }
        // O(N)
        radix_sort(a);
        for(int i = 0; i < n; i++)
            p[i] = a[i].second;
        c[p[0]] = 0;
        for(int i = 1; i < n; i++){
            if(a[i].first == a[i - 1].first) // it's compare pair data {a1, b1}
                c[p[i]] = c[p[i - 1]];
            else
                c[p[i]] = c[p[i - 1]] + 1;
        }
        k++;
    }
    return p;
}

void solve(){
    string s;
    cin >> s;
    vector<int> p = suffix_array(s);
    for(int i : p) cout << i << " ";
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
