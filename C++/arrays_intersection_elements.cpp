#include<iostream>
using namespace std;

void intersection_element(int arr[],int brr[], int n1, int n2)
{
    
    for(int i=0;i<n1;i++)
    {
        //int update;
        for(int j=0;j<n2;j++)
        {   
            //brr[j]= update;
            //cout<<brr[j];

            // cout<<endl<<arr[i]<<brr[j]<<endl;

            if(arr[i]<brr[j])
            {
                i++;
                break;

            }

            if(arr[i]==brr[j])
            {
        
                //update = -112231; 
                brr[j]= -112231;
                //cout<<"==>"<<brr[j];
                cout<<"intersection element is "<<arr[i]<<endl;
                
                break;
                
            }
        }
    }
}
int main()
{
    int arr[5]={1,2,3,4,3};
    int brr[3]={3,4,6};
    intersection_element(arr,brr,5,3);
    

    return 0;
}