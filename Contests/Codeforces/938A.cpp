#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ii pair<int,int>
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define fore(i,a,b) for(int i = a;i < b; i+= 1)
#define forr(i,a) for(int i = a; i >= 0; i--)
#define fori(i,m) for(auto i = m.begin(); i != m.end(); i++) 
#define sz(s) int(s.size())
#define cls(a,car) memset(a,car,sizeof (a))
using namespace std;
typedef long long ll;
const int N = 2 * 1e5 + 50;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
bool isvocal(char x){
    return x == 'a' or x == 'e' or x == 'i' or x == 'o' or x == 'u' or x == 'y';
} 
bool f(const string &s){
    fore(i,1,sz(s))
        if(isvocal(s[i - 1]) && isvocal(s[i]))
            return 0;
    return 1;
}
int main(){
    //fast;
    int t; 
    string s;
    cin >> t >> s;
    if(sz(s) == 1){
        cout << s << '\n';
        return 0;
    }
    while(1){
        if(f(s) or sz(s) == 1)
            break;
        fore(i,1,t){
            if(isvocal(s[i - 1]) && isvocal(s[i])){
                s.erase(i,1);
                break;
            }
        }
    }
    cout << s << '\n';
    return 0;
}
