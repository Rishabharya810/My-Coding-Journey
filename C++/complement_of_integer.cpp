#include<iostream>
#include<cmath>
#include<limits.h>
using namespace std;

int main()
{
    int n,i=0,d,m,ans,mask =0;

    cout<<"Enter value"<<endl;
    cin>>n;
    cout<<endl<<"Complement of an integer is ";
    m=n;
    if(n==0)
    {
        ans=1;
    }
    else
    while(m!=0)
    {
        mask = (mask<<1)|1;
        m=m>>1;
    }
    ans = (~n) & mask;
    // while(n!=0)
    // {
    //     d=!(n&1);
    //     n>>1;
    //     ans = (ans + (d* pow(10,i)));
    //     i++ ;
    // }
    
    // n=ans;
    // i=0;
    // while(n!=0)
    // {
    //     d=n%10;
    //     ans= (ans + (d*pow(2,i))); 
    //     i++;
    //     n/=10;
    // }
    cout<<ans;
    return 0;
}