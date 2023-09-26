//used si ya lo use ese numero
// n tamanio de la permutacion
void P(vector<int> &ans){// permutation
    if(sz(ans) == n){
        // permutacion
        for(int j = 0; j < n; j++)
            cout << ans[j] << ' ';
        cout << "\n";
        return ;
    }
    for(int i = 0; i < n; i++){
        if(used[i] == 0){
            used[i] = 1;
            ans.push_back(v[i]);
            P(ans);
            ans.pop_back();
            used[i] = 0;
        }
    }
}
