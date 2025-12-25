#include<iostream>
using namespace std;

// int findDuplicates(vector<int> &arr)
// {   
    
//     return ans;
// }

int main()
{
    int arr[6] = {1,2,5,4,4,6};

    // cout<<findDuplicates(arr[]);

    int ans = 0;
    for(int i=0;i<6;i++)
    {
        ans = ans^arr[i];
    }

    for(int i=1;i<6;i++)
    {
        ans = ans^i;
    }


    return 0;
}