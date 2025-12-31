#include<iostream>
using namespace std;

int main()
{
    int i, j, k,l, n=5,  value =1;

    // cout<<"Enter the value of n";
    // cin>>n;
    // cout<<endl;

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n-i+1;j++)
        {
            cout<<j;
        }
        for(k=1;k<i;k++)
        {
            cout<<"**";
        }
        
        for(l=1;l<n-i+2;l++)
        {
            cout<<n-i-l+2;
        }
        cout<<endl;
    }

    return 0;
}