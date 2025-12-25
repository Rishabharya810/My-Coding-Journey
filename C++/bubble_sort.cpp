#include<iostream>
using namespace std;

void print_array(int arr[], int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void bubble_sort(int arr[], int size)
{
    for(int i=0;i<size;i++)
    {
        bool sorted = false;
        for(int j=0;j<size-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                sorted = true;
                swap(arr[j],arr[j+1]);
            }
        }
        if(sorted == false)
        {
            break;
        }
    }
}

int main()
{
    int arr[8]={2,5,3,9,4,56,3,5};
    int brr[4]={5,3,6,9};
    bubble_sort(arr,8);
    print_array(arr,8);
    bubble_sort(brr,4);
    print_array(brr,4);
    return 0;
}