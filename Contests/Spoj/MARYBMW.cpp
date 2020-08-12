#include <bits/stdc++.h>
using namespace std;
const int N=50010;
int n,m,P[N];
typedef long long ll;
typedef tuple<ll,int,int> lii;
vector<lii> v;
void init()
{
    for(int i=0;i<N;i++)
        P[i]=i;
}
bool cmp(lii a,lii b)
{
    return get<0>(a) > get<0>(b);
}
int FIND(int u)
{
    if(u==P[u])
        return u;
    return P[u]=FIND(P[u]);
}
ll kruskal()
{
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<m;i++)
    {
        int u=get<1>(v[i]);
        int z=get<2>(v[i]);
        ll cost=get<0>(v[i]);
        int pu=FIND(u),pz=FIND(z);
        if(pu!=pz)
            P[pu]=pz;
        if(FIND(1)==FIND(n))
            return cost;
    }
    return -1;
}
int main()
{
    int t,a,b;
    ll p;
    scanf("%d",&t);
    while(t--)
    {
        v.clear();
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++)
        {
            scanf("%d %d %lld",&a,&b,&p);
            v.push_back(lii(p,a,b));
        }
        init();
        printf("%lld\n",kruskal());
 
    }
    return 0;
}
