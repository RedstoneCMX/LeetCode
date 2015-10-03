#include<iostream>
#include<vector>
using namespace std;
/*这道题非常简单，数组是有序数组，只需要遍历一遍数组，判断当前值是否等于target或者大于target即可返回其位置值。如果都不满足，
说明target比nums中所有数都大，直接插入数组尾部，因为返回size。
*/
/*************************在leetcode上直接提交以下代码即可******************************/
class Solution 
{
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        int size = nums.size();
        if(size == 0)
        	return 0;
        for(int i = 0; i < size; i++)
        {
        	if(nums[i] == target || nums[i] > target)
        		return i;
        }

        return size;
    }
};
/*************************在leetcode上直接提交以上代码即可******************************/
int main()
{
	cout << "请输入整数个数: " << endl;
	int n;
	cin >> n;
	vector<int> nums;
	for(int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		nums.push_back(temp);
	}

	cout << "请输入target: " << endl;
	int target;
	cin >> target;
	Solution solu;
	int si = solu.searchInsert(nums,target);
	cout << si << endl;
	return 0;
}