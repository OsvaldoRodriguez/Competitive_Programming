#include <bits/stdc++.h>
#define endl '\n' 
using namespace std;
typedef long long ll;
const int N =  5;
int v[N];
int main(){
	for(int i = 0; i < 4; i++)
		cin >> v[i];
	bool flag = 0;
	int s = v[0] + v[1] + v[2] + v[3];
	for(int i = 0; i < (1<<4); i++){
		int sum = 0;
		for(int j = 0; j < 4; j++){
			if(i&(1<<j)){
				sum += v[j];
			}
		}
		if(sum == s - sum){
			flag = 1;
			break;
		}
	}
	flag? cout << "YES\n":cout << "NO\n";
	return 0;
}
