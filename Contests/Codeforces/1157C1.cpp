#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ii pair<int,int>
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define fore(i,a,b) for(int i = a;i < b; i++)
using namespace std;
typedef long long ll;
const int N = 2 * 1e5 + 5;
const int mod = 1e9 + 7;
const ll MAX = INT_MAX;
int v[N];
int main(){
	fast;
	int n;
	cin >> n;
	fore(i,0,n)
		cin >> v[i];
	if(n == 1){
		cout << "1\nL\n";
		return 0;
	}
	int ans = 0;
	string cmp = "";
	int tmp;
	int i = 0, j = n - 1;
	if(v[0] <= v[n - 1]){
		tmp = v[0];
		cmp += "L";
		i++;
	}else{
		tmp = v[n - 1];
		cmp += 'R';
		j--;
	}		
	ans = 1;
	while(i <= j){
		int aux = min(v[i],v[j]);
		if(aux >= tmp){
			if(aux == v[i]){
				tmp = v[i];
				cmp += 'L';
				i++;
			}else{
				tmp = v[j];
				cmp += 'R';
				j--;
			}
		}else{
			aux = max(v[i],v[j]);
			if(aux >= tmp){
				if(aux == v[i]){
					tmp = v[i];
					cmp += 'L';
					i++;
				}else{
					tmp = v[j];
					cmp += 'R';
					j--;
				}
			}else break;
		}
	}
	cout << cmp.size() << "\n" << cmp << "\n";
	return 0;	
}
