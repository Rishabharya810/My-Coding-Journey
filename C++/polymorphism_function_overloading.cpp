#include<iostream>
using namespace std;

// function overloading

class abc
{
public:
    void fun()
    {
        cout<<"I am a function with no argument"<<endl;
    }

    void fun(int x)
    {
        cout<<"I am a function with int argument"<<endl;
    }
    void fun(double x)
    {
        cout<<"I am a function with double argument"<<endl;
    }
};

int main()
{
    abc obj;
    obj.fun();
    obj.fun(4);
    obj.fun(6.2);
    
}
