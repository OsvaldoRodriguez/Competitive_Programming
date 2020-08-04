#include <bits/stdc++.h>
#define endl '\n' 
using namespace std;
typedef long long ll;
const int N = 1e2 + 5;
int v[N];
int main(){
	int t;
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++)
				if((i + j) % 2 == 0)
					printf("W");
				else
					printf("B");	
			printf("\n");
		}
	return 0;
}
