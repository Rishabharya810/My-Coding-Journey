#include<iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
    for(int i = 1; i<n; i++) 
    {
        int temp = arr[i];
        //cout<<"temp "<<temp<<" "<<endl;
        int j = i-1;
        //cout<<"j "<<j<<" "<<endl;
        for(; j>=0; j--) 
        {
            
            if(arr[j] > temp) 
            {
                //shift
                //cout<<"a[j+1] "<<arr[j+1]<<endl;
                arr[j+1] = arr[j];
                //cout<<"a[j+1] "<<arr[j+1]<<endl;
            }
            else 
            {   // stop
                break;
            }
            
        }
        //copy temp value
        //cout<<"arr[j+1] "<<arr[j+1]<<endl;
        arr[j+1] = temp;  
    } 
}

int main()
{
    int arr[]={2,4,3,16,15,5,10,12};
    int n = 8;
    insertionSort(arr,n);
    
    for(int i = 0; i<8; i++) 
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}