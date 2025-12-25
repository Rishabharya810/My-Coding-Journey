#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int n,d, i=0, ans=0;

    cout<<"Enter binary number to be converted to decimal "<<endl;
    cin>> n;
    cout<<endl;

    cout<<"decimal value for "<<n<<" is";
    while(n!=0)
    {
        d=n%10;
        ans = ans + (d*pow(2,i));
        i++;
        n=n/10;
    }
    cout<<ans;
}