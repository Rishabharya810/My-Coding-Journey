#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{   
    string abc = "abcdefghij klmnopqrst uvwxyz";
    string s1="abc";
    string s2="xyz";
    cout<<"With add \n"<<s1+s2<<endl;
    s1.append(s2);
    cout<<"With append \n"<<s1<<endl;
    
    cout<<"str before clear is - "<<abc<<endl;
    abc.clear();
    cout<<"str after clear is - "<<abc<<endl;

    if(s1.compare(s2)==0)
    {
        cout<<"String are equal"<<endl;
    }    
    else 
    {
        cout<<"Strings are not equal"<<endl;
    }           
    cout<<s2.compare(s1)<<endl;

    s1.clear();

    if(s1.empty())
    {
        cout<<"string is empty"<<endl;  
    }

    string value = "abcdefghij klmnopqrst uvwxyz";

 

    cout<<"str before erase is - "<<value<<endl;
    value.erase(11,10);
    cout<<"str after erase is - "<<value<<endl;

    cout<<value.find("xyz")<<endl;

    value.insert(11,"rishab arya");
    cout<<value<<endl;
    
    cout<<"value length is "<<value.length()<<endl;
    cout<<"value size is "<<value.size()<<endl;

    for(int i = 0; i<value.length() ; i++)
    {
       cout<<value[i]<<endl;
    }

    cout<<value.substr(11,11)<<endl;

    string s3 = "786";

    //  converting string 's3' to to int 


    int x=stoi(s3);
    cout<<x+2<<endl;

    cout<<to_string(x) + "2"<<endl ;
    sort(value.begin(),value.end());
    cout<<value<<endl;

    return 0;
}