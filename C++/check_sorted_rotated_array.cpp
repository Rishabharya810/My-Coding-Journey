#include<iostream>
#include<vector>

using namespace std;

class Solution
{
    public:
        bool check(vector<int>& nums)
        {
            int count = 0;
            int n = nums.size();
            
            for(int i=1;i<n;i++)
            {
                if(nums[i-1]>nums[i])
                count++;
            }
            if(nums[n-1]>nums[0])
            {
                count++;
            }
            return count<=1;
        }
};


int main()
{
    Solution s1;
    vector<int> v ;
    
    bool sol;

    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(1);
    v.push_back(7);

    cout<<"Array is Sorted and Rotated : ";
    
    sol = s1.check(v);
    
    if(sol==1)
    {
        cout<<"True";
    }
    else
    {
        cout<<"False";
    }
    //cout<<sol;
    return 0;
}