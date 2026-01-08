/* template function */ 
#include<iostream> 
using namespace std;

template <class T> 
T big(T a,T b)
{
    if(a>b)
    return(a);
    else
    return(b);
}
int main()
{
    cout<<big(3,5)<<endl;
    cout<<big(2.4,7.4);
}

