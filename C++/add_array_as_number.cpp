#include<iostream>
#include<vector>

using namespace std;

void print(vector<int> v)
{
    for(int i=0; i<v.size(); i++)
    {
        cout<< v[i] << " ";
    }
    cout<< endl;
}

vector<int> reverse(vector<int> v)
{
    int s = 0, e = v.size() - 1;
    
    while(s<=e)
    {
        swap(v[s], v[e]);
        s++;
        e--;
    }

    return v;

}

vector<int> findArraySum(vector<int> a, int n, vector <int> b, int m)
{
    int i= n-1;
    int j= m-1;
    vector<int> ans;
    int carry = 0;

    while(i>=0 && j>=0)
    {
        
        int val1 = a[i];
        int val2 = b[j];

        int sum = val1 + val2 + carry; 
        carry = sum/10;                 
        sum = sum%10;                  
        ans.push_back(sum);
        i--;
        j--;
    }

    // first case
    while (i>=0)
    {   
        
        int sum = a[i] + carry; 
        carry = sum/10;         
        sum = sum%10;           
        ans.push_back(sum);
        i--;
    }

    //second case
    while(j>=0)
    {
        
        int sum =b[j] + carry;          
        carry = sum/10;          
        int value = sum%10;         
        ans.push_back(value);            
        j--;
    }

    //Third case
    while(carry !=0)
    {
        
        int sum = carry;                  
        carry = sum/10;                       
        sum = sum%10;                       
        ans.push_back(sum);                 
    }

    return ans; 
}

int main()
{
    vector<int> a ;
    vector<int> b ;

    a.push_back(1);
    a.push_back(7);
    a.push_back(3);
    a.push_back(2);
    a.push_back(4);

    b.push_back(4);
    b.push_back(2);
    b.push_back(9);
    b.push_back(8);

    vector<int> v = findArraySum(a,5,b,4);
    vector<int> ans = reverse(v);
    cout<<"Sum of vector arrays is : "<< endl;
    print(ans);
    return 0;
}