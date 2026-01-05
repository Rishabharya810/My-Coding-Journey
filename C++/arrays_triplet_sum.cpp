#include<iostream>
using namespace std;

void triplet_sum(int arr[], int size,int key)
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            for(int k=0;k<size;k++)
            {
                if(i==j)
                {
                    j++;
                }
                if(j==k)
                {
                    k++;
                }
                if(k==i)
                {
                    k++;
                }

                if((i+j+k)==key)
                {
                    cout<<"triplet with a given sum "<<key<<" is "<<i<<","<<j<<","<<k<<endl;


                }

                
            }
        }
    }
}

int main()
{
    int arr[8]={-2,-1,0,1,2,3,4,5};
    triplet_sum(arr,8,3);


    return 0;
}