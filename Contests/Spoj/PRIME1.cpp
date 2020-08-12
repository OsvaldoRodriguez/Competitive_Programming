#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N = 100005;
bool primo(int n){
  if(n==2)return 1;
  if(n<2 or n%2==0)
    return 0;
  for(int i=3;i*i<=n;i+=2)
    if(n%i==0)
      return 0;
  return 1;
}
int main()
{
  int t,a,b;
  scanf("%d",&t );
  while(t--){
    scanf("%d %d",&a,&b);
    for(int i=a;i<=b;i++){
      if(primo(i))
        printf("%d\n",i);
    }
    printf("\n");
  }
  return 0;
}
