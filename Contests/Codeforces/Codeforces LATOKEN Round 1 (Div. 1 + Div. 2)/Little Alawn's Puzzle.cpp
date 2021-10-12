#include <bits/stdc++.h>

using namespace std;

const int N = 4 * 1e5 + 5;
const long long mod = 1e9 + 7;
int P[N], rnk[N];

int _find(int u){
    if(u == P[u])return u;
    return P[u] = _find(P[u]);
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> A(n), B(n), idx(n + 1), used(n, false);
        for(int &i : A) cin >> i;
        for(int i = 0; i < n; i++){
            cin >> B[i];
            idx[B[i]] = i;
        }
        for(int i = 0; i <= n; i++)
            P[i] = i, rnk[i] = 1;
        int conj = n;
        for(int i = 0; i < n; i++){
            if(used[i])continue;
            int last = -1;
            int cur = i;
            while(i != last){
                int tmp = idx[A[cur]];
                int u = _find(B[cur]);
                int v = _find(B[tmp]);
                if(v != u){
                    if(rnk[u] < rnk[v]){
                        P[u] = v;
                    }else{ // u >= v
                        P[v] = u;
                        if(rnk[v] == rnk[u])
                            rnk[u]++;
                    }
                    conj--;
                }
                used[cur] = true;
                last = cur;
                cur = tmp;

            }
        }

        auto f = [] (long long a, long long b, long long m){
            long long ans = 1;
            while(b){
                if(b & 1)
                    ans = (ans % m * a % m) % m;
                b >>= 1;
                a = (a % m * a % m) % m;
            }
            return ans;
        };

        cout << f(2LL, conj, mod) << '\n';




    }
    return 0;
}
