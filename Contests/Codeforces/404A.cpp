    #include <bits/stdc++.h>

    using namespace std;

    int main()
    {
        int n;
        cin>>n;

        char m[n][n];

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>m[i][j];
            }
        }

        bool a=true;
        int q=m[0][0],w=m[0][1];

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(q!=w)
                {
                    if(i==j || i+j+1==n)
                    {
                      if(m[i][j]!=q)
                        {
                            a=false;
                            break;

                        }
                    }

                    else
                        if(m[i][j]!=w)
                        {
                            a=false;
                            break;
                        }
                }
                else
                {
                    a=false;
                    break;
                }


            }
        }

        if(a)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
        return 0;
    }
