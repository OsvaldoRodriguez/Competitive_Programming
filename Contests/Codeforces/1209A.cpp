#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100 + 5;
vector<int> G[N];
int w[N];
int n;
int main(){
	int x;
	while(cin >> n){
		set<int> s1;
		for(int i = 0; i < N; i++)
			G[i].clear();
		for(int i = 0; i < n; i++){
			cin >> x;
			G[i].push_back(x);
			s1.insert(x);
		}
		for(int i = 0; i < n; i++){
			int k = G[i][0];
			//cout << G[i][0] << "\n";
			for(int j = 1;j <= k; j++){
				if(k % j == 0){
					G[i].push_back(j);
					//cout << " na "<< j << "\n";
				}
			}
		}
		for(int i = 0; i < n; i++){
			//cout << G[i][0] << " valor\n";
			for(int j = 1; j < G[i].size(); j++){
				//cout << G[i][j] << " div\n";
				if(s1.count(G[i][j])){
					w[i] = G[i][j];
					break;
				}
			}
		}
		set<int> s;
		for(int i = 0; i < n; i++)
			s.insert(w[i]);
		cout << (int)s.size() << "\n";
	}
	return 0;
}
