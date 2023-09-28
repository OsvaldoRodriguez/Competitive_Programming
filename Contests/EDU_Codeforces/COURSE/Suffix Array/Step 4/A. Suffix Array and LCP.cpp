#include "bits/stdc++.h"
using namespace std;
/*
Explain
s = ababba$
    0123456

then with k = 1

    $a  6   0
    a$  5   1
    ab  0   2
    ab  2   2
    ba  1   3
    ba  4   3
    bb  3   4

        ^
        |
        p

for this case we can add a string (length 2) of the left


    k = 1                 -> new_pos k = 2
    ba$a  6   0                 4   (3, 0)
    bba$  5   1                 3   (4, 1)
    a$ab  0   2                 5   (1, 2)
    abab  2   2                 0   (2, 2)
    $aba  1   3                 6   (0, 3)
    abba  4   3                 2   (2, 3)    
    babb  3   4                 1   (3, 4)    
                                ^
        ^                       |
        |                 
        p
where new_pos is when we add other string with lenght 2 to the left
then que second half of pair is sorted by second element
then we need to do only one couting sort.
*/

// works in O(n)

struct SuffixArray{
    string str;
    int n; // length of string
    vector<int> cnt; // for counting sort
    vector<int> p; // for the answer
    vector<int> c; // for the classes
    vector<int> LCP;
    void suffix_array(){
        cnt.clear();
        p.clear();
        c.clear();
        str = "";
        n = 0;
    }

    // use de array p and c
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

    vector<int> build(string &s){
        str = s;
        str += '$';
        n = str.size();
        p.assign(n, 0); // for the answer
        c.assign(n, 0); // for the classes
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
            cout << p[i] << " " << LCP[i] << ' ' << str.substr(p[i], n - p[i]) << "\n";
        }
    }
};


void solve(){
    string s;
    cin >> s;
    SuffixArray arr;
    vector<int> p = arr.build(s);
    vector<int> lcp = arr.lcp();
    for(int i = 0; i < p.size(); i++)
        cout << p[i] << " ";
    cout << "\n";
    for(int i = 1; i < lcp.size(); i++)
        cout << lcp[i] << " ";
    cout << "\n";
}
int main(){
    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++){
        if(i > 1)
            cout << "\n";
        solve();
    }
    
    return 0;
}   
