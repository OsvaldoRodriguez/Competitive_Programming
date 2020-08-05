#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 520;
int v[N];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> v[i];
    int LOG = 31-__builtin_clz(n);
    int ans = 1;
    int cn = n*2;
    bool flag1 = 0;
    for(int i = 0; i < LOG; i++){
        bool flag = 1;
        int mar = 1;
        cn /= 2;
        for(int j = 1; j <= n; j++){
            if(mar >= cn){
                mar = 1;
                if(flag){
                    ans = cn;
                    i = 100;
                    flag1 =1;
                    break;
                }
                flag = 1;
                //j--;
            }
            else{
                mar++;
                if(v[j] > v[j + 1] && j != n)
                    flag = 0;
            }
        }   
  
    }
    cout  << ans << '\n';
    return 0;
}
