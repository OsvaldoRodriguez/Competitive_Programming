#include <bits/stdc++.h>

using namespace std;

int main()
{
    map<string,int> m;
    m["C"] = 0;
    m["C#"] = 1;
    m["D"] = 2;
    m["D#"] = 3;
    m["E"] = 4;
    m["F"] = 5;
    m["F#"] = 6;
    m["G"] = 7;
    m["G#"] = 8;
    m["A"] = 9;
    m["B"] = 10;
    m["H"] = 11;

   string a,b,c;
   cin>>a>>b>>c;
   vector<int> v;
   v.push_back(m[a]);
   v.push_back(m[b]);
   v.push_back(m[c]);
   sort(v.begin(),v.end());
   v.push_back(v[0]+12);
   if((abs(v[0]-v[1])==4 && abs(v[1]-v[2])==3) || (abs(v[1]-v[2])==4 && abs(v[2]-v[3])==3) || (abs(v[2]-v[3])==4 && abs(v[1]-v[0])==3))
        cout<<"major\n";
   else
        if((abs(v[0]-v[1])==3 && abs(v[1]-v[2])==4) || (abs(v[1]-v[2])==3 && abs(v[2]-v[3])==4) || (abs(v[2]-v[3])==3 && abs(v[1]-v[0])==4))
            cout<<"minor\n";
        else
            cout<<"strange\n";
    return 0;
}
