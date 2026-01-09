#include<iostream>
using namespace std;

bool ispowerof2(int n)
{
    cout<<(0 && 1)<<endl;
    cout<< !(n & n-1)<<endl;
    return(n && !(n & n-1));
}

int main()
{
    
    cout<<ispowerof2(2)<<endl;
    
    return 0;

}

