#include<iostream>
#include<cmath>
#include<limits.h>
using namespace std;

int main()
{
    int i=0,d,n,ans=0;
    cout<<"Enter integer to reverse"<<endl;
    cin>>n;
    
    cout<<n<<" when reversed is ";
    if(n>0)
    {
        while(n!=0)
        { 
            if((ans>INT_MAX/10)||(ans<INT_MIN/10))
            {
                return 0;
            }
            d=n%10;
            ans=ans*10+d;
            i++;
            n/=10;
        }

    }
    else
    {
        n=n*(-1);
        while(n!=0)
        {
            d=n%10;
            ans=ans*10+d;
            i++;
            n/=10;
        }

        ans= ans *-1;
    }


    cout<<ans<<endl<<i;
}