#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ii pair<int,int>
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define fore(i,a,b,inc) for(int i = a;i < b; i+= inc)
#define forr(i,a) for(int i = a; i >= 0; i--)
using namespace std;
typedef long long ll;
const int N = 1e3 + 5;
const int mod = 1e9 + 7;
const ll MAX = (1LL << 32) - 1;
int v[26],w[26];
int index(char x,const string &b,int pos){
	fore(i,pos,b.size(),1)
		if(b[i] == x)
			return i;
}
int main(){
	fast;
	int n;
	string a,b;
	cin >> n >> a >> b;
	fore(i,0,n,1){
		v[a[i] - 'a']++;
		w[b[i] - 'a']++;
	}
	bool flag = 1;
	fore(i,0,26,1)
		if(w[i] != v[i]){
			cout << "-1\n";
			return 0;
		}
	int i = 0, j = 0;
	vector<int> ans;
	while(j < n){
		if(a[i] == b[j]){
			i++;j++;
			continue;
		}
		int aux = index(b[j],a,i);
		char aux1 = a[aux];
		for(int k = aux; k > i; k--){
			ans.pb(k);
			a[k] = a[k - 1];
		}
		a[i] = aux1;
		j++;
		i++;
	}
	cout << ans.size() << "\n";
	for(auto i : ans)
		cout << i << ' ';
	return 0;	
}
