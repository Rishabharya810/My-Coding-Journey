#include<iostream> //given a 2 x n board and tiles of size 2x1, count the number of ways to tile the given board using these tiles
using namespace std;

int tilingWays(int n)
{
    if(n==0)
    {
        return 0;
    }
    if(n==1)
    {
        return 1;
    }
    return tilingWays(n-1) + tilingWays(n-2);
}

int main()
{
    cout<<tilingWays(4)<<endl;
    return 0;
}