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
