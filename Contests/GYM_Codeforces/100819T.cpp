#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 200005;
int v[26];
priority_queue<int,vector<int>,greater<int> > q;
int main(){
  bool f1=1;
  bool f2=1;
  int x,y,z;
  cin>>x>>y>>z;
  q.push(x);q.push(y);q.push(z);
  int a=q.top();q.pop();
  int b=q.top();q.pop();
  int c=q.top();q.pop();
  int d=c*c;
  if(a*a+b*b!=d)
    f1=0;

    cin>>x>>y>>z;
    q.push(x);q.push(y);q.push(z);
    int a1=q.top();q.pop();
    int b1=q.top();q.pop();
    int c1=q.top();q.pop();
    int e=c1*c1;
    if(a1*a1+b1*b1!=e)
      f1=0;

  if(f1 && f2 && e==d && a1==a && b1==b && c1==c)
    cout<<"YES\n";
  else cout<<"NO\n";
  return 0;
}
