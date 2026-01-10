#include<iostream>
using namespace std;

void sort_zeros_and_ones(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }

        }
        
        
    }
}

void print_array(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    
}

int main()
{
    int arr[8]={0,1,0,0,1,1,0,1};
    sort_zeros_and_ones(arr,8);

    print_array(arr,8);
    return 0;
}