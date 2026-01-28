#include<iostream>
using namespace std;

int peakIdexInMountainArray(int arr[], int size)
{
    int s=0;
    int e = size-1;
    int mid = s + (e-s)/2;

    while(s<e)
    {
        if(arr[mid]<arr[mid + 1])
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

int main()
{
    int arr[15] = {1,2,3,4,5,6,7,8,9,10,11,3,2,1,0};
    cout<<"Peak Index in mountain is"<<peakIdexInMountainArray(arr,15);
    return 0;
}