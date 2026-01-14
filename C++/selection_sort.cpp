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

void selection_sort(int arr[], int n)
{
    
    for(int i=0;i<n-1;i++)
    {
        int minIndex=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[minIndex])
            {
                minIndex=j;
            }
            
        }
        swap(arr[minIndex],arr[i]);

    }
}

int main()
{
    int arr[8]={2,5,3,9,4,56,3,5};
    int brr[4]={5,3,6,9};
    selection_sort(arr,8);
    print_array(arr,8);
    selection_sort(brr,4);
    print_array(brr,4);
    return 0;
}