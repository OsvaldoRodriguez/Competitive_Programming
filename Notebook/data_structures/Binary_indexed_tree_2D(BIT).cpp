#include <bits/stdc++.h>
using namespace std;
typedef long long   ll;
const int N = 1e3 + 50;
ll A[N][N], BIT[N][N];
int n, m; 
/*
Complexity
Space:
    build   ->  O(n * m)
Time:
    update  ->  O(log (n) * log(m))
    build   ->  O(n * m * log (n) * log (m))
    sum     ->  O(log (n) * log(m))
*/
void update(int pos_i, int pos_j, int val){ 
    for(int i = pos_i; i <= n; i += i&(-i))
        for(int j = pos_j; j <= m; j += j&(-j))
            BIT[i][j] += val;
}

void build(){ 
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            update(i, j, A[i][j]);
}

int sum(int pos_i, int pos_j){ 
    int sum = 0;
    for(int i = pos_i; i > 0; i -= i&(-i))
        for(int j = pos_j; j > 0; j -= j&(-j))
            sum += BIT[i][j];
    return sum;
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> A[i][j];

    build();
    int a, b, c, d, op;
    int q;//query
    cin >> q;
    while(q--){ //  x1   y1   x2   y2
        cin >> op >> a >> b >> c >> d;
        if(op == 1)
            cout << sum(c, d) - (c, b - 1) - sum(a - 1, d) + sum(a - 1, b - 1) << '\n';
        else{
            update(a, b, c - A[a][b]);
            A[a][b] = c;
        }
    }
    return 0;
}       
