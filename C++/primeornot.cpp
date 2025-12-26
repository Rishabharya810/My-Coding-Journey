#include<iostream>
using namespace std;

bool isPrime(int n)
{
    for(int i=2;i<n;i++)
    {
        if(n%2 ==0)
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    int n;
    cin>>n;
    bool p;
    p = isPrime;
    if(p==1)
    {
        cout<<"Prime number";
    }
    else 

    cout<<"Not a Prime numberṇ";
    return 0;
}