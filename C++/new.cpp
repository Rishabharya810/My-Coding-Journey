#include<iostream>
using namespace std;

//find factorial of a number in c++

int main()
{
    int a, fact=1;
    cin>>a;

    for(int i=a;i>0;i--)
    {
        
        fact *=i;
        
    }
    cout<<"Factorial of "<<a<<" is "<< fact;
}