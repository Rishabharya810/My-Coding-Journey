#include<iostream>
using namespace std;

void intersection_elements(int arr[], int m, int brr[], int n)
{
    int i=0, j=0;

    while(i<n&&j<m)
    {
        if(arr[i]==brr[j])
        {
            cout<<"intersection element is "<<arr[i]<<endl;
            i++;
            j++;
        }
        
        
        else if(arr[i]<brr[j])
        {
            i++;
        } 

        else
        {
            j++;
        }
        // if (arr[i]>arr[j])
        // {
        //     j++;
        // }
    }
}

int main()
{
    int arr[5]= {1,2,3,4,5};
    int brr[8]= {4,5,6,7,8,9,10,11};

    intersection_elements(arr,5,brr,8);

}