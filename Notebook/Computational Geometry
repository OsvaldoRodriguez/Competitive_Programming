#include <bits/stdc++.h>
using namespace std;
typedef long double T;
struct punto{
    T x, y;
    //punto(){x = y = 0.0;}
    punto():x(0), y(0){};
    punto(T _x, T _y){x = _x;y = _y;}
    punto operator + (punto &A){return punto(x + A.x, y + A.y);}//suma de vectores this + A
    punto operator - (punto &A){return punto(x - A.x, y - A.y);}//resta de vectores this - A
    punto operator * (T k){return punto(x * k, y * k);}// vector por escalar this * k
    T operator * (punto &A){return x * A.x + y * A.y;}// producto escalar
    T operator ^ (punto &A){return x * A.y - y * A.x;}//producto cruz, devuelve un vector ortogonal(90) a A y B , area del paralalogramo que forman los dos vectores
    T modulo(){return hypotl(x, y);}// modulo del vector
    punto unit(){return  punto(x, y) * (1.0 / modulo());}//vector unitario = vector / modulo(vector)/ -> vector por escalar
};


//punto de la proyeccionde B sobre A
    // proyecion de B en A -> vec A * vec B / mod(A)
    // T proyB_A = (A * B) / A.modulo();
    // cout << proyB_A << '\n';
    // cout << (A.unit() * proyB_A) << '\n';
//sobrecarga de operador
//& es para que mantenga el mismo cout
ostream &operator << (ostream &COUT, punto A){
    cout << "(" << A.x << "," << A.y << ")";
    return COUT;
}
istream &operator >> (istream &CIN, punto &A){
    CIN >> A.x >> A.y;
    return CIN;
}
void solve(){
    punto A(4, 1);
    punto B(2, 3);
    punto C(6, 3);
    // cout << A << " " << B << '\n';
    // cout << A + B << '\n';
    // cout << A - B << '\n';
    // cout << A * 3 << '\n';
    // cout << A * B << '\n';
    // cout << (A ^ B) << '\n';
    // cout << (C).modulo() << '\n';
    // cout << C.unit() << '\n';

    
    // lectura con sobrecarga de operador
    punto Z;
    cout << Z << '\n';
    cin >> Z;
    cout << Z << '\n';


}
int main(){
    solve();    
    return 0;
}
