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
const int N = 1 * 1e5 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
int acc[N],acc1[N];
int main(){
    fast;
    int n;
    string s;
    cin >> n;
    cin.ignore();
    while(n--){
        getline(cin,s);
        bool flag = 1;
        fore(i,0,sz(s)){
            string aux = "";
            while(i < sz(s) && s[i] != ' ')
                aux += tolower(s[i++]);
            
            if(flag){
                if(sz(aux) == 1){
                    char axi = toupper(aux[0]);
                    cout << axi << "ay ";
                    flag = 0;
                    continue;
                }
                aux[1] = toupper(aux[1]),flag = 0;
            }
            fore(j,1,sz(aux))
                cout << aux[j];
            cout << aux[0]  << "ay ";
        }
        cout << "\n";
    }
    return 0;
}
