#include<iostream>
using namespace std;

int main()
{
    int n, count=0;
    cout<<"Enter number"<<endl;
    cin>>n;
    cout<<endl;
    
    while(n!=0)
    {
        if(n&1)
        {
            count++;
        }
        n=n>>1;
    }
    
    cout<<"number of ones in binary form is "<<count;
  
    return 0;
}