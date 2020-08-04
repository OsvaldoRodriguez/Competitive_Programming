#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ii pair<int,int>
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
const int N = 1e3 + 5;
const int mod = 1e9 + 7;
const ll MAX = INT_MAX;
int v[11];
int main(){
	fast;
	string a;
	int n;
	cin >> n >> a;
	for(int i = 1; i < 10; i++)
		cin >> v[i];
	string b = "";
	int i = 0;
	for(; i < n; i++)
		if(a[i] - '0' >= v[a[i] - '0'])
			b += a[i];
		else break;
	bool flag = 0;
	for(; i < n; i++){
		if(a[i] - '0' <= v[a[i] - '0']){
			b += to_string(v[a[i] - '0']);
			flag = 1;
		}else
			break;
	}
	for(;i < n; i++)
		b += a[i];
	cout << max(a,b) << endl;
	return 0;	
}
