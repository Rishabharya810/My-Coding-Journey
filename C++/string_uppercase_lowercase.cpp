#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
    string str = " assdfsdfasd";

    cout<<'a'-'A'<<endl;

    // Convert uppercase
    for(int i=0;i<str.size();i++)
    {
        if(str[i]>='a'&&str[i]<='z')
        {
            str[i] -= 32;
        }
    }
    cout<<str<<endl;
    
    //Convert lowercase
    for(int i=0;i<str.size();i++)
    {
        if(str[i]>='A'&&str[i]<='Z')
        {
            str[i] += 32;
        }
    }

    cout<<str;

    transform(str.begin(),str.end(),str.begin(),::toupper);

    cout<<str<<endl;

    transform(str.begin(),str.end(),str.begin(),::toupper);

    
    cout<<str<<endl;


    string s5 = "34566422548990";

    sort(s5.begin(), s5.end(), greater<int>());

    cout<<s5<<endl;

    return 0;
}