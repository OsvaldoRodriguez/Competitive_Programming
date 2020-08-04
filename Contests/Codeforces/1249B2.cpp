#include <bits/stdc++.h>
#define endl '\n' 
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ii pair<int,int>
#define F first
#define S second
#define inf (1<<30)
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
const int N = 2 * 1e5 + 5;
const int mod = 1e9 + 7;
const int MAX = INT_MAX;
int cd = 0;
int v[N],c[N];
int FIND(int a){
	if(a == v[a])return a;
	return v[a] = FIND(v[a]);
}
int main(){
	fast;
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		for(int i = 0; i < N; i++)
			v[i] = i,c[i] = 1;
		int x;
		for(int i = 1; i <= n; i++){
			cin >> x;
			int pi = FIND(x);
			int i1 = FIND(i);
			if(pi != i1){
				v[pi] = i1;
				c[i1] += c[pi];
			}
		}
		for(int i = 1; i <= n; i++)
			cout << c[FIND(i)] << ' '; 
		cout << '\n';
	}
    return 0;
}
