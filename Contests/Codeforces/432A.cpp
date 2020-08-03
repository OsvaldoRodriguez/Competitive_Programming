#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    int v[n];

    for(int i=0;i<n;i++)
        cin>>v[i];

    int cont=0;
    for(int i=0;i<n;i++)
        if(v[i]+k<=5)
            cont++;

    cout<<cont/3<<endl;
    return 0;
}
