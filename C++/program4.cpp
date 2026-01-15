/* friend function */
#include<iostream>
#include<conio.h>
#include<stdio.h>
using namespace std;
class numbers
{
    float a,b;
    public:
    void input(float c, float d)
    {
        a=c;
        b=d;
    }
    friend float great(numbers num);
};
float great(numbers num)
{
    float g;
    if(num.a>num.b)
        g=num.a;
    else
        g=num.b;
    return g;
}
int main()
{
    float h,j,gr;
    numbers n1;
    cout<<"\n Enter two Numbers : ";
    cout<<"\n Num 1 : "; cin>>h;
    cout<<"\n Num 2 : "; cin>>j;
    n1.input(h,j);
    gr=great(n1);
    cout<<"\n Greatest Number : "<<gr;
    getch();
    return 0;
}



