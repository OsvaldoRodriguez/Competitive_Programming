// test in cf 

/*
S = winlose???winl???w??
T = win
you have two string S and T. You should get the maximum number occurrences of T in S replacing the character ? with anyone letter
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50;
const int ALPHA = 256;
vector<vector<int>> dp;
vector<int> phi;
int aut[N][ALPHA]; // si estoy en estado i y veo letra j a donde voy
vector<int> prefix_function(string &p){
    int n = p.size();
    vector<int> phi(n);
    for(int i = 1, j = 0; i < n; i++){
        while(j > 0 and p[j] != p[i])
            j = phi[j - 1];
        if(p[j] == p[i])
            j++;
        phi[i] = j;
    }
    return phi;
}

void kmp_automaton(string &patron){
    phi = prefix_function(patron);
    int  n = patron.size();

    // i = 1 -> aut[0][patron[0]] = 1;
    for(int i = 0; i <= n; i++){ // tiene un estado mas que el tamaño de la cadena -> automata
        for(int j = 0; j < ALPHA; j++){
            if(i < n and j == patron[i])
                aut[i][j] = i + 1;
            else{
                if(i)
                    aut[i][j] = aut[phi[i - 1]][j];
            }
        }
    }
}
string text, pt;
int f(int i, int j){
    if(i == text.size())
        return 0;
    int &ans = dp[i][j];
    if(ans == -1){
        ans = 0;
        for(char k = 'a'; k <= 'z'; k++){
            char cur = text[i] == '?' ? k : text[i];
            ans = max(ans, f(i + 1, aut[j][cur]) + (aut[j][cur] == pt.size()));
        }
    }
    return ans;
}
int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> text >> pt;
    kmp_automaton(pt);
    dp.assign(text.size() + 5, vector<int> (pt.size() + 5, -1));
    cout << f(0, 0) << '\n';
    return 0;
}
