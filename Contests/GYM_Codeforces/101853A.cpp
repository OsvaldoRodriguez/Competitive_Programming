#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N= 1e5+10;
int v[N];
set<int> s;
map<int,int> m;
int main(){
  int t,n,q,a,b,c;
  scanf("%d",&t);
  while(t--){
    s.clear();
    m.clear();
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++){
      scanf("%d",&v[i]);
      s.insert(v[i]);
      m[v[i]]++;
    }
    while(q--){
      scanf("%d",&a);
      if(a==1){
        scanf("%d %d",&b,&c);
        m[v[b]]--;
        if(!m[v[b]]){
          s.erase(v[b]);
        }
        v[b]=c;
        s.insert(c);
        m[c]++;
       
      }else{
        int ans=(int)s.size();
        if(s.count(0))
          ans--;
        printf("%d\n",ans);
      }

    }

  }
  return 0;
}

