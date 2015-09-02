#include<iostream>
using namespace std;
/*这道题其实很常见，一般的解法有两种，一种是递归求解，一种是动态规划。递归的求解方法很容易超时，而动态规划的解法效率高，典型的空间换时间。
*/
/*************************在leetcode上直接提交以下代码即可******************************/
class Solution 
{
	public:
    int climbStairs(int n) 
    {
        if(n == 1)
        	return 1;
        if(n == 2)
        	return 2;
    
        int *nums = new int[n+1];
        for(int i = 0; i < n+1; i++)
        	nums[i] = 0;
        nums[1] = 1;
        nums[2] = 2;
        for(int i = 3; i < n+1; i++)
        	nums[i] = nums[i-1]+nums[i-2];
        
        return nums[n];
    }
};
/*************************在leetcode上直接提交以上代码即可******************************/
int main()
{
	int n;
	cin >> n;
	Solution solu;
	int num = solu.climbStairs(n);
	cout << num << endl;
}