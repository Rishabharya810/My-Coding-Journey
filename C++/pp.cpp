#include<iostream>
using namespace std;

int main()
{
    int i, j, n;
    char ch = 'A';

    cout<<"Enter the value of n"<<endl;
    cin>>n;
    cout<<endl;

    for(i=1;i<=n;i++)
    {
        char ch = 'A' + (n-i);
        for(j=1;j<=i;j++)
        {
            
            cout<<ch++ ;
        }
        cout<<endl;
    }

    return 0;
    //42:51
}