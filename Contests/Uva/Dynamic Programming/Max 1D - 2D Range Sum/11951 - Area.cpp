#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
int main(){
        
    int t;
    scanf("%d", &t);
    for(int li = 1; li <= t; li++){
        int n, m;
        ll kk;
        scanf("%d %d %lld", &n, &m, &kk);
        vector<vector<ll>> A(n + 2, vector<ll> (m + 2));
        vector<vector<ll>> acc(n + 2, vector<ll> (m + 2));
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                scanf("%d", &A[i][j]);

        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                acc[i][j] = acc[i - 1][j] + acc[i][j - 1] + A[i][j] - acc[i - 1][j - 1];

        // for(int i = 1; i <= n; i++){
        //     for(int j = 1; j <= m; j++)
        //         printf("%d ", acc[i][j]);
        //     printf("\n");
        // }
        ll area = 0, sum = 2e18;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                for(int k = i; k <= n; k++){
                    for(int l = j; l <= m; l++){
                        ll s = acc[k][l] - acc[k][j - 1] - acc[i - 1][l] + acc[i - 1][j - 1];
                        if(s <= kk){
                            ll tmp = (k - i + 1) * (l - j + 1);
                            // cout << tmp <<  " " << s << endl;
                            if(tmp > area){
                                area = tmp;
                                sum = s;
                            }else if(tmp >= area){
                                area = tmp;
                                if(sum > s)
                                    sum = s;
                            }
                        }
                    }
                }
            }
        }
        if(area == 0)
            sum = 0;
        printf("Case #%d: %lld %lld\n", li, area, sum);


    }
    return 0;
}
