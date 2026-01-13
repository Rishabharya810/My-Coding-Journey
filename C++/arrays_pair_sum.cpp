#include<iostream>
#include<algorithm>
using namespace std;

void sum_pair(int arr[], int size, int key)
{
    
    int minimum=0,maximum=0;
    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(arr[i]+ arr[j] ==key)
            {
                
                minimum = min(arr[i],arr[j]);
                maximum = max(arr[i],arr[j]);
                cout<<"pair sum is ("<<minimum<<","<<maximum<<")"<<endl;
            }
        }
    }
    // int pair =-1;
    // for(int i=0;i<size;i++)
    // {
    //     for(int j=0;j<size;j++)
    //     {
    //         if(i==j)
    //         {
    //             j++;
    //         } 
    //         if(arr[i]+arr[j]==key)
    //         {
    //              pair =1;
    //             cout<<"pair with a given sum "<<key<<" is "<<"("<<arr[i]<<","<<arr[j]<<")"<<endl;
    //         }
    //     }
    // }
    // if(pair==-1)
    // {
    //     cout<<"No valid pair exist for "<<key<<endl;
    // }
}

int main()
{
    int arr[8]={-2,-1,0,1,2,3,4,5};
    int brr[5]={2,-3,3,3,-2};

    sum_pair(arr,8,3);
    cout<<"-------------------------------"<<endl;
    sum_pair(brr,5,0);
    return 0;
}