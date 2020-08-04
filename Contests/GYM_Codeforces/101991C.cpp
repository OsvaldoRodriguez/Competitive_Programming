#include <bits/stdc++.h>
using namespace std;
map<string,pair<int,pair<int,int> > > mp;
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("coffee.in","r",stdin);
	
	int t;
	cin >> t;
	while(t--){
		int n,m;
		mp.clear();
		cin >> n >> m;
		for(int i = 0; i < n; i++){
			string s;
			int a,b,c;
			cin >> s >> a >> b >> c;
			mp[s] = {a,{b,c}}; 
		}
		string x,y,z;
		int sumP = 100 / m;
		for(int i =  0; i < m; i++){
			cin >> x >> y >> z;
			int val;
			if(y == "small")
				val = mp[z].first;
			if(y == "large")
				val = mp[z].second.second;
			if(y == "medium")
				val = mp[z].second.first;
			val += sumP;
			if((val + 1) % 5 == 0)
				val++;
			else if((val - 1) % 5 == 0)
				val--;

			cout << x << " " << val << '\n';
			
		}
		
		
	}
}
