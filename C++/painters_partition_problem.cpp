#include<iostream>
using namespace std;

bool isPossible(int arr[], int size, int n, int m, int mid)
{
    int painterCount = 1;
    int wallsum = 0;

    for(int i = 0;i<n;i++)
    {
        if(wallsum + arr[i] <= mid)
        {
            wallsum + arr[i];
        }
        else
        {
            if(painterCount>m)
            {
                return false;
            }
            
        }
        return true;
    }
}

int allocatePainter(int arr[],int size, int n, int m)
{
    int s = 0;
    int sum = 0;

    for(int i=0;i<n;i++)
    {
        sum+=arr[i];

    }
    int e = sum;
    int ans = -1;
    int mid = s +(e-s)/2;

    while(s<=e)
    {
        if(isPossible(arr,size,n,m,mid))
        {
            ans = mid;
            e = mid - 1;

        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}