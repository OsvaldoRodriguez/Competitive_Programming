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
int v[N];
vector<ii> w;
int main(){
	fast;
	int n;
	cin >> n;
	int ans = 0;
	for(int i = 0; i < n; i++)
		cin >> v[i], ans += (v[i] / 2);
	int i = 0;
	while(i < n){
		if(v[i] == 0 or ans == 0)
			cout << v[i] / 2 << "\n";
		else if((v[i] & 1)){
			if(ans > 0 && v[i] < 0){
				if(floor(v[i] / 2.0) <  v[i] / 2){
					ans -= 1;
					cout << floor(v[i] / 2.0);
				}else cout << v[i] / 2;
				cout << "\n";
			}else if(ans < 0 && v[i] > 0){
				if(ceil(v[i] / 2.0) > v[i] / 2){
					ans += 1;
					cout << ceil(v[i] / 2.0);
				}else cout << v[i] / 2;
			cout << "\n";
			}else cout << v[i] / 2 << "\n";
		}else cout << v[i] / 2<< '\n';
		i++;
	}
	return 0;	
}
