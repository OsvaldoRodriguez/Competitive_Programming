#include <bits/stdc++.h>
#define FIN         ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ii          pair<int,int>
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
const int N = 8 * 1e5 + 5;
const ll mod = 1e9 + 7;
const double E = 1e-9;
//int dx[] = {1, 0}, dy[] = {0, 1};
//int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
//int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
int n;
string str;
string cur = "abacaba";
string ans = "";
bool c(char x, char cmp){
    return (x == cmp or x == '?');
}
bool ok(){
    for(int i = 0; i < n - 6; i++){
        if(str[i] == 'a' or str[i] == '?'){
            if(c(str[i], 'a') && c(str[i + 1], 'b') && c(str[i + 2], 'a') && c(str[i + 3], 'c') && c(str[i + 4], 'a') && c(str[i + 5], 'b') && c(str[i + 6], 'a')){
                int k = 0;
                for(int k = 0; k < 7; k++)
                    ans[i + k] = cur[k];
                return 1;
            }
        }
    }
    return  0;
}
int main(){
    //FL;
    FIN;
    int t;
    cin >> t;
    while(t--){
        cin >> n >> str;
        int count = 0;
        ans = str; 
        for(int i = 0; i < n - 6; i++){
            string aux = str.substr(i, 7);
            if(aux == cur)
                count++;
        }
        if(count > 1)
            cout << "NO\n";
        else{

            bool flag = 0;
            for(int i = 0; i < n - 6; i++){
                ans = str;
                if(str[i] == 'a' or str[i] == '?'){
                    if(c(str[i], 'a') && c(str[i + 1], 'b') && c(str[i + 2], 'a') && c(str[i + 3], 'c') && c(str[i + 4], 'a') && c(str[i + 5], 'b') && c(str[i + 6], 'a')){
                        int k = 0;
                        for(int k = 0; k < 7; k++)
                            ans[i + k] = cur[k];

                        for(int k = 0; k < n; k++)
                            if(ans[k] == '?')
                                ans[k] = 'z';

                        count = 0;
                        for(int k = 0; k < n; k++){
                            string a1 = ans.substr(k, 7);
                            if(a1 == cur)
                                count++;
                        }
                        if(count == 1){
                            flag = 1;
                            cout << "YES\n";
                            cout << ans << '\n';
                            break;
                        }
                    }   
                }
            }
            if(!flag)cout << "NO\n";
        }
    }
    EjecuteTime;
    return 0;
}       
