#include<iostream>
#include<vector>

using namespace std;

class Solution
{
    public:
        void reverseString(vector<char>& s)
        {
            int st=0;
            int e = s.size()-1;

            while(st<e)
            {
                swap(s[st++], s[e--]);

            }

        }

        void print(vector<char> s)
        {
            cout<<"[";
            for(int i=0; i<s.size(); i++)
            {
                cout<<"\" "<< s[i] <<" \"";
                if(i<(s.size()-1))
                {
                    cout<<",";
                }
            }
            cout<<"]";
            cout<< endl;
        }
};

int main()
{
    Solution s1;
    vector<char> s ;

    s.push_back('h');
    s.push_back('e');
    s.push_back('l');
    s.push_back('l');
    s.push_back('o');

    s1.print(s);
    s1.reverseString(s);
    cout<<"Reverse string is "<<endl;
    s1.print(s);
    cout<<"Quotes \" ";
    return 0;
}