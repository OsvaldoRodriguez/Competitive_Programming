#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 2e5 + 5;
int main(){
	int x,y,a,b;
	vector<int> v;
	cin >> x >> y >> a >> b;
	for(int i = a;i <= x; i++){
		for(int j = b; j <= y; j++){
			if(i > j)
				v.push_back(i),v.push_back(j);
		}
	}
	cout << (int)v.size()/2 << '\n';
	for(int i = 0; i < (int)v.size(); i+=2)
		cout << v[i] << ' ' << v[i + 1] << '\n';
	return 0;
}
