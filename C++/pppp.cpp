#include<iostream>
using namespace std;

class student 
{
    private:
        string name;
        wchar_t a;
        int age=12;
        int height;

    public:
    // void set_a()
    // {
    //     this->a = L 'π';
    // }
    int getAge()
    {
        return this->age;
    }

};

int main()
{   
    student first;
    char ch1= 1234;
    cout<<"code"<<endl;
    first.getAge();
    wchar_t pi = L'π';
    wcout<<pi<<endl;
    
    cout<<"OK"<<endl;

    cout<<ch1;

    return 0;
}