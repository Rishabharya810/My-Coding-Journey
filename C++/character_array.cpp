#include<iostream>
using namespace std;

int main ()
{
    char arr[100]="APPLE", arr1[1000];

    int i=0;
    cin>>arr1;

    while(arr[i]!='\0')
    {
        cout<<arr[i]<<endl;
        i++;
    }

    i=0;
    cout<<endl<<arr1[2]<<endl;
    while(arr1[i]!='\0')
    {
        cout<<endl<<arr1[i];
        i++;
    }
    return 0;
}