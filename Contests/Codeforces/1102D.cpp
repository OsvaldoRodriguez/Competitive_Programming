#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ii pair<long long,long long>
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
int v[3];
int main(){
    fast;
    int n;
    string s;
    cin >> n >> s;
    fore(i,0,n)
        v[s[i] - '0']++;
    int cnt = n / 3;
    if(v[1] == v[0] && v[0] == v[2] && v[1] == v[2]){
        cout << s << '\n';
        return 0;
    }
    //if(max(v[0],max(v[1],v[2])) == v[2]){
        for(int i = 0; i < n; i++){
            if(s[i] == '2' && v[2] > cnt && v[0] < cnt){
                s[i] = '0';
                v[0]++;
                v[2]--;
            }
            if(s[i] == '2' && v[2] > cnt && v[1] < cnt){
                s[i] = '1';
                v[1]++;
                v[2]--;
            }
        } 

       /* cout << s <<  " 1edti\n";
        for(int i = 0; i < n; i++){
            if(s[i] == '1' && v[1] > cnt && v[0] < cnt){
                s[i] = '0';
                v[0]++;
                v[1]--;
            }
            if(s[i] == '2' && v[2] > cnt && v[0] < cnt){
                s[i] = '0';
                v[0]++;
                v[2]--;
            }
        } 
        cout << s << " 2editmay\n";
        for(int i = 0; i < n; i++){
            if(s[i] == '1' && v[1] > cnt && v[0] < cnt){
                s[i] = '0';
                v[0]++;
                v[1]--;
            }
            if(s[i] == '2' && v[2] > cnt && v[0] < cnt){
                s[i] = '0';
                v[0]++;
                v[2]--;
            }
        } 

        cout << s << "\n";
        return 0;

    }*/
    for(int i = n - 1; i >= 0; i--){
        if(s[i] == '0' && v[0] > cnt && v[2] < cnt){
            s[i] = '2';
            v[2]++;
            v[0]--;
        }
        if(s[i] == '1' && v[1] > cnt && v[2] < cnt){
            s[i] = '2';
            v[2]++;
            v[1]--;
        }
    } 
    for(int i = n - 1; i >= 0; i--){
        if(s[i] == '0' && v[0] > cnt && v[1] < cnt){
            s[i] = '1';
            v[1]++;
            v[0]--;
        }
        if(s[i] == '2' && v[2] > cnt && v[1] < cnt){
            s[i] = '1';
            v[1]++;
            v[2]--;
        }
    } 
    for(int i = 0; i < n; i++){
        if(s[i] == '1' && v[1] > cnt && v[0] < cnt){
            s[i] = '0';
            v[0]++;
            v[1]--;
        }
        if(s[i] == '2' && v[2] > cnt && v[0] < cnt){
            s[i] = '0';
            v[0]++;
            v[2]--;
        }
    } 

    cout << s << '\n';
	return 0;
}
