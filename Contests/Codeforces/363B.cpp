#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 2e5 + 5;
int v[N],acc[N];
int main(){
	int n , k;
	cin >> n >> k;
	for(int i = 0; i < n; i++)
		cin >> v[i];
	acc[0] = v[0];
	for(int i = 1; i < n; i++)
		acc[i] = acc[i - 1] + v[i];
	k--;
	int ans = acc[k];
	int val = 1;
	for(int i = k + 1; i < n; i++){
		int query = acc[i] - acc[i - k - 1];
		if( ans > query){
			val = i - k + 1;
			ans = query;
		}
	}
	cout << val  << '\n';
	return 0;
}
