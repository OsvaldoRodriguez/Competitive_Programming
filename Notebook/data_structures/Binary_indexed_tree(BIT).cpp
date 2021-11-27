#include <bits/stdc++.h>
using namespace std;
typedef long long   ll;
const int N = 1e5 + 50;
ll A[N], BIT[N];
int n;
/*
n -> len array
Complexity
Space:  
    build   -> O(n)
Time:
    update  ->  O(log (n))
    build   ->  O(n * log (n))
    getSum  ->  O(log (n))
*/
void update(int pos, int val){
    for(int i = pos; i <= n; i += i&(-i))
        BIT[i] += val;
}

void build(){
    for(int i = 1; i <= n; i++)
        update(i, A[i]);
}

ll getSum(int pos){
    ll ans = 0;
    for(int i = pos; i > 0; i -= i&(-i))
        ans += BIT[i];
    return ans;
}
int main(){
    int q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
        cin >> A[i];
    build();
    int op, l, r;
    while(q--){
        cin >> op >> l >> r;
        l++;
        if(op == 1){
            update(l, r - A[l]);
            A[l] = r;   
        }
        else
            cout << getSum(r) - getSum(l - 1) << '\n';
        
    }
    return 0;
}       
