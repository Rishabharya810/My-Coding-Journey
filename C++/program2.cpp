/* function overloading */
#include<iostream>
#include<conio.h>
using namespace std;
float add(float a, float b)
{ 
    float sum;
    sum=a+b; 
    return sum;
}
int add(int a, int b)
{ 
    int sum;
    sum = a+b;
    return sum;
}
float add(float a,int b)
{ 
    float sum;
    sum = a+b; 
    return sum;
}
int add(int a,float b)
{ 
    int sum;
    sum = a+b;
    return sum;
}
int main()
{ 
    int a=10,b=25,sum1; 
    float c=17.34,d=37.29,sum2; 
    sum2=add(c,d); 
    cout<<"\n Sum = "<<sum2; 
    sum1=add(a,b); 
    cout<<"\n Sum = "<<sum1; 
    sum2=add(c,a); 
    cout<<"\n Sum = "<<sum2; 
    sum1=add(b,d); 
    cout<<"\n Sum = "<<sum1;
    return 0;
}




