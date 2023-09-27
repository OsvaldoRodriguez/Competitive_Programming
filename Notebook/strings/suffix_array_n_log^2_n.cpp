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
        sort(a.begin(), a.end());
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
