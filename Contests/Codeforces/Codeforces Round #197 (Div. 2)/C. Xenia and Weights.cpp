#include <bits/stdc++.h>

using namespace std;

const int N = 1 * 1e3 + 5;
const long long mod = 1e9 + 7;

string str;
int m;

int dp[N][50][12];
int offset = 25;
int f(int i, int diff, int last){
    // cout << "i: " << i << " diff: " << diff << " last: " << last + 1 << endl;
    if(i == m)
        return 1;

    int &ans = dp[i][diff][last];
    if(ans == -1){
        ans = 0;
        for(int j = 0; j < 10; j++){    
            if(str[j] == '1' and j != last){
                if(i % 2 == 0 and j + 1 + diff > offset)    
                    ans |= f(i + 1, j + 1 + diff, j);
                if(i % 2 == 1 and diff - j - 1 < offset)
                    ans |= f(i + 1, diff - j - 1, j);
            }
        }
    }
    return ans;

}

void r(int i, int diff, int last){
    // cout << "i: " << i << " diff: " << diff << " last: " << last + 1 << endl;
    if(i == m)
        return;

    int ans = dp[i][diff][last];
    
    for(int j = 0; j < 10; j++){    
        if(str[j] == '1' and j != last){
            if(i % 2 == 0 and j + 1 + diff > offset and ans == f(i + 1, j + 1 + diff, j)){
                cout << j + 1 << " ";
                r(i + 1, j + 1 + diff, j);
                break;
                return;
            }    
            if(i % 2 == 1 and diff - j - 1 < offset and ans == f(i + 1, diff - j - 1, j)){
                cout << j + 1 << " ";
                r(i + 1, diff - j - 1, j);
                break;
                return;
            }
        }
    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> str >> m;
    memset(dp, -1, sizeof dp);
    if(f(0, offset, -1)){
        cout << "YES\n";
        r(0, offset, -1);
    }else
        cout << "NO\n";
    return 0;
}
