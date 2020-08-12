#include <bits/stdc++.h>
using namespace std;
const int N=1000010;
int lps[N];
string patron,texto;
vector<int> v;
bool flag=0;
void LPS(){
  int M=patron.size();
  lps[0]=0;
  int i=1,len=0;
  while(i<M){
    if(patron[i]==patron[len]){
      len++;
      lps[i]=len;
      i++;
    }
    else
    {
      if(len!=0)
        len=lps[len-1];
      else
      {
        lps[i]=0;
        i++;
      }
    }
  }
 
}
void KMP(){
  int M=patron.size();
  int N=texto.size();
  LPS();
  int i=0,j=0;
  while(i<N){
    if(texto[i]==patron[j]){
      i++;j++;
    }
    if(j==M){
      v.push_back(i-j+1);
      flag=1;
      j=lps[j-1];
    }
    else
    {
      if(i<N && texto[i]!=patron[j]){
        if(j!=0)
          j=lps[j-1];
        else
          i++;
      }
    }
 
  }
}
int main()
{
  int test,t=1;
  cin>>test;
  while(test--){
    flag=0;
    v.clear();
    cin>>texto>>patron;
    KMP();
    if(t>1)
      cout<<"\n";
    t++;
    if(flag){
    cout<<v.size()<<"\n";
    for(int i=0;i<v.size();i++)
      cout<<v[i]<<" ";
    cout<<"\n";
  }
  else
    cout<<"Not Found\n";
 
  }
  return 0;
}
