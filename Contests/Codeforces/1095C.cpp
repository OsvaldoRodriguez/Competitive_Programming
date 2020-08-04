#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ii pair<int,int>
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define fore(i,a,b) for(int i = a;i < b; i+= 1)
#define forr(i,a) for(int i = a; i >= 0; i--)
#define fori(i,m) for(auto i = m.begin(); i != m.end(); i++)
using namespace std;
typedef long long ll;
const int N = 2 * 1e5 + 5;
const int mod = 1e9 + 7;
const ll MAX = (1LL << 32) - 1;
bool f(int x){
	if(x&(x - 1))
		return 0;
	return 1;
}
int v[31];
int main(){
	fast;
	int n,k;
	fore(i,0,31)
		v[i] = (1 << i);

	cin >> n >> k;
	if(k == 1 && f(n))
		cout << "YES\n" << n << "\n";
	else{
		if(k > n){
			cout << "NO\n";
			return 0;
		}
		int cant = 0;
		int i = 30;
		vector<int> ans;
		int cn = n;
		while( i >= 0){
			if(cn >= v[i]){
				cn -= v[i];
				ans.pb(v[i]);
			}
			else i--;
		}
		if(ans.size() > k)
			cout << "NO\n";
		else{
			cant = ans.size();
			vector<int> x;
			int i = 0;
			int j = 0;
			while(cant < k && i < ans.size()){
				j = 0;
				bool flag = 0;
				while(ans[i] != v[j]){
					if(ans[i] / v[j] + cant - 1 <= k && ans[i] != -1){
						fore(k,0,ans[i] / v[j]){
							ans.pb(v[j]);
						}
						cant += ans[i] / v[j] - 1; 
						ans[i] = -1;
							break;
					}else
						j++;
				}
				i++;
				
			}
			
			cout << "YES\n";
			for(auto i : ans)
				if(i != -1)
				cout << i << " ";
			cout << endl;
		}
	}
	return 0;	
}
