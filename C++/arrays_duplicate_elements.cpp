#include<iostream>
using namespace std;

// int findDuplicates(vector<int> &arr)
// {   
    
//     return ans;
// }

int main()
{
    int arr[6] = {2,3,4,2,8,7};

    // cout<<findDuplicates(arr[]);

    int ans = 0;

    //XOR ing all array element

    for(int i=0;i<6;i++)
    {
        ans = ans^arr[i];
    }

    //XOR  array elements from and to [1,n-1]

    for(int i=1;i<6;i++)
    {
        ans = ans^arr[i];
    }
    
    cout<<ans;


    return 0;
}