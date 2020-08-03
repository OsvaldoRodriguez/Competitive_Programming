#include <bits/stdc++.h>

using namespace std;
bool rec(double x1,double y1,double x2,double y2,double x3 ,double y3)
{
    double a=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    double b=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
    double c=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
   // printf("\n %.2f %.2f %.2f     a  b c\n",a,b,c );
    priority_queue<double> q;
    q.push(a);
    q.push(b);
    q.push(c);
    double hip=q.top()*q.top();q.pop();
    double lado1=q.top()*q.top();q.pop();
    double lados2=q.top()*q.top();q.pop();
    double lados=lado1+lados2;
           // printf("%.5f %.5f %.0f %.0f %.0f %.0f %.0f %.0f \n",hip,lados,x1,y1,x2,y2,x3,y3);
        if(abs(hip-lados)<=0.0000000001 && hip>0.000000001 && lado1>0.000000001 && lados2>0.000000001)
            return 1;
        return 0;
}
int main()
{
    double x1,y1,x2,y2,x3,y3;
    while(cin>>x1>>y1>>x2>>y2>>x3>>y3)
    {
        if(rec(x1,y1,x2,y2,x3,y3))
            cout<<"RIGHT\n";
        else
        {
            if(rec(x1,y1+1,x2,y2,x3,y3) || rec(x1-1,y1,x2,y2,x3,y3) || rec(x1,y1-1,x2,y2,x3,y3) || rec(x1+1,y1,x2,y2,x3,y3) || rec(x1,y1,x2,y2+1,x3,y3) || rec(x1,y1,x2-1,y2,x3,y3) || rec(x1,y1,x2,y2-1,x3,y3) || rec(x1,y1,x2+1,y2,x3,y3) || rec(x1,y1,x2,y2,x3,y3+1) || rec(x1,y1,x2,y2,x3-1,y3) || rec(x1,y1,x2,y2,x3,y3-1) || rec(x1,y1,x2,y2,x3+1,y3))
                cout<<"ALMOST\n";
            else
                cout<<"NEITHER\n";
        }
    }
    return 0;
}
