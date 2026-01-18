#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    char arr[100];
    cout<<"Enter your name and age"<<endl;
    cin.getline(arr,100);

    fstream myfile("abc.txt",ios::out|ios::app);
    myfile<<arr;
    myfile.close();
    cout<<"File write operation performed successfully"<<endl<<endl;
    cout<<"Reading from file operation started"<<endl;
    char arr1[100];
    ifstream obj("abc.txt");
    obj.getline(arr1,100);
    cout<<"array content: "<<endl<<arr1<<endl;
    obj.close();

    return 0;
}