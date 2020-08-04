#include <bits/stdc++.h>
#define endl '\n' 
using namespace std;
typedef long long ll;
const int N = 1e2 + 5;
int v[N];
int c,m,x;
bool f(int n){
	int cc = c - n;
	int mm = m - n;
	if(cc < 0 or mm < 0)return 0;
	int xx = x + cc + mm;
	if( xx >= n) return 1;
	return 0;
}
int main(){
	int t;
	scanf("%d" ,&t);
	while(t--){
		scanf("%d%d%d",&c,&m,&x);
		int a = 0, b = 1<<30, m;
		while(b - a > 1){
			m = (a + b) >> 1;
			if(f(m))
				a = m;
			else 
				b = m;
		}
		printf("%d\n",a);
	}
	return 0;
}
