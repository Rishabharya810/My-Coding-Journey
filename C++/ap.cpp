#include<iostream>
using namespace std;

int ap(int n)
{
    return (3*n)+7;
}

int main()
{
    int n;

    cout<<"Enter value of n"<<endl;
    cin>>n;
    cout<<"AP is "<<ap(n);
}
