//#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }

    cout<<endl;
}

void sort_array(int arr[],int size)
{ 
    int left = 0, right = size-1;
    while(left<right)
    {
        if (left>=right)
        {
            break;
        }

        while (arr[left]==0 && left < right)
        {
            left++;
        }

        while(arr[right]==1 && left < right)
        {
            right--;
        }


        //if we have reached this point this means
        // arr[left]==1 and arr[right]==0

        swap(arr[left],arr[right]);
        left++;
        right--;
    } 

}

int main()
{
    int arr[8]={1,0,1,1,0,0,0,1};
    sort_array(arr,8);
    printArray(arr,8);
    return 0;
}