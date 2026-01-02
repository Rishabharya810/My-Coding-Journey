/*operator overloading*/
#include <iostream>
using namespace std;
class abc{
    int a, b;
public:
    void input(){
        cout<<"\nEnter 1st number(a=) : ";
        cin>>a;
        cout<<"\nEnter 2nd number(b=) : ";
        cin>>b;
    }
    void display(){

        cout<<"\n a = "<<a;
        cout<<"\n b = "<<b;
    }
    abc operator+(abc const &x){
        abc z;
        z.a = a + x.a;
        z.b = b + x.b;
        return z;
    }
    // friend abc operator+(const abc&,const abc&); };

    /*to show operator overloading using a friend function abc operator+(const abc &x,const abc &y)
    { abc z;

    z.a = x.a + y.a;

    z.b = x.b + y.b; return z;
    }

    We could have used this to achieve the same result

    */
};
int main(){
    abc ob1, ob2, ob3;
    cout<<"Object 1 :";
    ob1.input();
    ob1.display();
    cout<<"\n\nObject 2 : ";
    ob2.input();
    ob2.display();
    ob3 = ob1 + ob2;

    cout<<"\n\n\nAfter overloading operator (+) for ob3:-\n";
    ob3.display();
    return 0;
}
