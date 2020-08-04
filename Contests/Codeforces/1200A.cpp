#include <bits/stdc++.h>
using namespace std;
int dx[]={1,1,0,-1,-1,-1,0,1},dy[]={0,1,1,1,0,-1,-1,-1};
typedef long long ll;
const int N= 1e5+5;
bool v[10];
priority_queue<int,vector<int>,greater<int> > q;
int main(){
  int n;
  char s[N];
  scanf("%d %s",&n,&s);
  for(int i=0;i<strlen(s);i++){
    if(s[i]=='L')
    for(int j=0;j<10;j++)
      if(!v[j]){
        v[j]=1;
        break;
      }
    if(s[i]=='R')
      for(int j=9;j>=0;j--)
        if(!v[j]){
          v[j]=1;
          break;
        }
    if(s[i]!='L' && s[i]!='R')
   v[s[i]-'0']=0;
  }
  for(int  i=0;i<10;i++)
    printf("%d",v[i]);
  return 0;
}
