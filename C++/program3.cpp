/* matrix addition */ 
#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int a[10][10];
    int i,j,m,n;
    cout<<"\n Enter no of rows for Matrix 1    : ";
    cin>>m;
    cout<<"\n Enter no of columns for Matrix 1 : ";
    cin>>n;
    cout<<"\n Enter Elements of Matrix 1       :\n ";
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    cout<<"\n Enter no of rows for Matrix 2    : ";
    cin>>m;
    cout<<"\n Enter no of columns for Matrix 2 : ";
    cin>>n;
    cout<<"\n Enter Elements of Matrix 2       :\n ";
    int b[10][10];
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>b[i][j];
        }
    }
    int c[10][10];
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            c[i][j] = a[i][j]+b[i][j];
        }
    }
    cout<<"\n Matrix 1 \n ";
    for(i=0;i<m;i++)
    {   
        cout<<"\n";
        for(j=0;j<n;j++)
        {
            cout<<"\t"<<a[i][j];
        }
    }
    cout<<endl;
    cout<<"\n Matrix 2 \n ";
    for(i=0;i<m;i++)
    {   
        cout<<"\n";
        for(j=0;j<n;j++)
        {
            cout<<"\t"<<b[i][j];
        }
    }
    cout<<"\n Sum \n ";
    for(i=0;i<m;i++)
    {   
        cout<<"\n";
        for(j=0;j<n;j++)
        {
            cout<<"\t"<<c[i][j];
        }
    }
    return 0;
}

