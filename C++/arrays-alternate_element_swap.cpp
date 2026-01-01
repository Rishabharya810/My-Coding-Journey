#include<iostream>
using namespace std;

void swap_alternate_element(int arr[], int size)
{
    for(int i=0;i<size;i+=2)
    {
        if(i+1<size)
        {
            swap(arr[i],arr[i+1]);
            //i+=1;
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
    int arr[7] = {1,2,3,6,5,4,9};
    swap_alternate_element(arr,7);
    print_array(arr,8);

    return 0;
}