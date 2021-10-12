#include <bits/stdc++.h>

using namespace std;

const int N = 1 * 1e3 + 5;
const long long mod = 1e9 + 7;

int f(int x){
    return abs(x);
}

bool cmp (pair<int, int> &A, pair<int, int> &B){
    return f(A.first) + f(A.second) < f(B.first) + f(B.second);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    string dx = "UDLR";
    vector<tuple<int, int, char>> ans;

    vector< pair<int, int> > A(n);
    for(int i = 0; i < n; i++){
        cin >> A[i].first >> A[i].second;
    }

    sort(A.begin(), A.end(), cmp);
    for(int i = 0; i < n; i++){
        int x = A[i].first, y = A[i].second;
        if(x == 0){
            int f = 0;
            int s = 1;
            if(y < 0)
                y *= -1, swap(f, s);

            ans.push_back({1, y, dx[f]});
            ans.push_back({2, 1, '@'});
            ans.push_back({1, y, dx[s]});
            
        }else if(y == 0){
            int f = 3;
            int s = 2;
            if(x < 0)
                x *= -1, swap(f, s);
            ans.push_back({1, x, dx[f]});
            ans.push_back({2, 1, '@'});
            ans.push_back({1, x, dx[s]});

        }else if(x > 0 and y > 0){ // RU
            ans.push_back({1, x, dx[3]});
            ans.push_back({1, y, dx[0]});
            ans.push_back({2, 1, '@'});
            ans.push_back({1, x, dx[2]});
            ans.push_back({1, y, dx[1]});
        }else if(x < 0 and  y > 0){ // LU
            ans.push_back({1, -x, dx[2]});
            ans.push_back({1, y, dx[0]});
            ans.push_back({2, 1, '@'});
            ans.push_back({1, -x, dx[3]});
            ans.push_back({1, y, dx[1]});
        }else if(x < 0 and y < 0){  // LD
            ans.push_back({1, -x, dx[2]});
            ans.push_back({1, -y, dx[1]});
            ans.push_back({2, 1, '@'});
            ans.push_back({1, -x, dx[3]});
            ans.push_back({1, -y, dx[0]});
        }else{ // RD
            ans.push_back({1, x, dx[3]});
            ans.push_back({1, -y, dx[1]});
            ans.push_back({2, 1, '@'});
            ans.push_back({1, x, dx[2]});
            ans.push_back({1, -y, dx[0]});
        }

        ans.push_back({3, 1, '@'});
    }

    cout << (int) ans.size() << '\n';
    for(int i = 0; i < (int) ans.size(); i++){
        int ope, len;
        string dir;
        tie(ope, len, dir) = ans[i];
        cout << ope <<  " ";
        if(ope == 1)
            cout << len << " " << dir;
        cout << '\n';
    }
    return 0;
}
