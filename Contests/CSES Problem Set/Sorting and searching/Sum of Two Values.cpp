#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const int N = 2e5 + 50;
const ll mod = 1e9 + 7;
pair<int, int> A[N];
void solve(){   
    int n, x;
    cin >> n >> x;

    for(int i = 0; i < n; i++){
        cin >> A[i].first;
        A[i].second = i;
    }
    sort(A, A + n);
    int i = 0, j = n - 1;
    while(i < j){
        if(A[i].first + A[j].first == x){
            cout << A[i].second + 1 << " " << A[j].second + 1 << '\n';
            return;
        }
        if(A[i].first + A[j].first > x)
            j--;
        else
            i++;
    }

    cout << "IMPOSSIBLE\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++)
        solve();
    return 0;
}
