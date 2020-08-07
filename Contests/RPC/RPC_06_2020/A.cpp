#include <bits/stdc++.h>
#define FIN         ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ii          pair<int,int>
#define pl          pair<long long, long long>
#define F           first
#define S           second
#define pb          push_back
#define all(x)      (x).begin(),(x).end()
#define rall(x)     (x).rbegin(),(x).rend()
#define fore(i,a,b) for(int i = a;i < b; i+= 1)
#define forr(i,a)   for(int i = a; i >= 0; i--)
#define fori(i,m)   for(auto i = m.begin(); i != m.end(); i++) 
#define w(t)        while(t--)
#define sz(s)       int(s.size())
#define cls(a,car)  memset(a,car,sizeof (a))
#define db(x)       cerr << #x << " is " << x << '\n'
#define FL          freopen("input.txt", "r", stdin),freopen("output.txt", "w", stdout);
#define EjecuteTime cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n"
#define angle(x)    double(x * acos(-1) / 180.0)
using namespace std;
typedef long long   ll;
typedef vector<int> vi;
typedef vector<ii>  vii;
const int N = 2 * 1e5 + 5;
const ll mod = 1e9 + 7;
const double E = 1e-9;
int dx[] = {1, 0}, dy[] = {0, 1};
//int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
map<char, vector<string>> m;
int main(){
    //FL;
    FIN;
    string str;
    int n;
    m.clear();
    cin >> str >> n;
    for(int i = 0; i < n; i++){
        string aux;
        cin >> aux;
        m[aux[0]].pb(aux);
    }
    
    char cmp = str[sz(str) - 1];
    if(m.count(cmp) == 0)
        cout << "?\n";
    else{
        bool flag = 0;
        string ans = "@";
        string ans2 = "@";
        
        vector<string> aux = m[cmp];
        for(int j = 0; j < sz(aux); j++){
            char car = aux[j][sz(aux[j]) - 1];
            //db(car);
            if(car == cmp){
                if(m[car].size() == 1){
                    flag = 1;
                    ans = aux[j];
                    break;
                }else{
                    if(ans2 == "@")
                    ans2 = aux[j];
                }
            }else{
                if(m.count(car) == 0){
                    flag = 1;
                    ans = aux[j];
                    break;
                }else{
                    if(ans2 == "@")
                    ans2 = aux[j];
                }
            }
        }
   
        if(flag)
            cout << (ans + "!") << '\n';
        else
            cout << ans2 << '\n';
    }
    EjecuteTime;
    return 0;
}       
