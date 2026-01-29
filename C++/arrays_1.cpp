#include<iostream>
using namespace std;

void printarray(int arr[], int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int number[15];

    cout<<"Value at 14 index"<<number[14]<<endl;

    cout<<"Value at 15 index"<<number[15]<<endl;

    int second[3]={5,7,11};

    cout<<"Value at 2 index"<<second[2]<<endl;

    int third[15] = {2,7};

    int n=15;
    cout<<"Printing the array"<<endl;

    printarray(third,15);
    // for(int i=0;i<n;i++)
    // {
    //     cout<<third[i]<<" ";
    // }

    int fourth[10] = {0};
    n=10;
    cout<<endl<<"Printing the array"<<endl;

    printarray(fourth,10);
    // for(int i=0;i<n;i++)
    // {
    //     cout<<fourth[i]<<" ";
    // }

    int fifth[10] = {1};

    n=10;
    cout<<endl<<"Printing the array "<<endl;
    printarray(fifth,10);

    // for(int i=0;i<n;i++)
    // {
    //     cout<<fifth[i]<<" ";
    // }


    cout<<endl<<"Everything is fine"<<endl;

    return 0;
}