#include <bits/stdc++.h>


using namespace std;



int main()
{
     int n ;
    cin>>n ;
    int may=n ;
     if (n/10 > may)
        may = n/10;
     if (n%10 + (n/100) * 10> may)
        may = n%10+(n/100)*10;




    cout << may ;

    return 0;
}
