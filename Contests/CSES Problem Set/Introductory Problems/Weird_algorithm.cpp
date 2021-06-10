#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n;
    scanf("%lld", &n);
    while(true){
        printf("%lld ", n);
        if(n == 1)
            break;
        if(n & 1){
            n = 3LL * n;
            n++;
        }
        else
            n >>= 1;

    }
}
