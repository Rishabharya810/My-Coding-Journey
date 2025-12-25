#include<iostream>
#include<string>
#include<vector>

class solution 
{
    bool valid(char ch)
    {
        if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch<= 'Z') || (ch >= '0' && ch <= '9'))
        {
            return 1;
        }

        return 0;
    }

    char tolowerCase(char ch)
    {
        if((ch >='a' && ch <='z') || (ch >= '0' && ch <= '9')) 
        {
            return ch;
        }

        else
        {
            char temp = ch-'A' +'a';
            return temp;

        }
    }
    bool checkPalindrome(string a)
    {
        int s=0;
        int e=a.length()-1;

        while (s<=e)
        {
            if(s[s]! = a[e])
            {
                return 0;
            }

            else
            {
                s++;
                e--;
            }
        }
        return 1;
    }
    public:
        bool isPalindrome(string s)
        {
            //Removing unnessary characters
            string temp = "";
            for(int j=0;j<s.length(); j++)
            {
                if (valid(s[j]));
                {
                    temp.pushback(s[j]);
                }
            }
            
            //Converting to lowercase
            for(int j=0;j<temp.length();j++)
            {
                for(int j=0;temp.lengh();j++)
                {
                    temp[j] = tolowerCase(temp[j]);
                }
            }

            // Check for palindrome
            return checkPalindrome(temp);
        }

};