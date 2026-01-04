/* exception handeling */
#include<iostream> 
#include<conio.h> 
using namespace std;
int main()
{ 
    int x = -1; cout<<"\n Before Try"; 
    try
    { 
        cout<<"\n Inside Try"; 
        if(x<0)
        {
            throw x;
            cout<<"\n After throw (never executed)";
        }
    }
    catch(int x)
    {
        cout<<"\n Exception caught";
    }
    cout<<"\n After catch(excecuted)";
    return 0;
}
