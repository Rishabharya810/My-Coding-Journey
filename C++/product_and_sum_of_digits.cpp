#include<iostream>
using namespace std;

int main()
{
    int n,product=1,sum=0;
    cout<<"Enter number"<<endl;
    cin>>n;

    while(n!=0)
    {
        int d=n%10;
        n=n/10;
        product=product*d;
        sum=sum+d;
        
    }
    cout<<"Product is "<<product<<endl;
    cout<<"Sum is "<<sum<<endl;
    cout<<"Product - sum is "<<product-sum;

}