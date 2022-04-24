#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
int main(){
    int n;
    while(scanf("%d", &n) != EOF and n){
        vector<int> v(n);
        for(int &i : v)
            cin >> i;

        int s = 0, p = 0;
        for(int i = 0; i < n; i++){
            s = max(v[i], s + v[i]);
            p = max(p, s);
        }
        if(p)
            printf("The maximum winning streak is %d.\n", p);
        else
            printf("Losing streak.\n");
    }
    return 0;
}
