#include<iostream>
using namespace std;

void seprate_zeros_and_ones(int arr[],int size)
{
    int count=0;
    //counting number of zeros
    for(int i=0;i<size;i++)
    {
        if(arr[i]==0)
        {
            count++;
        }
    }

    //filling arrays with 0 until number of zeros

    for(int i=0;i<count;i++)
    {
        arr[i]=0;
    }

    //filling rest of the array with 1
    
    for(int i=count;i<size;i++)
    {
        arr[i]=1;
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
    seprate_zeros_and_ones(arr,8);

    print_array(arr,8);
    return 0;
}