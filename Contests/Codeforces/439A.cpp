    #include <bits/stdc++.h>

    using namespace std;

    int main()
    {
        int n,d;
        cin>>n>>d;
        int v[n+1];
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            cin>>v[i];
            sum+=v[i];
        }


        if(sum+10*(n-1)>d)
            cout<<-1<<endl;
        else
            cout<<(d-sum)/5<<endl;

        return 0;
    }
