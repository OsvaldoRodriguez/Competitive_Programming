#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ii pair<int,int>
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
const int N = 1e6 + 5;
const int mod = 1e9 + 7;
const ll MAX = INT_MAX;
int v[N];
int w[N],z[N];
int main(){
	fast;
	int n;
	cin >> n;
	bool flag = 1;
	for(int i = 0; i < n; i++){
		cin >> v[i];
		if(v[i] > 0)
			w[v[i]]++;
		else 
			z[-v[i]]++;
	}
	if(n&1){
		cout << "-1";
		return 0;
	}
	for(int i = 1;i < N; i++){
		if(((w[i] + z[i])& 1)){
			cout << "-1\n";
			return 0;
		}
	}
		int i = 0;
		vector<int> ans;
		int aux1 = 0;
		int tam;
		while(i < n){
			int ini = i;
			int aux = v[i];
			i++;
			map<int,int> m;
			m.clear();
			m[aux]++;
			tam = 1;
			while(tam > 0 && i < n){
				if(v[i] > 0){
					m[v[i]]++;
					tam++;
				}
				if(m[v[i]] > 1){
					flag = 0;
					i = n + 1;
					break;
				}
				if(v[i] < 0){
					if(!m.count(-v[i])){
						flag = 0;
						i = n + 1;
						break;
					}

					tam--;
				}
				i++;
			}	
			if(flag && tam == 0){
				ans.pb(i - ini);
				aux1 += i - ini;
			}
			
		}
		if(flag && ans.size() > 0 && aux1 == n && tam == 0){
			cout << ans.size() << "\n";
			for(auto i : ans)
				cout << i << ' ';
		}
		else cout << "-1\n";
	
	return 0;	
}
