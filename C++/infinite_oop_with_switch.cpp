#include<iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    int a=0, n;

    

    while(1)
    {   cout<<endl;
        cin>>n;
        switch(n)
        {
            case 1: cout<<"one";
                    continue;
            case 2: cout<<"Two";
                    continue;
            case 3: cout<<"Three";
                    continue;
            case 4: cout<<"Four";
                    continue;
            case 5: cout<<"Five";
                    continue;
            default: cout<<"Number greater than Five";
                    break;
            
        }
        cout<<endl<<"Do you want to exit this program ? type 0 to continue and 1 to exit"<<endl;
        cin>>a;
        if(a==1)
        {
            exit(1);
        }
    }
    return 0;
}