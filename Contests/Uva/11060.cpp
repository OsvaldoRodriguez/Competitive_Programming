#include <bits/stdc++.h>
using namespace std;
map<string,int> m;
vector<int> G[105];
vector<string> v;
int arcos[105];
int main()
{
  int n,m1,test=0;
  string cad;
  while(cin>>n)
  {
    for(int i=0;i<n;i++)
      G[i].clear();
    memset(arcos,0,sizeof arcos);
    m.clear();
    v.clear();
    for(int i=0;i<n;i++){
      cin>>cad;
      v.push_back(cad);
      m[cad]=i;
    }
    cin>>m1;
    while(m1--)
    {
      cin>>cad;
      int x=m[cad];
      cin>>cad;
      int y=m[cad];
      G[x].push_back(y);
      arcos[y]++;//lo que le llega a y
    }
      printf("Case #%d: Dilbert should drink beverages in this order:",++test);

      priority_queue<int,vector<int>,greater<int> > q;
      for(int i=0;i<n;i++)
        if(arcos[i]==0)
          q.push(i);
      while(!q.empty()){
        int ar=q.top();q.pop();
        for(vector<int>::iterator it=G[ar].begin();it!=G[ar].end();it++){
          arcos[*it]--;
          if(arcos[*it]==0)
            q.push(*it);
        }
        cout<<" "<<v[ar];
      }
      cout<<".\n";
      if(test>0)
        cout<<'\n';

  }
  return 0;
}
