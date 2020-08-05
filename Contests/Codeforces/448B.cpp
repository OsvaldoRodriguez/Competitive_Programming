#include <bits/stdc++.h>
#define fin ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
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
#define w(t) while(t--)
#define sz(s) int(s.size())
#define cls(a,car) memset(a,car,sizeof (a))
#define what_is(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ii> vii;
const int N = 1 * 1e5 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
const double E = 1e-9;
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
int v[26], arr[26];
int main(){
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    fin;
    string s, t;
    cin >> s >> t;
    for(auto i : s)
        v[i - 'a']++;
    for(auto i : t)
        arr[i - 'a']++;
    
    bool flag = 1;
    fore(i, 0, 26){
        if(arr[i] > v[i])
            flag = 0;
    }
    if(!flag or sz(s) < sz(t))
        cout << "need tree\n";
    else{
        string a1 = s;
        string a2 = t;
        sort(all(a1));
        sort(all(a2));
        if(a1 == a2)
            cout << "array\n";
        else{
            int i = 0;
            int j = 0;
            while(j < sz(s)){
                if(s[j] == t[i])
                    j++,i++;
                else
                    j++;
            }
            if(i == sz(t))
                cout << "automaton\n";
            else
                cout << "both\n";
        }
    }
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}   
