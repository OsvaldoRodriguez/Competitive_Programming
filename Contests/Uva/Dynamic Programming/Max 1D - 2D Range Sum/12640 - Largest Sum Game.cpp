#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    string str;
    while(getline(cin, str)){
        vector<int> v;
        for(int i = 0; i < str.size(); i++){
            string aux = "";
            while(i < str.size() and str[i] != ' ')
                aux += str[i++];

            v.push_back(atoi(aux.data()));
        }

        int s = 0, p = 0;
        for(int i = 0; i < v.size(); i++){
            s = max(v[i], s + v[i]);
            p = max(p, s);
        }
        cout << p << '\n';
    }
    return 0;
}
