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
const int N = 1 * 1e5 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
int v[N];
int main(){
    fast;
    int n;
    string s;
    cin >> n >> s;
    int cnt_1 = 0,cnt_2 = 0;
    fore(i,0,n)
        if(s[i] == '(')
            cnt_1++;
        else
            cnt_2++;
    if(cnt_1 == cnt_2){
        cnt_2 = cnt_1 = 0;
        int cnt_11 = 0,cnt_22 = 0;
        bool flag_1 = 0,flag_2 = 0;
        int ans = 0;
        fore(i,0,n){
            if(s[i] == ')'){
                if(flag_2)
                    cnt_22++;
                else{
                    flag_1 = 1;
                    cnt_1++;
                }
            }else{
                if(flag_1)
                    cnt_2++;
                else{
                    cnt_11++;
                    flag_2 = 1; 
                }
            }
            if(flag_1 && cnt_1 == cnt_2){
                flag_1 = 0;
                ans += cnt_2 * 2;
                cnt_2 = cnt_1 = 0;
            }
            if(flag_2 && cnt_11 == cnt_22){
                flag_2 = 0;
                cnt_22 = cnt_11 = 0;
            }
        }
        cout << ans << '\n';
    }else
        cout << "-1\n"; 
    return 0;
}
    
