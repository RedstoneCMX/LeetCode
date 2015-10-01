#include<iostream>
#include<vector>
using namespace std;
/*这道题是一道动态规划的题，之前还没怎么做过动态规划的题。这题算比较简单，状态转移方程为:
maxV[i] = max(maxV[i-2]+nums[i], maxV[i-1]);
*/
/*************************在leetcode上直接提交以下代码即可******************************/
class Solution 
{
public:
    int rob(vector<int>& nums) 
    {
    	int n = nums.size();
    	if(n == 0)
    		return 0;
    	else if(n == 1)
    		return nums[0];

        vector<int> maxV(n,0);
        maxV[0] = nums[0];
        maxV[1] = max(nums[0], nums[1]);

        for(int i = 2; i < n; i++)
        {
        	maxV[i] = max(maxV[i-2]+nums[i], maxV[i-1]);
        }

        return maxV[n-1];

    }
};
/*************************在leetcode上直接提交以上代码即可******************************/
int main()
{
	cout << "请输入整数个数: " << endl;
	int n;
	cin >> n;
	vector<int> nums;
	cout << "请输入各整数: " << endl;
	for(int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		nums.push_back(temp);
	}

	Solution solu;
	int rob = solu.rob(nums);
	cout << rob << endl;
	return 0;
}