#include <bits/stdc++.h>
using namespace std;
int dx[]={1,1,0,-1,-1,-1,0,1},dy[]={0,1,1,1,0,-1,-1,-1};
typedef long long ll;
const int N= 1005;
char v[N][N];
int  w[6];
int p[N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n,m;
  cin>>n>>m;
  int ans=0;
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      cin>>v[i][j];
  for(int i=0;i<m;i++)
    cin>>p[i];
  for(int i=0;i<m;i++){
    memset(w,0,sizeof w);
    for(int j=0;j<n;j++){
      //cout<<v[j][i]<<" ";
      w[v[j][i]-'A']++;
    }
    //cout<<endl;
    int may=0;
    for(int k=0;k<5;k++){
      //cout<<w[k]<<" ";
      if(may<w[k])
        may=w[k];
    }
    //cout<<endl;
    //cout<<may<<endl;
    ans+=may*p[i];
  }
  cout<<ans<<"\n";
  return 0;
}
