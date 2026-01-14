#include<iostream>
#include<limits.h>
using namespace std;

void update(int arr[], int n)
{
    cout<<endl<<"Inside the function"<<endl;

    //updating array's first element
    arr[0]= 120;
    //printing the array
    for(int i=0;i<3;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"Going back to the main function"<<endl;
}

int getMax(int num[], int n)
{
    int max = INT_MIN;

    for(int i=0;i<n;i++)
    {
        if(num[i]>max)
        {
            max = num[i];
        }       
    }
    return max;
}


int getMin(int num[], int n)
{
    int min = INT_MAX;

    for(int i=0;i<n;i++)
    {
        if(num[i]<min)
        {
            min = num[i];
        }    
    }
    return min;
}

int main()
{
    int size;
    

    int arr[3] = {1,2,3};
    update(arr,3);

    //printing the array
    for(int i=0;i<3;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    int num[100];

    cin>>size;

    for(int i=0;i<size;i++)
    {
        cin>>num[i];
    }

    cout<<"Maximum value is "<<getMax(num,size)<<endl;
    cout<<"Minimum value is "<<getMin(num,size)<<endl; 
}