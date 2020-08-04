#include <bits/stdc++.h>
#define endl '\n' 
using namespace std;
typedef long long ll;
const int N = 104;
set<int> s;
vector<int> v;
int main(){
	int t,n,r,x;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&r);
		s.clear();
		v.clear();
		int dis = 0;
		while(n--){
			scanf("%d",&x);
			s.insert(x);
		}
		for(auto i = s.rbegin(); i != s.rend(); i++)
			v.push_back(*i);
		for(int i = 0; i < v.size(); i++){
			if(dis * r >= v[i])
				continue;
			dis++;
		}
		printf("%d\n",dis );
	}
	return 0;
}
