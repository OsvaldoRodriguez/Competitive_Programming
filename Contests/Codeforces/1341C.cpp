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
int v[2 * N];
int n, t, a, b, c, d;
int main(){
    fin;
    cin >> t;
    w(t){
        cin >> n;
        fore(i, 0, n)
            cin >> v[i];
        bool flag = 1;
        int last = 1;
        int i = n - 1;
        int ant = n;
        while(i >= 0){
            int j = i;
            while(j >= 0 && v[j] != last)
                j--;
            int k = j;
            j++;
            while(j < n && v[j - 1] + 1 == v[j]){
                last = v[j];
                j++;
            }
            if(j != ant){
                flag = 0;
                break;
            }

            last++;
            ant = k;
            i = k - 1;
        }
        cout << (flag? "Yes" : "No") << endl;

    }
    return 0;
}   
