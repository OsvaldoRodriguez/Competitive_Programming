#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ii pair<int,int>
#define F first
#define S second
#define pb push_back
#define pf push_front
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define fore(i,a,b) for(int i = a;i < b; i+= 1)
#define forr(i,a) for(int i = a; i >= 0; i--)
#define fori(i,m) for(auto i = m.begin(); i != m.end(); i++) 
#define sz(s) int(s.size())
#define cls(a,car) memset(a,car,sizeof (a))
using namespace std;
typedef long long ll;
const int N = 5 * 1e5 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
int v[N];
int main(){
    string s;
    cin >> s;
    bool sw_1 = 0,sw_2 = 0,sw_11 = 0,sw_22 = 0;
    int idx_1 = -1,idx_2 = -1;
    int cnt = 0;
    int ans = 0;
    fore(i,0,sz(s)){
        if(!sw_1 && s[i] == '[' && !v[i]){
            v[i] = 1;
            sw_1 = 1;
            idx_1 = i;
        }
        
    }
    forr(i,sz(s) - 1){
        if(!sw_11 && s[i] == ']' && !v[i]){
            v[i] = 1;
            sw_11 = 1;
            idx_2 = i;
        }
        
    }
    if(sw_1 && sw_11)
        ans += 2;
    else{
        cout << "-1\n";
        return 0;
    }
    fore(i,idx_1,idx_2){
        if(!sw_2 && s[i] == ':' && !v[i]){
            v[i] = 1;
            sw_2 = 1;
            idx_1 = i;
        }
    }
    for(int i = idx_2; i > idx_1; i--){
        if(!sw_22 && s[i] == ':' && !v[i]){
            v[i] = 1;
            sw_22 = 1;
            idx_2 = i;
        }
    }
    if(sw_2 && sw_22)
        ans += 2;
    else{
        cout << "-1\n";
        return 0;
    }

    fore(i,idx_1,idx_2){
        ans += (s[i] == '|');
    }
    cout << ans << "\n";
    return 0;
}
    
