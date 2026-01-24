// #include<iostream>
// using namespace std;

// // int bill(int unit)
// // {

// // }

// int main()
// {
//     float unit,n1=0,n2=0,n3=0,n4=0,n5=0,bill,a=41.33,b=0,c=0 ;
//     cout<<"enter unit "<<endl;
//     cin>>unit;
//     if(unit>n1)
//     {
//         n1=200;
//     }
//     else
//     {
//         n1=unit;
//     }

//     if(unit>400)
//     {
//         n2=200;
//     }
//     else
//     {
//         n2=unit-200;
//     }

//     if(unit>800)
//     {
//         n3=400;
//     }
//     else
//     {
//         n3=unit-400;
//     }


//     if(unit>1200)
//     {
//         n4=400;
//     }
//     else
//     {
//         n4=unit-800;
//     }


//     if(unit>3200)
//     {
//         n5=unit-1200;
//     }

//     //PUTTING ZERO IF VALUES ARE NEGETIVE
//     {
//         if(n2<0)
//         {
//             n2=0;
//         }
//         if(n3<0)
//         {
//             n3=0;
//         }
//         if(n4<0)
//         {
//             n4=0;
//         }
//         if(n5<0)
//         {
//             n5=0;
//         }
//     }
//     b= (n1*3)+(n2*4.5)+(n3*6.5)+(n4*7)+(n5*8);
//     cout<<"b= "<<n1<<"*3 + "<<n2<<"*4.5 +"<<n3<<"*6.5 +"<<n4<<"*7 +"<<n5<<"*8 ="<<bill;
//     c= ((n1*3)*.2069)+((n2*4.5)*.2069)+((n3*6.5)*.2069)+((n4*7)*.2069)+((n5*8)*20.69);
//     d=0;
//     e=(()*.08);
//     e=(()*.07);
//     g=8.56;
    
// }





#include<iostream>
using namespace std;

// int bill(int unit)
// {

// }

int main()
{
    float unit,n1=0,n2=0,n3=0,n4=0,n5=0,bill,a=41.33,b=0,c=0 ;
    cout<<"enter unit "<<endl;
    cin>>unit;
    if(unit>50)
    {
        n1=50;
    }
    else
    {
        n1=unit;
    

    if(unit>150)
    {
        n2=150;
    }
    else
    {
        n2=unit-150;
    }

    if(unit>300)
    {
        n3=300;
    }
    else
    {
        n3=unit-400;
    }


    if(unit>1200)
    {
        n4=400;
    }
    else
    {
        n4=unit-800;
    }


    if(unit>3200)
    {
        n5=unit-1200;
    }

    //PUTTING ZERO IF VALUES ARE NEGETIVE
    {
        if(n2<0)
        {
            n2=0;
        }
        if(n3<0)
        {
            n3=0;
        }
        if(n4<0)
        {
            n4=0;
        }
        if(n5<0)
        {
            n5=0;
        }
    }
    b= (n1*3)+(n2*4.5)+(n3*6.5)+(n4*7)+(n5*8);
    cout<<"b= "<<n1<<"*3 + "<<n2<<"*4.5 +"<<n3<<"*6.5 +"<<n4<<"*7 +"<<n5<<"*8 ="<<bill;
    // c= ((n1*3)*.2069)+((n2*4.5)*.2069)+((n3*6.5)*.2069)+((n4*7)*.2069)+((n5*8)*20.69);
    // d=0;
    // e=(()*.08);
    // e=(()*.07);
    // g=8.56;
    
}