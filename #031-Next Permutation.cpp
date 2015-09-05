#include<iostream>
#include<vector>
using namespace std;
/*这道题就是一道字典序排列的题
其实可以求解全排列问题，把升序的排列（当然，也可以实现为降序）作为当前排列开始，然后依次计算当前排列的下一个字典序排列。
对当前排列从后向前扫描，找到一对为升序的相邻元素，记为i和j（i < j）。如果不存在这样一对为升序的相邻元素，则所有排列均已找到，算法结束；
否则，重新对当前排列从后向前扫描，找到第一个大于i位置的元素k，交换i和k的值，然后对从j开始到结束的子序列反转，
则此时得到的新排列就为下一个字典序排列。这种方式实现得到的所有排列是按字典序有序的。
*/
/*************************在leetcode上直接提交以下代码即可******************************/ 
class Solution 
{
	public:
    void nextPermutation(vector<int>& nums) 
    {
        int size = nums.size();
        int i, j, k;
        for(i = size - 2; i >= 0; i--)
        {
        	if(nums[i+1] > nums[i])
        	{
        		j = i+1;
        		break;
        	}
        }

        if(i < 0)
        {
        	sort(nums.begin(),nums.end());
        	return ;
        }
        for(k = size - 1; k > i; k--)
        {
        	if(nums[k] > nums[i])
        		break;
        }
        swap(nums[i], nums[k]);
        reverse(nums.begin() + j, nums.end());
        return ;
    }
};
/*************************在leetcode上直接提交以上代码即可******************************/
int main()
{
	int n;
	cin >> n;
	vector<int> nums;
	for(int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		nums.push_back(num);
	}

	Solution solu;
	solu.nextPermutation(nums);

	for(int i = 0; i < n; i++)
		cout << nums[i] << endl;
}