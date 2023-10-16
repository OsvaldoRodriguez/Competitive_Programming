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

struct SuffixArray{
    string str;
    int n; // length of string
    vector<int> cnt; // for counting sort
    vector<int> p; // for the answer
    vector<int> c; // for the classes
    vector<int> LCP;
    vector<int> type;
    void suffix_array(){
        cnt.clear();
        p.clear();
        c.clear();
        str = "";
        n = 0;
    }

    // use de array p and c  // O(n)
    void count_sort(){
        // sorts array P the keys stored in array C
        cnt.assign(n, 0);
        for(auto i : c)
            cnt[i]++; // sorting by second element of pair
        vector<int> p_new(n);
        vector<int> pos(n); // for each position of element after separate in  buckets
        pos[0] = 0;
        for(int i = 1; i < n; i++)
            pos[i] = pos[i - 1] + cnt[i - 1];
        // is filling to each bucket all element by second element of pair
        for(auto x : p){
            int i = c[x];
            p_new[pos[i]] = x;
            pos[i]++;
        }
        p = p_new;
    }
    // O(n log n)
    vector<int> build(string &s){
        str = s;
        str += '$';
        // cout << str << " origin\n";
        n = str.size();
        p.assign(n, 0); // for the answer
        c.assign(n, 0); // for the classes
        type.assign(n, 0);
        // assign type class
        int q = 0;
        while(q < n and str[q] != '%')
            type[q++] = 1;
        q++;
        while(q < n and str[q] != '$')
            type[q++] = 2;


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
            // so we first shift all positions 2^k to the left
            for(int i = 0; i < n; i++)
                p[i] = (p[i] - (1 << k) + n) % n; // add string to the left with 2^k length
            // because it will do what second half of pair is sorted 
            // then we only need sorted by first element
            count_sort();
            vector<int> c_new(n);
            c_new[p[0]] = 0;
            // calculate equivalent classes
            for(int i = 1; i < n; i++){
                pair<int, int> prev = {c[p[i - 1]], c[(p[i - 1] + (1 << k)) % n]};
                pair<int, int> now = {c[p[i]], c[(p[i] + (1 << k)) % n]};
                if(now == prev)
                    c_new[p[i]] = c_new[p[i - 1]];
                else
                    c_new[p[i]] = c_new[p[i - 1]] + 1;
            }
            c = c_new;
            k++;
        }

        return p;
    }
    // must call to build function
    // use que suffix array lcp[i] = lcp(s[p[i]..], s[p[i - 1]...])
    // O(n)
    vector<int> lcp(){
        LCP.assign(n, 0);
        int k = 0;
        for(int i = 0; i < n - 1; i++){
            int pi = c[i]; // cur
            int j = p[pi - 1]; // prev
            // lcp[i] = lcp(s[i...], s[j...])
            while(str[i + k] == str[j + k]) k++;
            LCP[pi] = k;
            k = max(k - 1, 0);
        }
        return LCP;
    }

    void mostrar(){
        for(int i = 0; i < n; i++){
            cout << setw(2) << p[i] << " " << type[p[i]] << " " << LCP[i] << ' ' << str.substr(p[i], n - p[i]) << "\n";
        }
    }
};

void solve(){
    string s, t;
    cin >> s >> t;
    s = s + '%' + t;
    SuffixArray SA = SuffixArray();
    SA.build(s);
    SA.lcp();
    // SA.mostrar();
    int ans = 0;
    string data = "";
    for(int i = 3; i < SA.n; i++){
        if(SA.type[SA.p[i]] != SA.type[SA.p[i - 1]]){
            // cout << SA.LCP[i] << endl;
            if(SA.LCP[i] > ans){
                ans = SA.LCP[i];
                data = s.substr(SA.p[i], SA.LCP[i]);
            }
        }
    }
    cout << data << "\n";
}
int main(){
    fastio;
    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++){
        solve();
    }
    
    return 0;
}   
// solo recorre en los bits encendidos
// O(bits_encendidos en mask)
// for(int x = mask; x; x &= (x - 1)){
//     int v = __builtin_ctz(x); // da la posicion donde esta 
// }    
