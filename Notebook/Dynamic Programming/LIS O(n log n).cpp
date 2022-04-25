#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int &i : v)
        cin >> i;
    vector<int> dp(n, 1);

    /*
    IDEA DE LA SOLUCION
    
    v: n elementos
    dp: tamaño de LIS en la posicion i
    I: aplicando la busqueda binaria nos permite saber en Log n cual es la subsecuencia mas grande hasta la poisicion i

    V:  8    1    9    8    3    4    6    1    5    2
    dp: 1    1    2    2    2    3    4    1    4    2
    I: -inf  1    2    4    5
    id: 0    1    2    3    4    5    6    7    8    9
    */

    vector<int> I(1, -1e9);
    for(int i = 0; i < n; i++){
        // lower_bound -> no-decrecient
        // uper_bound -> crecient
        int pos = lower_bound(I.begin(), I.end(), v[i]) - I.begin();
        if(pos == (int) I.size())
            I.push_back(v[i]);
        else
            I[pos] = v[i];
        // asignar en dp el lis
        dp[i] = pos;
    }


    // for(int i : v)
    //     cout << i << ' ';
    // cout << '\n';
    // for(int i : dp)
    //     cout << i << ' ';
    // cout << '\n';

    // for(int i : I)
    //     cout << i << ' ';
    // cout << '\n';

    // ans tiene el LIS, es -1 xq se agrega antes -inf
    int ans = (int) I.size() - 1;
    cout << ans << "\n";

    int i = n - 1;
    int value = ans;
    stack<int> s;

    // reconstruccion de la solucion (la mas grande)

    // O(n)
    while(i >= 0){
        if(dp[i] == value){
            s.push(v[i]);
            value--;
        }
        i--;
    }

    while(s.size()){
        cout << s.top() << '\n';
        s.pop();
    }
    return 0;
}

// 10
// 8 1 9 8 3 4 6 1 5 2
