#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 500;
const int ALPHA = 256;
int trie[N][ALPHA];
int cnt[N];
int nodes;
void add(string &s){
    int cur = 0;
    for(char c : s){
        if(trie[cur][c] == 0)
            trie[cur][c] = ++nodes;
        cnt[cur]++;
        cur = trie[cur][c];
    }
}


int f(string &s){
    int cur = 0;
    int ans = 0;
    for(char c : s){
        ans++;
        cur = trie[cur][c];
        if(cnt[cur] == 1)
            break;

    }
    return ans;
}
int main()
{   
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<string> v(n);
        nodes = 0;
        for(int i = 0; i < n; i++){
            cin >> v[i];
            add(v[i]);
        }
        int ans = 0;
        for(string u : v)
            ans += f(u);
        cout << ans << '\n';

        for(int i = 0; i < nodes + 1; i++){
            for(int j = 0; j < ALPHA; j++)
                trie[i][j] = 0;
            cnt[i] = 0;
        }
    }    
    return 0;
}
