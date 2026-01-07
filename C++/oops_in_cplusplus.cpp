#include<iostream>
using namespace std;
class student 
{
    // string name;

public:
    int age;
    string name;  
    bool gender;


    student()
    {
        cout<<"Default constructor"<<endl;
    }//default const

    student(string s, int a, int g)
    {
        cout<<"Parameterised constructor"<<endl;
        name = s;
        age = a;
        gender = g;
    }//parametrised constructor


    student(student &a)
    {
        cout<<"Copy constructor"<<endl;
        name = a.name;
        age = a.age;
        gender = a.gender;
    }

    ~student()
    {
        cout<<"Destructor called"<<endl;
    }


    void setName(string s)
    {
       name = s;
    } 

    string getName(string s)
    {
        cout<<name<<endl;
        return 0; 
    }

   


    void printInfo()
    {

        cout<<endl<<endl;
        cout<<"Name = ";
        cout<<name<<endl;
        cout<<"Age = ";
        cout<<age<<endl;
        cout<<"Gender = ";
        cout<<gender<<endl;
        
    }
    

    bool operator == (student &a)
    {
        if((name == a.name) &&  (age == a.age) && (gender = a.gender))
        {
            return true;
        }
        return false;
    }







// //area of circle
// float area(int r)
// {
//     return 3.141 *r*r;
// }
// //area of rectangle
// int area(int l, int r)
// {
//     return l*r;
// }

// return 0;

};




int main()
{
    // student arr[3];
    // for(int i=0;i<3;i++)
    // {
    //     string s;
    //     cout<<"Name = ";
    //     cin>>s;
    //     arr[i].setName(s);
    //     cout<<"Age = ";
    //     cin>>arr[i].age;
    //     cout<<"Gender = ";
    //     cin>>arr[i].gender;
    // }

    // for(int i=0;i<3;i++)
    // {
    //     arr[i].printInfo();
    // }

    student a("Urvi", 20 ,1);
    // a.printInfo();
    student b;
    student c = a;


    if(b==a)
    {
        cout<<"Same"<<endl;
    }
    else
    {
        cout<<"Not Same"<<endl;
    } 


    if(c==a)
    {
        cout<<"Same"<<endl;
    }
    else
    {
        cout<<"Not Same"<<endl;
    }

    return 0;
}