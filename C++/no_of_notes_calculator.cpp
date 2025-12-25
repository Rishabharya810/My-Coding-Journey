#include<iostream>
using namespace std;

int main()
{
    int a, n;
    
    cout<<"Enter amount ";
    cin>>n;

    switch (1)
    {

    case 1: cout<<"number of 100 notes is "<<n/100<<endl;
            n = n- ((n/100)*100);
    case 2: cout<<"number of 50 notes is "<<n/50<<endl;   
            n = n- ((n/50)*50);
    case 3: cout<<"number of 10 notes is "<<n/10<<endl;
            n = n-((n/10)*10);
    case 4: cout<<"number of 1 notes is "<<n/1<<endl;    
            n = n-((n/1)*1);

    // case (n>=100):  cout<<"number of 100 notes is "<<n/100;
    //                 n- =((n/100)*100);
    // case (n>=50):   cout<<"number of 50 notes is "<<n/50    
    //                 n- =((n/50)*50);
    // case (n>=10):  cout<<"number of 10 notes is "<<n/10;
    //                 n- =((n/10)*10);
    // case (n>=50):   cout<<"number of 1 notes is "<<n/1;    
    //                 n- =((n/1)*1);
    
    default:
        break;
    }
}