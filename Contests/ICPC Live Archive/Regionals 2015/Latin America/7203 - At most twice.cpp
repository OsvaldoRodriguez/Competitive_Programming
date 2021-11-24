#include <bits/stdc++.h>

using namespace std;

const int N = 20 + 10;
typedef long long ll;
const ll mod = 1e9 + 7;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string str;
    while(cin >> str){
        // cout << str << endl;
        vector<int> dig(10, 0);
        int n = (int) str.size();
        string ans(n, '0');
        int i = 0;
        while(i < n){
            if(dig[str[i] - '0'] <= 1){
                dig[str[i] - '0']++;
                ans[i] = str[i];
                i++;
            }else{
                int j = i;
                ans[i] = str[i];
                dig[ans[j] - '0']++;
                while(j >= 0){
                    if(ans[j] == '0'){
                        dig[0]--;
                        j--;    
                    }else{
                        dig[ans[j] - '0']--;
                        ans[j]--;
                        dig[ans[j] - '0']++;
                        if(dig[ans[j] - '0'] <= 2)
                            break;
                    }
                }
                if(j == -1)
                    j += 2;
                else
                    j++;
                int num = 9;
                while(j < n){
                    if(dig[num] <= 1){
                        ans[j] = num + '0';
                        dig[num]++;
                        j++;
                    }else
                        num--;
                }
                break;
            }
        }
        cout << atoll(ans.data()) << '\n';

    }
    return 0;

}


