#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ii pair<int,int>
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define allr(x) (x).rbegin(),(x).rend()
#define fore(i,a,b) for(int i = a;i < b; i+= 1)
#define forr(i,a) for(int i = a; i >= 0; i--)
#define fori(i,m) for(auto i = m.begin(); i != m.end(); i++) 
#define cls(s) s.clear()
#define sz(s) int(s.size())
#define	mst(a,car) memset(a,car,sizeof (a))
using namespace std;
typedef long long ll;
const int N = 2 * 1e5 + 5;
const int mod = 1e9 + 7;
const ll MAX = (1 << 30);
ll v[N];
int main(){
	fast;
	int t,n;
	cin >> t;
	while(t--){
		cin >> n;
		int idx1 = -1,idx2 = -1;
		fore(i,0,n){
			cin >> v[i];
			if(v[i] == 1)
				idx1 = i;
		} 
		if(idx1 == 0)
			idx2 = 1;
		else if(idx1 + 1 == n){
			idx2 = n - 1;
			idx1 = n - 2;
		}else{
			if(v[idx1 - 1] > v[idx1 + 1])
				idx2 = idx1 + 1;
			else 
				idx2 = idx1 - 1;
		}
		if(idx1 > idx2)
			swap(idx1,idx2);	
		ll k = 2;
		ll sum = v[idx1] + v[idx2];
		ll cambia = 0;
		string ans = "1";
		while(idx1 >= 0 && idx2 < n){
			ll tmp = k * (k + 1) >> 1;
			sum += cambia;
			if(sum == tmp)
				ans += '1';
			else
				ans += '0';
			if(idx2 + 1 == n){
				idx1--;
				cambia = v[idx1];
			}
			else if(idx1 == 0){
				idx2++;
				cambia = v[idx2];
			}
			else if(v[idx1 - 1] < v[idx2 + 1]){
				cambia = v[idx1 - 1];
				idx1--;
			}
			else{
				cambia = v[idx2 + 1];
				idx2++;
			}
		
			k++;
		}
		cout << ans << '\n';
	}
	return 0;	
}
