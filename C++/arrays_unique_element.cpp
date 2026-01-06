#include<iostream>
using namespace std;
int unique_element(int arr[],int size)
{
    int ans=0;

    for(int i=0;i<size;i++)
    {
        ans=ans^arr[i];
    }

    return ans;
    // int count=0,unique =-1;
    // for(int i=0;i<size;i++)
    // {
    //     for(int j=0;j<size;j++)
    //     {
            
    //         if(i==j)
    //             {
    //                 j++;
    //             }
                
    //         if(arr[i]==arr[j])
    //         {
                
    //             count =1;
                
    //             break;
    //         }
    //         else
    //         {
    //             unique=arr[j];
    //             count = 0;
    //         }
    //     }
        
        
    //     if(count ==0)
    //     {
    //         cout<<"unique element is "<<arr[i]<<endl;
    //         unique =1;
    //     }
        
        
    // }
    // if(count == 1 && unique==-1)
    //     {
    //         cout<<"no unique element"<<endl;
    //     }
}
int main()
{
    int arr[7]={1,1,2,4,5,5,2};
    cout<<unique_element(arr,7);
    return 0;
}