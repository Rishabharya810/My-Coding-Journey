#include<bits/stdc++.h>
using namespace std;

//Syntax
//vector< data_type > name(size, value)

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);


    for(int i=0; i<v.size();i++)
    {
        cout<<v[i]<<endl;
    }// 1 2 3 

    //2D vector 
    //initialised a grid with -1
    // vector<vector<int>> grid(n,vector<int>(m,-1));

    vector<int>::iterator it;
    for(it = v.begin(); it != v.end(); it++)
    {
        cout<<*it<<endl;
    }// 1 2 3 

    for(auto element : v)
    {
        cout<<element<<endl;
    }//1 2 3 

    v.pop_back();// 1 2

    vector<int> v2(3,50);
    // 50 50 50

    swap(v,v2);
    for(auto element:v)
    {
        cout<<element<<endl;
    }

    for(auto element:v2)
    {
        cout<<element<<endl;
    }

    
    return 0;
}






// v.swap(v1);

// sort(v.begin(), v.end());

// int sum = accumlate(v.begin(),v.end(),0);
// cout<<sum;
