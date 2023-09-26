#include <bits/stdc++.h>
using namespace std;

struct Trie{
    int t;
    int existe;
    map<char, Trie*> M;
    Trie(){
        t = 0;
        M.clear();
        existe = 0;
    }
};
void init_Trie(){
    Trie* root = new Trie();
}
void add(Trie* root, const string &str){
    Trie* node = root;
    for(int i = 0; i < str.size(); i++){
        if(node->M[str[i]] == NULL){
            node->M[str[i]] = new Trie();
        }
        node = node ->M[str[i]];
    }
    node->t++;
    node->existe = 1;
}

bool contain(Trie* root, const string &str){
    Trie* node = root;
    for(int i = 0; i < str.size(); i++){
        if(node->M[str[i]] == NULL)
            return 0;
        node = node -> M[str[i]];
    }
    return node->existe;
}
void dfs(Trie* root){
    Trie* node = root;
    for(map<char, Trie*> :: iterator it = node->M.begin(); it != node->M.end(); it++){
        cout << it -> first << '\n';
        dfs(it -> second);
    }
}
int main(){
    Trie* root = new Trie();
    string str;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> str;
        add(root, str);
    }
    cin >> str;
    cout << contain(root, str) << '\n';
    dfs(root);
    return 0;
}       
