#include <bits/stdc++.h>
#define endl '\n' 
using namespace std;
typedef long long ll;
const int N = 104;
int v[10];
int main(){
	int x,y;
	cin >> x >> y;
	bool flag = 1;
	for(int i = x; i <= y; i++){
		memset(v,0,sizeof v);
		int n = i;
		while(n > 0){
			v[n % 10]++;
			n /= 10;
		}
		flag = 1;
		for(int j = 0;j < 10; j++)
			if(v[j] > 1){
				flag = 0;
				break;
			}
		if(flag){
			cout << i << '\n'; 
			break;
		}
	}
	if(!flag)
		cout << -1 << '\n'; 
	return 0;
}
