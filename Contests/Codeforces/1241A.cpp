#include <iostream>

using namespace std;

int main()
{
    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        if(n == 2){
            cout << "2\n";
            continue;
        }
        if((n&1))
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
