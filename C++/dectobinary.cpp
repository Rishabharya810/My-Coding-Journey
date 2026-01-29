#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    double /*a[99999],*/ i = 0, /*d,value,binary,*/ ans = 0;

    cout << "Enter number to convert from decimal to binary " << endl;
    cin >> n;

    if (n > 0)
    {
        while (n != 0)
        {
            double bit = n & 1;
            ans = (bit * pow(10, i) + ans);

            n = n >> 1;
            i++;
        }
        cout << "Answer is " << ans << endl;
    }
    else
    {
        cout<<"number is not postive  integer";
    }
    // {
    //     n=n*(-1)
    //     while (n != 0)
    //     {
    //         double bit = n & 1;
    //         ans = (bit * pow(10, i) + ans);

    //         n = n >> 1;
    //         i++;
    //     }
    //     ans
    // }

    // while(n!=0)
    // {
    //     d=n%10;
    //     a[i]=n&1;
    //     i++;

    //     n=n>>1;
    // }
    // cout<<"Binary representation is "<<endl;
    // int j=i;
    // for(;j>=0;j--)
    // {
    //     cout<<a[j];
    // }
    cout << endl;
}