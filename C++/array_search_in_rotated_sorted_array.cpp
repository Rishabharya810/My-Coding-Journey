#include<iostream>
using namespace std;


int getPivot(int arr[], int n)
{
    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;

    while(s<e)
    {
        if(arr[mid] >= arr[0])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;

        }
        mid = s + (e-s)/2;
    }
    return s;
}

int binarySearch(int arr[], int s, int e, int key)
{
    int start = s;
    int end = e;
    
    int mid = start + (end - start)/2;

    while(start <= end)
    {
        if(arr[mid] == key)
        {
            return mid;
        }

        //go to right part
        if(key>arr[mid])
        {
            start = mid + 1;
        }
        else 
        //go to the left part
        {
            end = mid - 1;
        }

        mid = start + (end - start)/2;
    }
    return - 1;
}


int find_position(int arr[], int n, int k)
{
    int pivot = getPivot(arr, 8);
    
    if(k >= arr[pivot] && k <= arr[n-1] )
    {
        return binarySearch(arr,pivot,n-1,k);
    }
    else
    {
        return binarySearch(arr,0,pivot-1,k);

    }

}

int main()
{
    int arr[8] = {11,14,20,22,25,2,6,10};
    cout<<"Element is at position "<<find_position(arr,8,6)<<endl;
    cout<<"Element is at position "<<find_position(arr,8,11)<<endl;
    return 0;
}
