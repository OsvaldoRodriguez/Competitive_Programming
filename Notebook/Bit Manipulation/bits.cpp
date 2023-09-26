#include<bits/stdc++.h>
using namespace std;
//apaga el i-esimo bit de un numero
int off(int x, int i){
    return x & ( ~ (1 << i));
}
//enciende el i-esimo bit de un numero
int on(int x, int i){
    return x | (1 << i);
}
//cambia el i-esimo bit de un numero
int toggle(int x, int i){
    return x ^ (1 << i);
}
//LeastSignificanOneBit consigue el valor del bit menos significativo del numero
int LsoneBit(int x, int i){
    return x & ( - x);
}
// y MostSignificantOneBit consigue el valor del  bit mas significativo del numero
int MsoneBit(int x, int i){
    int ans = x & ~ ( - x);
    if(ans == 0)
        return x;
    return ans;
}
bool isPowerOfTwo(int x){
  if(x & (x - 1)) // si la condicion es igual a 0 entonces es potencia de 2
    return 0;
  return 1;
  ///forma acortada return x && !(x&(x-1))
}


int count_one(int n){
    int count = 0;
    while(n){
        n = n & (n - 1);
        count++;
    }
    return count;
}
int main(){
    int n = 10, i = 3;
    cout << "off: " << off(n, i) << "\n";
    cout << "on: " << on(n, i) << "\n";
    cout << "toggle: " << toggle(n, i) << "\n";
    cout << "least significat one bit: " << LsoneBit(n, i) << "\n";
    cout << "most significant one bit: " << MsoneBit(n, i) << "\n";

    //funciones para contar bits
    cout<< "0's izq int : " <<__builtin_clz(1) << "\n";  //cuenta 0's a la izquierda el nro para enteros 32 bits para long long 64 bits
    cout<< "0's izq long long: " <<__builtin_clzll(1) << "\n";

    cout<< "cuenta 0's " <<__builtin_ctz(2048) << "\n";    //cuenta 0's a la derecha del nro

    cout<< "cuennta 1's " <<__builtin_popcount(15) << "\n";  //cuenta los bits prendidos de un nro
    cout<< isPowerOfTwo(62) << " potencia\n";
    cout<< " contar unos \n";
    cout<< count_one(15);

}
