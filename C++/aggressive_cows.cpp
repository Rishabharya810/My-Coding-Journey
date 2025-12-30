#include<iostream>
using namespace std;

void selectionSort(int a[], int n) {
   int i, j, min, temp;
   for (i = 0; i < n - 1; i++) {
      min = i;
      for (j = i + 1; j < n; j++)
      if (a[j] < a[min])
      min = j;
      temp = a[i];
      a[i] = a[min];
      a[min] = temp;
   }
}

bool isPossible(int stalls[], int k, int mid, int m)
{
    int cowCount = 1;
    int lastPos = stalls[0];

    for(int i=0;i<m;i++)
    {
        if(stalls[i] - lastPos >= mid)
        {
            cowCount++;
            if(cowCount==k)
            {
                return true;
            }
            lastPos=stalls[i];
        }

    }
    return false;
}

int aggresiveCows(int stalls[], int size, int k)
{
    selectionSort(stalls, size);
    int s=0, m = size, e = stalls[m-1], ans = -1, mid = s + (e-s)/2;
    while(s<=e)
    {
        if(isPossible(stalls, k, mid, m))
        {
            ans=mid;
            s = mid + 1;

        }

        else
        {
            e = mid -1;

        }
        mid = s + (e-s)/2;
    }
    return ans;
}