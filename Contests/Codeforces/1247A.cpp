#include <bits/stdc++.h>
#define endl '\n' 
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ii pair<int,int>
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
const int N = 35 + 5;
const int mod = 1e9 + 7;
const ll MAX = INT_MAX;
char f(char x){
	if(x == 'R')
		return 'P';
	if(x == 'P')
		return 'S';
	if(x == 'S')
		return 'R';
	
}
char f1(char x){
	if(x == 'R')
		return 'S';
	if(x == 'S')
		return 'P';
	if(x == 'P')
		return 'R';
}
int main(){
	fast;
	int a,b;
	cin >> a >> b;
	if(a == 9 && b == 1)
		cout << "9 10\n";
	else{
		if(a > b){
		cout << "-1\n";
		return 0;
	}else
		if(b - a > 1)
			cout << "-1\n";
		else if( b == a){
			int aux = 5;
			cout << a * 10 + aux << " " << b * 10 + aux + 1 << "\n";
		}
		else
			cout << a << " " << b << "\n"; 
	}
	return 0;
	
}
