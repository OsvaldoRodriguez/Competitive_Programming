#include <bits/stdc++.h>
using namespace std;
typedef long long   ll;
const int N = 1e3 + 50;
int G[N][N], dis[N][N];

/*
n vertex
m edges
Complexity
Time:
    floyd -> O(n ^ 3) matrix adjadency matrix
*/

void floyd_warshall(int n){
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
}
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> G[i][j];
            if(G[i][j] == 0)
                dis[i][j] = (1 << 30); // infinity
            else
                dis[i][j] = G[i][j];
        }
    }
    floyd_warshall(n);
    return 0;
}       
