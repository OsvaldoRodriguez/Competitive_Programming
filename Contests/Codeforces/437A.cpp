#include <bits/stdc++.h>
int iii;
using namespace std;
int menor(int v[])
{int men=100;
    for(int i=0;i<4;i++)
    {
        if(men>v[i])
            {men=v[i];iii=i;}

    }
    ///cout<<iii<<endl;
    return men;
}

int mayor(int v[])
{int may=0;
    for(int i=0;i<4;i++)
    {
        if(may<v[i])
            {may=v[i];iii=i;}
    }
    return may;
}

void mostrar(int v[])
{
    for(int i=0;i<4;i++)
    cout<<v[i]<<" ";
}
void mostrarLetra(int v[],int m)
{
    int r=0;
    for(int i=0;i<4;i++)
       if(v[i]==m)
         r=i+1;

      switch(r)
        {
        case 1:cout<<"A"<<endl;break;
        case 2:cout<<"B"<<endl;break;
        case 3:cout<<"C"<<endl;break;
        case 4:cout<<"D"<<endl;break;
        }

}
bool iguales(int v[])
{
    for(int i=0;i<3;i++)
        for(int j=i+1;j<4;j++)
            if(v[i]!=v[j])
            return false;

    return true;
}

int main()
{
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    int v[4];
    v[0]=a.size()-2;
    v[1]=b.size()-2;
    v[2]=c.size()-2;
    v[3]=d.size()-2;




    //mostrar(v);
   //cout<<endl<<menor(v)<<endl;
int cont=0;


   bool qwe=true;
   for(int i=0;i<c.size();i++)
        if(c[i]=='_')
            cont++;
///<<cont<<" "<<c.size()-2<<endl;
   if(cont==c.size()-2)
   qwe=false;


   if(!qwe)
   {
        cout<<"C"<<endl;
   }

   else
   {
       if(iguales(v))
        cout<<"C"<<endl;
       else
       {
          bool qwe=false,ws=true;
        bool sw=true;
        for(int i=0;i<4;i++)
        {
           /// cout<<iii<<" guarda"<<endl;
            if(menor(v)*2>v[i]&& iii!=i)
                {
                   /// cout<<"entra"<<endl;
                    sw=false;
                    break;
                }
        }

           for(int i=0;i<4;i++)
            {
                if(mayor(v)/2<v[i]&&iii!=i)
                    {
                        ws=false;
                        break;
                    }
            }

        if(sw && ws)
            cout<<"C"<<endl;
        else
        {
            if(sw)
              {
                 mostrarLetra(v,menor(v));//cout<<" actual";
              }
            else
            {
                if(ws)
                    {mostrarLetra(v,mayor(v));//cout<<" actual 2";
                    }
            }

            if(!sw &&!ws)
                cout<<"C"<<endl;
        }
       }
   }


    return 0;
}
