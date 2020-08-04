#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 100 + 5;
int v[N][N*100];
int n;
vector<ii> w;
int main(){
	string s;
	int a,b,f;
	while(cin >> n){
		w.clear();
		cin >> s;
		f = 1;
		memset(v,0,sizeof v);
		for(int i = 0; i < n; i++){
			cin >> a >> b;
			w.push_back(ii(a,b));
			for(int k = b - 1; k >= 0; k--)
				v[f][k] = (s[i] == '1');
			f++;
		}
		f = 1;
		for(int i = 0; i < n; i++){
			a = w[i].first;
			b = w[i].second;
			bool flag = 0;
			if(s[i] == '1')
				flag = 1;
			bool flag1 = 0;
			if(flag)
				flag1 = 1;
			int cont = 0;
			for(int j = b; j <= 10000; j++){
				if(flag1){
					v[f][j] = 0;
					cont++;
					if(cont == a){
						flag1 = 0;
						cont = 0;
					}
				}else{
					v[f][j] = 1;
					cont++;
					if(cont == a){
						flag1 = 1;
						cont = 0;
					}
				}
			}
			f++;
		}
		int ans = 0;
		for(int i = 0; i <= 10000; i++){
			int may = 0;
			for(int j = 0 ;j <= n; j++){
				if(v[j][i])
					may++;
			}
			if(ans < may)
				ans = may;
		}
		cout << ans << '\n';


	}
	return 0;
}
