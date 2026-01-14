#include<iostream>
using namespace std;

void print(int arr[],int size)
{
    
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
}

int array_sum(int arr[],int size)
{
    int sum=0;
    for(int i=0;i<size;i++)
    {
        sum = sum + arr[i];
    }
    return sum;
}

int main()
{
    int size;int arr[10];
    cout<<"Enter size of array"<<endl;
    cin>>size;

    cout<<"Enter "<<size<<" array elements"<<endl;
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }

    cout<<"Sum of array "<<array_sum(arr,size)<<endl;

    cout<<"Print arrays"<<endl;
    print(arr, size);




    return 0;

}