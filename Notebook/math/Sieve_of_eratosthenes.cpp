#include <bits/stdc++.h>
using namespace std;
typedef long long   ll;
const int N = 1e5 + 50;

int v[N];// 0 is prime
bitset<N> pr; // 0 is prime

void sieve(){ //O(n log log n)
    v[0] = v[1] = 1;
    for(int i = 2; i * i < N; i++)
        if(!v[i])
            for(int j = i * i; j < N; j += i)
                v[j] = 1;
}

void sieveBitSet(){
    pr[0] = pr[1] = 1;
    for(int i = 2; i * i < N; i++)
        if(!pr[i])
            for(int j = i * i; j < N; j += i)
                pr[j] = 1;
}

void fact(){
    for(int i = 1; i < N; i++)
        v[i] = i;
    for(int i = 2; i * i < N; i++)
        if(v[i] == i)
            for(int j = i * i; j < N; j += i)
                if(v[j] == j)
                    v[j] = i; // smallest prime factor
}

map<int, int> recFact(int x){
    map<int, int> m;
    while(v[x] != 1){
        m[v[x]]++;
        x /= v[x];
    }
    return m;
}
int main(){
    int x = 93848;
    fact();
    auto cur = recFact(x);
    for(auto i = cur.begin(); i != cur.end(); i++)
    cout << i-> first << " " << i-> second << '\n';
    return 0;
}       
