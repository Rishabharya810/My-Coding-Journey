/* pure virtual function*/ 
#include<iostream> 
#include<conio.h>
using namespace std;
class Base
{ 
    int x; 
    public:
    virtual void func()=0; //this is pure virtual function
};
class Derived : public Base
{ 
    int y; 
    public:
    void func()
    {
        cout<<"\n func() is called \n ";
    }
};
int main()
{ 
    Derived d; 
    d.func();
    return 0;
}
