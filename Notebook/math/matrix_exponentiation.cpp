#include <bits/stdc++.h> // java.util.*;
using namespace std;
typedef long long ll;
int const N = 4e3 + 100;

vector<vector<int>> mul_matrix(vector<vector<int>> A, vector<vector<int>> B){
    int R1 = A.size();
    int C1 = A[0].size();
    int R2 = B.size();
    int C2 = B[0].size();

    vector<vector<int>> ans(R1, vector<int> (C2));

    for(int i = 0; i < R1; i++){
        for(int j = 0; j < C2; j++){
            for(int k = 0; k < R2; k++)
                ans[i][j] += A[i][k] * B[k][j];
        }
    }
    return ans;
}

vector<vector<int>> power(vector<vector<int>> A, int b){
    int n = (int) A.size();
    vector<vector<int>> ans(n, vector<int> (n));  
    for(int i = 0; i < n; i++)
        ans[i][i] = 1;

    while(b){
        if(b & 1)
            ans = mul_matrix(ans, A);
        b >>= 1;
        A = mul_matrix(A, A);
    }
    return ans;

}


/*
linear Recurrence
f(n) = c_1 * f(n - 1) + c_2 * f(n - 2) + ... + c_k * f(n - k)

Problem Fibonacci

f(0) = 0
f(1) = 1
f(n) = f(n - 1) + f(n - 2)
c_1 = c_2 = 1


X * |   f(i)  | = |f(i + 1)|
    | f(i + 1)|   |f(i + 2)|


para el caso de fibonacci es 
X = |0 1|
    |1 1|


por ejemplo
|0 1|   |f(6)|   |0 1|   |5|   | 8|   |f(6)|
|1 1| * |f(7)| = |1 1| * |8| = |13| = |f(7)|

Finalmente se puede calcular:


      |f(0)|   |  f(n)  |
X^n * |f(1)| = |f(n + 1)|


Caso General

     |    f(i)    |   | f(i + 1) |
     |  f(i + 1)  |   | f(i + 2) |  
X *  |  f(i + 2)  | = | f(i + 3) | 
     |     ...    |   |    ...   |  
     |f(i + k - 1)|   | f(i + k) |


y la matriz X es

    |c_1 c_2 c_3 ... c_k| 
    | 1   0   0  ...  0 |
X = | 0   1   0  ...  0 |
    | 0   0   1  ...  0 |
    | 0   0   0  ...  0 |
*/
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    vector<vector<int>> X = {{0, 1}, {1, 1}};

    int Z;
    // problema de fibonacci
    while(cin >> Z){

        vector<vector<int>> exp = power(X, Z);

        vector<vector<int>> inicial = {{0}, {1}};
        exp = mul_matrix(exp, inicial);
        for(int i = 0; i < (int) exp.size(); i++){
            for(int j = 0; j < (int) exp[i].size(); j++){
                cout << exp[i][j] << ' ';
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
