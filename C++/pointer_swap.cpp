#include<iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;

}

int main()
{
    int a=2;
    int b=4;
    cout<<"Before swap \n a = "<<a<<" b = "<<b<<endl;
    swap(&a,&b);
    cout<<"After swap \n a = "<<a<<" b = "<<b<<endl;

    return 0;
}