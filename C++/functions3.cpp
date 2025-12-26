#include<iostream>
using namespace std;

int update(int a  )
{ 
    int ans = a*a;
    return ans;
}

int main()
{
    int a = 14;
    int ar[10];
    a = update(a);
    cout<<a<<endl; 
    for(int i=0;i<10;i++)
    {
        cout<<ar[i]<<endl;
    }

}