#include<iostream>
using namespace std;

unsigned int countSetBits(unsigned int n)
{
    unsigned int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

int main()
{
    int n, count;
    cout<<"Enter the number to check for power of 2 ";
    cin>>n;
    count = countSetBits(n);
    if(count == 1)
    {
        cout<<"Power of 2 verfied";

    }

    else 
    {
        cout<<"Not power of 2";

    }
    return 0;
}