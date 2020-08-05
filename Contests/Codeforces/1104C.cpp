#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ii pair<int,int>
#define F first
#define S second
#define pb push_back
#define pf push_front
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define fore(i,a,b) for(int i = a;i < b; i+= 1)
#define forr(i,a) for(int i = a; i >= 0; i--)
#define fori(i,m) for(auto i = m.begin(); i != m.end(); i++) 
#define sz(s) int(s.size())
#define cls(a,car) memset(a,car,sizeof (a))
using namespace std;
typedef long long ll;
const int N = 1 * 1e5 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
int a[4][4];
int isRow(){
	int ans = -1;
	fore(i,0,4){
		int aux = 0;
		fore(j,0,4)
			if(a[i][j] == 1)
				aux++;
		if(aux == 4)
			ans = i;
	}
	return ans;
}
int isCol(){
	int ans = -1;
	fore(i,0,4){
		int aux = 0;
		fore(j,0,4)
			if(a[j][i] == 1)
				aux++;
		if(aux == 4)
			ans = i;
	}
	return ans;
} 
void addRow(){
	fore(i,0,4){
		fore(j,0,3){
			if(a[i][j] == 0 && a[i][j + 1] == 0){
				a[i][j] = a[i][j + 1] = 1;
				return;
			}
		}
	}
}
void addCol(){
	fore(i,0,3){
		fore(j,0,4){
			if(a[i][j] == 0 && a[i + 1][j] == 0){
				a[i][j] = a[i + 1][j] = 1;
				return;
			}
		}
	}
}
int main(){
	fast;
	string x;
	cin >> x;
	int row = 0,col = 0;
	fore(i,0,sz(x)){
		if(x[i] == '0'){
			if(row == 0){
				cout << "1 1\n";
				row++;
			}
			else{
				cout << "3 1\n";
				row = 0;
			}
		}
		else{
			if(col == 0){
				cout << "1 2\n";
				col++;
			}
			else if(col == 1){
				cout << "2 2\n";
				col++;
			}
			else if(col == 2){
				cout << "3 2\n";
				col++;
			}
			else{
				cout << "4 2\n";
				col = 0;
			}
			
		}
	}
	return 0;
}
    
