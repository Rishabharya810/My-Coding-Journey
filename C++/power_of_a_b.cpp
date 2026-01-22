#include<iostream>
using namespace std;

int main()
{
    double long a, b;

    cin>>a>>b;

    double long ans = 1;

    for(int i = 1;i<=b;i++)
    {
        ans = ans *a;
    }

    cout<<"Answer is "<<ans;
    

    
}
