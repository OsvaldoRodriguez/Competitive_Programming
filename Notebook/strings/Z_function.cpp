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
/*
para hacer string matching 
s = t + "#" + p;
t = texto
p = patron
"#" = no pertenece al alfabeto
*/

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
