#include <iostream>
#define N 100001
using namespace std;
int v1[N],v2[N],n,m,A[N+2];
void mostrar(int v[],int n)
{
    for(int i=0;i<n;i++)
        cout<<v[i]<<" ";
    cout<<endl;
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>v1[i];
    cin>>m;
    for(int i=0;i<m;i++)
        cin>>v2[i];
    A[0]=1;
    A[1]=v1[0];
    for(int i=2;i<=n;i++)
        A[i]=A[i-1]+v1[i-1];
    for(int i=0;i<m;i++)
    {
        int a=-1,b=n+1,mid;
        while(b-a>1)
        {
            mid=(a+b)/2;
            if(A[mid-1]+1<= v2[i] && A[mid]>= v2[i])
            {
                if(mid==0)
                    cout<<mid+1<<"\n";
                else
                cout<<mid<<"\n";
                break;
            }
            else
            {
                if(v2[i]<A[mid])
                    b=mid;
                else
                    a=mid;
            }

        }
    }
    return 0;
}
