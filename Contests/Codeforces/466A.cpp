    #include<bits/stdc++.h>
    using namespace std;
    int main()
    {

        int n,m,a,b,r;
        cin>>n>>m>>a>>b;

        int men=n*a;

        ///
        if(m>n)
        {
            r=b;

        if(r<men)
            men=r;
        }


        ///


        if(a>b)
            r=((n/m)*b)+((n%m)*b);
        else
            r=((n/m)*b)+((n%m)*a);

        if(r<men)
            men=r;


        ///

        if(b==1 )
        {
            r=((n/m)+1);
            if(r<men)
                men=r;
        }

        ///








        cout<<men<<endl;
        return 0;
    }
