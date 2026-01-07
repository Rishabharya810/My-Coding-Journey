#include<iostream>
#include"bits/stdc++.h"
// #include<climits>
using namespace std;


// void SubarrayWithGivenSum()
// {
//     int n,s;
//     cin>>n>>s;
//     int a[n];
//     for(int i=0;i<n;i++)
//     {
//         cin>>a[i];
//     }

//     int i=0, j=0; int st=0-1; int sum=0;
//     while (j<n&& sum +a[j]<=s)
//     {
//         sum+= a[j];
//         j++;
//     }
//     if(sum == s)
//     {
//         cout<<i+1<<" "<<j<<endl;
//         return;
//     }
//     while(j<n)
//     {
//         sum+= a[j];
//         while(sum>s)
//         {
//             sum -= a[i];
//             i++;
//         }
//         if(sum ==s)
//         {
//             st = i+1;
//             en = j+1;
//             break;
//         }
//         j++;

//     }
//     cout<<st<<" "<<en<<endl;
    

// }

int main()
{
    int n;
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    const int N = 1e6+2;
    int idx[n];
    for(int i=0;i<N;i++)
    {
        idx[i] =-1;
    }

    int minidx = INT_MAX;

    for(int i=0;i<n;i++)
    {
        if(idx[a[i]]!= -1)
        {
            minidx = min(minidx, idx[a[i]]);
        
        }
        else{
            idx[a[i]] = i;
        }   
    }

    if(minidx == INT_MAX)
    {
        cout<<"-1"<<endl;
    }
    else
    {
        cout<<minidx + 1<<endl;
    }
    return 0;
}