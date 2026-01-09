/* addition of two numbers using constructor overloading*/ 
#include<iostream>
#include<conio.h> 
using namespace std;
class abc
{ 
    float a,b; 
    public:
    abc(float x,float y)
    {
        a = x; 
        b = y;
    }
    abc(abc const &ob)
    {
        a = ob.a + ob.b;
    }
    float returnsum()
    {
        return a;
    }
};
int main()
{ 
    float n1,n2,sum; 
    cout<<"\n Enter number 1 : "; cin>>n1;
    cout<<"\n Enter number 2 : "; cin>>n2;
    abc ob1(n1,n2); abc ob2(ob1);
    sum = ob2.returnsum(); 
    cout<<"\n Sum            : "<<sum; 
    getch();
    return 0;
}


