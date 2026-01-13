#include<iostream>
using namespace std; 

int main()
{
    int i, j ,n ;
    char obj= 'A';
    
    cin>>n;
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            cout<<obj;
        }
        cout<<endl;
        obj++;
    }
    
}    