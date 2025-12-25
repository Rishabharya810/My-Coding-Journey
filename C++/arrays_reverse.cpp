#include<iostream>
using namespace std;

void reverse_array(int arr[], int size)
{
    int n1=0,n2=size-1,temp;
    for(int i=0;n1<=n2;i++)
    {
        swap(arr[n1],arr[n2]);

        n1++;
        n2--;
    }
    
}

void print_Array(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";

    }
}

int main()
{
    int i=0;
    int arr[8]={1,2,3,4,5,6,7,8};
    int brr[6]={5,4,6,7,2,8};
    
    reverse_array(arr,8);
    print_Array(arr,8);

    cout<<endl<<endl;
    
    reverse_array(brr,6);
    print_Array(brr,6);

    return 0;
}