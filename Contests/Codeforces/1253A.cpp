#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ii pair<int,int>
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
const ll MAX = INT_MAX;
int v[N],w[N],z[N];
int main(){
	fast;
	int t,n;
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 0; i < n; i++)
			cin >> v[i];
		for(int i = 0; i < n; i++)
			cin >> w[i];
		int tmp = 0;
		int j = 0;
		for(int i = 0; i < n; i++)
			if(v[i] != w[i] && w[i] - v[i] > 0){
				tmp = w[i] - v[i];
				j = i;
				break;
			}else if(v[i] > w[i]){
				tmp = MAX;
				break;
			}
		if(tmp == 0)
			cout << "YES\n";
		else if(tmp == MAX)
			cout << "NO\n";
		else{
			for(;j < n; j++)
				if(v[j] != w[j])
					v[j] += tmp;
				else break;
			tmp = 1;
			for(auto i = 0; i < n; i++)
				if(v[i] != w[i]){
					tmp = 0;break;
				}
			if(tmp)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
		
	}
	return 0;	
}
