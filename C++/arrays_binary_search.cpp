#include<iostream>
using namespace std;

// int middle_element(int i, int size)
// { 
//     int mid=0;
//     if(size%2==0)
//     {
//         mid=(i+size)/2;
//     }
//     else
//     {
//         mid=(i+size+1)/2;
//     }
    

//     return mid;
// }

// void binary_search(int arr[], int size, int key)
// {
//     int mid = 0;
//     for(int i=0;i<size;)
//     {
//         mid = middle_element(i,size);
        
//         if(arr[mid]==key)
//         {
//             cout<<arr[mid]<<" found at "<<mid+1<<" position ";
//             break;
//         }

//         if (arr[mid]<key)
//         {
//             i=mid;
//             mid = middle_element(i,size);
//         }
//         if (arr[mid]>key)
//         {
//             size=mid; 
//             mid = middle_element(i,size);   
//         }
//     }
// }
//OR

int binarySearch(int arr[], int size, int key)
{
    int start = 0;
    int end = size - 1;
    
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

int main()
{
    int even[8] = {2,6,10,11,14,20,22,25};
    int odd[7] = {3,5,7,11,15,16,17};
    

    // binary_search(even,8,20);
    // binary_search(odd,7,15);

    cout<<"Index of 20 is "<<binarySearch(even,8,20)<<endl;
    cout<<"Index of 15 is "<<binarySearch(odd,7,15);
    return 0;
}