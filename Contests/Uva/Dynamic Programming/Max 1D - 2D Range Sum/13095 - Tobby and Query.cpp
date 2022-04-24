#include "iostream"
#include "vector"
using namespace std;
int main(){
        
    int n;
    while(scanf("%d", &n) != EOF){
        vector<vector<int>> v(10, vector<int>(n, 0));
        for(int i = 0; i < n; i++){
            int x;
            scanf("%d", &x);
            v[x][i]++;
        }
        for(int i = 0; i < 10; i++)
            for(int j = 1; j < n; j++)
                v[i][j] += v[i][j - 1];

        int q;
        scanf("%d", &q);
        while(q--){
            int l, r;
            scanf("%d %d", &l, &r);
            l--;
            r--;
            int ans = 0;
            for(int i = 0; i < 10; i++){
                int cur = v[i][r] - (l == 0 ? 0 : v[i][l - 1]);
                if(cur > 0)
                    ans++;
            }
            printf("%d\n", ans);
        }
    }    
    return 0;
}
