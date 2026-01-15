#include<iostream>
using namespace std;

unsigned int cal(unsigned int n)
{
    unsigned int count =0;
     while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count; 
}
int total_setbits(int a, int b)
{
    unsigned int total;
    
    total = cal(a)+cal(b) ;
    return total;
}

int main()
{
    int a, b;
    cout<<"Enter first number";
    cin>>a;
    cout<<"Enter second number ";
    cin>>b;
    cout<<"Total number of setbits is "<<total_setbits(a,b);

    return 0;
}