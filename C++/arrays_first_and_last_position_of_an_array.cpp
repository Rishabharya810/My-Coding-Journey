#include<iostream>
using namespace std;

// void print_element(int size, int key, int start, int end)
// {
//     cout<<"size "<<size;
//     cout<<" key "<<key;
//     cout<<" start "<<start;
//     cout<<" end "<<end;
// };

void first_last_position(int arr[], int size, int key)
{
    int start = 0, end = 0;

    for(int i=0;i<size;i++)
    {
        if(arr[i]==key)
        {
            //cout<<"start part"<<endl;
            //print_element(size,key,start,end);
            //cout<<endl;
            start=i;
            break;
            
        }
    }
    
    //cout<<start ;
    
    for(int i=start;i<size;i++)
    {   
        
        //cout<<endl;
        //cout<<arr[i]<<arr[i+1]<<endl;
        
        if (arr[i]!=arr[i+1])
        {
            //int i = start;
            end=i;
            //cout<<"end part"<<endl;
            //print_element(size,key,start,end);
            //cout<<endl;
            //end == i+1;
            cout<<"start position is "<<start<<endl;
            cout<<"end position is "<<end;
            break;
            
        }

    }


};


int main()
{
    int arr[8]={0,1,2,2,2,2,3,3};
    first_last_position(arr,8,2);
    return 0;
}