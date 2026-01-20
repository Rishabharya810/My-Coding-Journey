#include<iostream>
using namespace std;

int main()
{   
    int i, a=0,b=1,n, value=0;
    cout<<"Enter value of n "<<endl;
    cin>>n;
    cout<<endl;
    cout<<a<<endl<<b<<endl;
    for( i=0;i<n-2;i++)

    {   
        value=a+b;
        cout<<value<<endl;
        a=b;
        b=value;
    }
    return 0; 
}