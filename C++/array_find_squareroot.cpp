#include<iostream>
using namespace std;

long long int Squareroot_using_binarySearch( int key)
{
    int start = 0;

    int end = key;

    long long int ans= -1;
    
    long long int mid = start + (end - start)/2;

    while(start <= end)
    {
        long long int square = mid*mid;

        if(square == key)
        {
            return mid;
            
        }

        //go to right part
        if(square < key)
        {
            start = mid + 1;
            ans = mid;
        }
    
        else
        //go to the left part
        {
            end = mid - 1;
        }

        mid = start + (end - start)/2;
    }
    return - 1;
}

double morePrecision(int n, int precision, int tempSol)
{
    double factor = 1;
    double ans = tempSol;

    for(int i=0;i<precision;i++)
    {
        factor = factor/10;

        for(double j = ans; j*j<n;j=j+factor)
        {
            ans =j;
        }
    }

    return ans;   
    

}

int main()
{
    int n;

    cout<<"Enter the number "<<endl;
    cin>>n;

    int tempSol = Squareroot_using_binarySearch(n);

    cout<<"Precise squareroot answer is "<<morePrecision(n, 3, tempSol);
    

    
    return 0;
}