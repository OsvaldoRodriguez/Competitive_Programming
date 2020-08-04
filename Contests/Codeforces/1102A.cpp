#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ii pair<int,int>
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define fore(i,a,b) for(int i = a;i < b; i+= 1)
#define forr(i,a) for(int i = a; i >= 0; i--)
#define fori(i,m) for(auto i = m.begin(); i != m.end(); i++)
using namespace std;
typedef long long ll;
const int N = 2 * 1e5 + 5;
const int mod = 1e9 + 7;
const ll MAX = (1LL << 32) - 1;
int v[101];
map<int,int> m;
int main(){
	fast;
	int n;
	cin >> n;
	if(n == 1 or n == 2)
		cout << "1\n";
	else{
		if(!(n & 1))
			n -= 2;
		else
			n--;
		
		if(n % 4 == 0)
				cout << "1\n";
			else cout << "0\n";
	}
	return 0;	
}
