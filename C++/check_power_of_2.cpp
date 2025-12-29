#include <iostream>
#include <cmath>
#include <limits.h>
using namespace std;

int main()
{
    int n, d = 0, ans = 1, i = 0;
    cout << "Enter value " << endl;
    cin >> n;
    cout << endl;
    if (n < 0)
    {
        cout << "Enter a positive number";
        
    }
    else
    // else if(n<INT_MAX)
    {
        for (int i = 0; i < 30; i++)
        {
            
            
            if (ans == n)
            {
                
                // int ans = pow(2, i);
                cout << "TRUE";
                break;
            }
            if(ans<INT_MAX)
            ans = ans * 2;
            
        }
        if(ans!=n)
        {
        cout << "False";
        }
        // while(n>=ans)
        // {
        //     ans = pow(2,i);
        //     if (n==ans)
        //     {
        //         d=1;
        //         break;
        //     }
        //     else
        //     {
        //         i++;
        //     }
        // }
        // if(d==1)
        // {
        //     cout<<"TRUE";

        // }
        // else
        // {
        //     cout<<"FALSE";
        // }
    }
    // else
    // {
    //     cout << "Enter corect value ";
    // }

    return 0;
}
