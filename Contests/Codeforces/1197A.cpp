#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N =100005;
int v[N];
bool cmp(int a,int b){
  return a>b;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t,n;
  cin>>t;
  while(t--){
    cin>>n;
    for(int i=0;i<n;i++){
      cin>>v[i];
    }
    sort(v,v+n,cmp);
    int cont=0;
    for(int i=2;i<n;i++){
      if(v[i]<=v[1] && v[1]!=1){
        cont++;
        if(v[1]-cont<2)
        break;
      }
    }
    cout<<cont<<"\n";
  }
  return 0;
}
/*
5 3 2 1 6
3 4 10
4 5 10
5 1 3
5 2 4
1 3 23
2 3 24
8 1 7 8 8
1 2 1
2 4 2
2 3 1
4 5 2
3 5 1
5 6 1
6 8 1
6 7 1
-1 -1 -1 -1 -1
*/
