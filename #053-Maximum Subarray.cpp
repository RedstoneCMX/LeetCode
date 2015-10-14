#include<iostream>
#include<vector>
using namespace std;
/*这道题属于动态规划的题。
利用动态规划的思想完成，时间复杂度为O(n)。已知0,..,k的最大可能和以后，0,...k+1的最大可能和为：
1）若sum[k]>=0,sum[k+1]=sum[k]+A[k+1]。
2）若sum[k]<0,sum[k+1]=A[k+1]。
这里求得最后的sum[n-1]并不一定就是最大的和，只是最大可能的和，需要求解出sum数组中最大的数才为nums中的最大sub和。
*/
/*************************在leetcode上直接提交以下代码即可******************************/
class Solution 
{
public:
    int maxSubArray(vector<int>& nums) 
    {
        int size = nums.size();
        int maxsubsum = INT_MIN;
        int subsum = INT_MIN;
        for(int i = 0; i < size; i++)
        {
        	if(subsum < 0)
        		subsum = nums[i];
        	else
        		subsum = subsum + nums[i];
        	if(subsum > maxsubsum)
        		maxsubsum = subsum;
        }

        return maxsubsum;
    }
};
/*************************在leetcode上直接提交以上代码即可******************************/
int main()
{
	int n;
	cout << "请输入整数个数: " << endl;
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
	int maxsubsum = solu.maxSubArray(nums);
	cout << maxsubsum << endl;
	return 0;
}